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
#include <SFML/Graphics/RenderTexture.h>
#include <SFML/Graphics/RenderTextureStruct.h>
#include <SFML/Graphics/CreateRenderStates.hpp>
#include <SFML/Internal.h>


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
    delete renderTexture->Target;
    delete renderTexture;
}


void sfRenderTexture_getSize(const sfRenderTexture* renderTexture, DUint* x, DUint* y)
{
    //sfVector2u size = {0, 0};
    //CSFML_CHECK_RETURN(renderTexture, size);

    sf::Vector2u sfmlSize = renderTexture->This.getSize();
    *x = sfmlSize.x;
    *y = sfmlSize.y;

}


DBool sfRenderTexture_setActive(sfRenderTexture* renderTexture, DBool active)
{
    CSFML_CALL_RETURN(renderTexture, setActive(active == DTrue), DFalse);
}


void sfRenderTexture_display(sfRenderTexture* renderTexture)
{
    CSFML_CALL(renderTexture, display());
}


void sfRenderTexture_clear(sfRenderTexture* renderTexture, DUbyte r, DUbyte g, DUbyte b, DUbyte a)
{
    sf::Color SFMLColor(r, g, b, a);

    CSFML_CALL(renderTexture, clear(SFMLColor));
}


void sfRenderTexture_setView(sfRenderTexture* renderTexture, const sfView* view)
{
    CSFML_CHECK(view);
    CSFML_CALL(renderTexture, setView(view->This));
    renderTexture->CurrentView.This = view->This;
}


sfView* sfRenderTexture_getView(const sfRenderTexture* renderTexture)
{
    CSFML_CHECK_RETURN(renderTexture, NULL);

    //Safe because the pointer will only be used in a const instance
    return const_cast<sfView*>(&renderTexture->CurrentView);
}


sfView* sfRenderTexture_getDefaultView(const sfRenderTexture* renderTexture)
{
    CSFML_CHECK_RETURN(renderTexture, NULL);

    //Safe because the pointer will only be used in a const instance
    return const_cast<sfView*>(&renderTexture->DefaultView);
}


void sfRenderTexture_getViewport(const sfRenderTexture* renderTexture, const sfView* view, DInt* rectLeft, DInt* rectTop, DInt* rectWidth, DInt* rectHeight)
{
    //sfIntRect rect = {0, 0, 0, 0};
   // CSFML_CHECK_RETURN(view, rect);
    //CSFML_CHECK_RETURN(renderTexture, rect);

    sf::IntRect SFMLrect = renderTexture->This.getViewport(view->This);
    *rectLeft   = SFMLrect.left;
    *rectTop    = SFMLrect.top;
    *rectWidth  = SFMLrect.width;
    *rectHeight = SFMLrect.height;

}


void sfRenderTexture_mapPixelToCoords(const sfRenderTexture* renderTexture, DInt xIn, DInt yIn, float* xOut, float* yOut, const sfView* targetView)
{
   // sfVector2f result = {0, 0};
    //CSFML_CHECK_RETURN(renderTexture, result);

    sf::Vector2f sfmlPoint;
    if (targetView)
        sfmlPoint = renderTexture->This.mapPixelToCoords(sf::Vector2i(xIn, yIn), targetView->This);
    else
        sfmlPoint = renderTexture->This.mapPixelToCoords(sf::Vector2i(xIn, yIn));

    *xOut = sfmlPoint.x;
    *xOut = sfmlPoint.y;

   // return result;
}


void sfRenderTexture_mapCoordsToPixel(const sfRenderTexture* renderTexture, float xIn, float yIn, DInt* xOut, DInt* yOut, const sfView* targetView)
{
    //sfVector2i result = {0, 0};
    //CSFML_CHECK_RETURN(renderTexture, result);

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
    CSFML_CALL(renderTexture, draw(reinterpret_cast<const sf::Vertex*>(vertices), vertexCount, static_cast<sf::PrimitiveType>(type), createRenderStates(blendMode, transform, texture, shader)));
}


void sfRenderTexture_pushGLStates(sfRenderTexture* renderTexture)
{
    CSFML_CALL(renderTexture, pushGLStates());
}


void sfRenderTexture_popGLStates(sfRenderTexture* renderTexture)
{
    CSFML_CALL(renderTexture, popGLStates());
}


void sfRenderTexture_resetGLStates(sfRenderTexture* renderTexture)
{
    CSFML_CALL(renderTexture, resetGLStates());
}


sfTexture* sfRenderTexture_getTexture(const sfRenderTexture* renderTexture)
{
    CSFML_CHECK_RETURN(renderTexture, NULL);

    //Safe because the pointer will only be used in a const instance
    return const_cast<sfTexture*>(renderTexture->Target);
}


void sfRenderTexture_setSmooth(sfRenderTexture* renderTexture, DBool smooth)
{
    CSFML_CALL(renderTexture, setSmooth(smooth == DTrue));
}


DBool sfRenderTexture_isSmooth(const sfRenderTexture* renderTexture)
{
    CSFML_CALL_RETURN(renderTexture, isSmooth(), DFalse);
}
