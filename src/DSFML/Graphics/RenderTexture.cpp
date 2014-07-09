/*
DSFML - The Simple and Fast Multimedia Library for D

Copyright (c) <2013> <Jeremy DeHaan>

This software is provided 'as-is', without any express or implied warranty.
In no event will the authors be held liable for any damages arising from the use of this software.

Permission is granted to anyone to use this software for any purpose, including commercial applications,
and to alter it and redistribute it freely, subject to the following restrictions:

1. The origin of this software must not be misrepresented; you must not claim that you wrote the original software.
If you use this software in a product, an acknowledgment in the product documentation would be appreciated but is not required.

2. Altered source versions must be plainly marked as such, and must not be misrepresented as being the original software.

3. This notice may not be removed or altered from any source distribution


***All code is based on code written by Laurent Gomila***


External Libraries Used:

SFML - The Simple and Fast Multimedia Library
Copyright (C) 2007-2013 Laurent Gomila (laurent.gom@gmail.com)

All Libraries used by SFML - For a full list see http://www.sfml-dev.org/license.php
*/

// Headers
#include <DSFML/Graphics/RenderTexture.h>
#include <DSFML/Graphics/RenderTextureStruct.h>
#include <DSFML/Graphics/CreateRenderStates.hpp>


sfRenderTexture* sfRenderTexture_create(DUint width, DUint height, DBool depthBuffer)
{
    sfRenderTexture* renderTexture = new sfRenderTexture;
    renderTexture->This.create(width, height, depthBuffer == DTrue);
    renderTexture->Target = new sfTexture(const_cast<sf::Texture*>(&renderTexture->This.getTexture()));
    renderTexture->DefaultView.This = renderTexture->This.getDefaultView();
    renderTexture->CurrentView.This = renderTexture->This.getView();

    return renderTexture;
}


void sfRenderTexture_destroy(sfRenderTexture* renderTexture)
{
    delete renderTexture;
}


void sfRenderTexture_getSize(const sfRenderTexture* renderTexture, DUint* x, DUint* y)
{
    sf::Vector2u sfmlSize = renderTexture->This.getSize();
    *x = sfmlSize.x;
    *y = sfmlSize.y;
}


DBool sfRenderTexture_setActive(sfRenderTexture* renderTexture, DBool active)
{
    return renderTexture->This.setActive(active == DTrue)?DTrue: DFalse;
}


void sfRenderTexture_display(sfRenderTexture* renderTexture)
{
    renderTexture->This.display();
}


void sfRenderTexture_clear(sfRenderTexture* renderTexture, DUbyte r, DUbyte g, DUbyte b, DUbyte a)
{
    sf::Color SFMLColor(r, g, b, a);

    renderTexture->This.clear(SFMLColor);
}


void sfRenderTexture_setView(sfRenderTexture* renderTexture, const sfView* view)
{
    renderTexture->This.setView(view->This);
    renderTexture->CurrentView.This = view->This;
}


sfView* sfRenderTexture_getView(const sfRenderTexture* renderTexture)
{
    //Safe because the pointer will only be used in a const instance
    return const_cast<sfView*>(&renderTexture->CurrentView);
}


sfView* sfRenderTexture_getDefaultView(const sfRenderTexture* renderTexture)
{
    //Safe because the pointer will only be used in a const instance
    return const_cast<sfView*>(&renderTexture->DefaultView);
}


void sfRenderTexture_getViewport(const sfRenderTexture* renderTexture, const sfView* view, DInt* rectLeft, DInt* rectTop, DInt* rectWidth, DInt* rectHeight)
{
    sf::IntRect SFMLrect = renderTexture->This.getViewport(view->This);
    *rectLeft   = SFMLrect.left;
    *rectTop    = SFMLrect.top;
    *rectWidth  = SFMLrect.width;
    *rectHeight = SFMLrect.height;

}


void sfRenderTexture_mapPixelToCoords(const sfRenderTexture* renderTexture, DInt xIn, DInt yIn, float* xOut, float* yOut, const sfView* targetView)
{
    sf::Vector2f sfmlPoint;
    if (targetView)
        sfmlPoint = renderTexture->This.mapPixelToCoords(sf::Vector2i(xIn, yIn), targetView->This);
    else
        sfmlPoint = renderTexture->This.mapPixelToCoords(sf::Vector2i(xIn, yIn));

    *xOut = sfmlPoint.x;
    *xOut = sfmlPoint.y;

}


void sfRenderTexture_mapCoordsToPixel(const sfRenderTexture* renderTexture, float xIn, float yIn, DInt* xOut, DInt* yOut, const sfView* targetView)
{
    sf::Vector2i sfmlPoint;
    if (targetView)
        sfmlPoint = renderTexture->This.mapCoordsToPixel(sf::Vector2f(xIn, yIn), targetView->This);
    else
        sfmlPoint = renderTexture->This.mapCoordsToPixel(sf::Vector2f(xIn, yIn));

    *xOut = sfmlPoint.x;
    *yOut = sfmlPoint.y;

}



void sfRenderTexture_drawPrimitives(sfRenderTexture* renderTexture,
                                    const void* vertices, DUint vertexCount,
                                    DInt type, DInt blendMode,const float* transform, const sfTexture* texture, const sfShader* shader)
{
    renderTexture->This.draw(reinterpret_cast<const sf::Vertex*>(vertices), vertexCount, static_cast<sf::PrimitiveType>(type), createRenderStates(blendMode, transform, texture, shader));
}


void sfRenderTexture_pushGLStates(sfRenderTexture* renderTexture)
{
    renderTexture->This.pushGLStates();
}


void sfRenderTexture_popGLStates(sfRenderTexture* renderTexture)
{
    renderTexture->This.popGLStates();
}


void sfRenderTexture_resetGLStates(sfRenderTexture* renderTexture)
{
    renderTexture->This.resetGLStates();
}


sfTexture* sfRenderTexture_getTexture(const sfRenderTexture* renderTexture)
{
    //Safe because the pointer will only be used in a const instance
    return const_cast<sfTexture*>(renderTexture->Target);
}


void sfRenderTexture_setSmooth(sfRenderTexture* renderTexture, DBool smooth)
{
    renderTexture->This.setSmooth(smooth == DTrue);
}


DBool sfRenderTexture_isSmooth(const sfRenderTexture* renderTexture)
{
    return renderTexture->This.isSmooth()?DTrue: DFalse;
}
