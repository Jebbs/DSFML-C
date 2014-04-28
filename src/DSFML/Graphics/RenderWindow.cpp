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
#include <DSFML/Graphics/RenderWindow.h>
#include <DSFML/Graphics/RenderWindowStruct.h>
#include <DSFML/Graphics/ImageStruct.h>
#include <DSFML/Graphics/CreateRenderStates.hpp>
#include <DSFML/ConvertEvent.h>



sfRenderWindow* sfRenderWindow_create(DUint width, DUint height, DUint bitsPerPixel, const char* title, DInt style, DUint depthBits, DUint stencilBits, DUint antialiasingLevel, DUint majorVersion, DUint minorVersion)
{
    // Convert video mode
    sf::VideoMode videoMode(width, height, bitsPerPixel);

    // Create context settings
    sf::ContextSettings params;
    
    params.depthBits         = depthBits;
    params.stencilBits       = stencilBits;
    params.antialiasingLevel = antialiasingLevel;
    params.majorVersion      = majorVersion;
    params.minorVersion      = minorVersion;
    

    // Create the window
    sfRenderWindow* renderWindow = new sfRenderWindow;
    renderWindow->This.create(videoMode, title, style, params);
    renderWindow->DefaultView.This = renderWindow->This.getDefaultView();
    renderWindow->CurrentView.This = renderWindow->This.getView();

    return renderWindow;
}


sfRenderWindow* sfRenderWindow_createUnicode(DUint width, DUint height, DUint bitsPerPixel, const DUint* title, DInt style, DUint depthBits, DUint stencilBits, DUint antialiasingLevel, DUint majorVersion, DUint minorVersion)
{
    // Convert video mode
    sf::VideoMode videoMode(width, height, bitsPerPixel);

    // Convert context settings
    sf::ContextSettings params;
    
    params.depthBits         = depthBits;
    params.stencilBits       = stencilBits;
    params.antialiasingLevel = antialiasingLevel;
    params.majorVersion      = majorVersion;
    params.minorVersion      = minorVersion;
    

    // Create the window
    sfRenderWindow* renderWindow = new sfRenderWindow;
    renderWindow->This.create(videoMode, title, style, params);
    renderWindow->DefaultView.This = renderWindow->This.getDefaultView();
    renderWindow->CurrentView.This = renderWindow->This.getView();

    return renderWindow;
}



sfRenderWindow* sfRenderWindow_createFromHandle(sfWindowHandle handle, DUint depthBits, DUint stencilBits, DUint antialiasingLevel, DUint majorVersion, DUint minorVersion)
{
    // Convert context settings
    sf::ContextSettings params;
    
    params.depthBits         = depthBits;
    params.stencilBits       = stencilBits;
    params.antialiasingLevel = antialiasingLevel;
    params.majorVersion      = majorVersion;
    params.minorVersion      = minorVersion;
    

    // Create the window
    sfRenderWindow* renderWindow = new sfRenderWindow;
    renderWindow->This.create(handle, params);
    renderWindow->DefaultView.This = renderWindow->This.getDefaultView();
    renderWindow->CurrentView.This = renderWindow->This.getView();

    return renderWindow;
}



void sfRenderWindow_destroy(sfRenderWindow* renderWindow)
{
    delete renderWindow;
}



void sfRenderWindow_close(sfRenderWindow* renderWindow)
{
    renderWindow->This.close();
}



DBool sfRenderWindow_isOpen(const sfRenderWindow* renderWindow)
{
    return renderWindow->This.isOpen()?DTrue: DFalse;
}



void sfRenderWindow_getSettings(const sfRenderWindow* renderWindow, DUint* depthBits, DUint* stencilBits, DUint* antialiasingLevel, DUint* majorVersion, DUint* minorVersion)
{
    const sf::ContextSettings& params = renderWindow->This.getSettings();
    *depthBits         = params.depthBits;
    *stencilBits       = params.stencilBits;
    *antialiasingLevel = params.antialiasingLevel;
    *majorVersion      = params.majorVersion;
    *minorVersion      = params.minorVersion;

}



DBool sfRenderWindow_pollEvent(sfRenderWindow* renderWindow, DEvent* event)
{

    // Get the event
    sf::Event SFMLEvent;
    DBool ret = renderWindow->This.pollEvent(SFMLEvent);

    // No event, return
    if (!ret)
        return DFalse;

    // Convert the sf::Event event to a DSFML Event
    convertEvent(SFMLEvent, event);

    return DTrue;
}



DBool sfRenderWindow_waitEvent(sfRenderWindow* renderWindow, DEvent* event)
{

    // Get the event
    sf::Event SFMLEvent;
    DBool ret = renderWindow->This.waitEvent(SFMLEvent);

    // Error, return
    if (!ret)
        return DFalse;

    // Convert the sf::Event event to a sfEvent
    convertEvent(SFMLEvent, event);

    return DTrue;
}



void sfRenderWindow_getPosition(const sfRenderWindow* renderWindow, DInt* x, DInt* y)
{

    sf::Vector2i sfmlPos = renderWindow->This.getPosition();
    *x = sfmlPos.x;
    *y = sfmlPos.y;

}



void sfRenderWindow_setPosition(sfRenderWindow* renderWindow, DInt x, DInt y)
{
    renderWindow->This.setPosition(sf::Vector2i(x, y));
}



void sfRenderWindow_getSize(const sfRenderWindow* renderWindow, DUint* width, DUint* height)
{
    sf::Vector2u sfmlSize = renderWindow->This.getSize();
    *width = sfmlSize.x;
    *height = sfmlSize.y;

}



void sfRenderWindow_setSize(sfRenderWindow* renderWindow, DInt width, DInt height)
{
    renderWindow->This.setSize(sf::Vector2u(width, height));
}



void sfRenderWindow_setTitle(sfRenderWindow* renderWindow, const char* title)
{
    renderWindow->This.setTitle(title);
}



void sfRenderWindow_setUnicodeTitle(sfRenderWindow* renderWindow, const DUint* title)
{
    renderWindow->This.setTitle(title);
}



void sfRenderWindow_setIcon(sfRenderWindow* renderWindow, DUint width, DUint height, const DUbyte* pixels)
{
    renderWindow->This.setIcon(width, height, pixels);
}



void sfRenderWindow_setVisible(sfRenderWindow* renderWindow, DBool visible)
{
    renderWindow->This.setVisible(visible == DTrue);
}



void sfRenderWindow_setMouseCursorVisible(sfRenderWindow* renderWindow, DBool visible)
{
   renderWindow->This.setMouseCursorVisible(visible == DTrue);
}



void sfRenderWindow_setVerticalSyncEnabled(sfRenderWindow* renderWindow, DBool enabled)
{
    renderWindow->This.setVerticalSyncEnabled(enabled == DTrue);
}



void sfRenderWindow_setKeyRepeatEnabled(sfRenderWindow* renderWindow, DBool enabled)
{
    renderWindow->This.setKeyRepeatEnabled(enabled == DTrue);
}



DBool sfRenderWindow_setActive(sfRenderWindow* renderWindow, DBool active)
{
    return renderWindow->This.setActive(active == DTrue)?DTrue: DFalse;
}



void sfRenderWindow_display(sfRenderWindow* renderWindow)
{
    renderWindow->This.display();
}



void sfRenderWindow_setFramerateLimit(sfRenderWindow* renderWindow, DUint limit)
{
    renderWindow->This.setFramerateLimit(limit);
}



void sfRenderWindow_setJoystickThreshold(sfRenderWindow* renderWindow, float threshold)
{
    renderWindow->This.setJoystickThreshold(threshold);
}



sfWindowHandle sfRenderWindow_getSystemHandle(const sfRenderWindow* renderWindow)
{
    return (sfWindowHandle)renderWindow->This.getSystemHandle();
}



void sfRenderWindow_clear(sfRenderWindow* renderWindow, DUbyte r, DUbyte g, DUbyte b, DUbyte a)
{
    sf::Color SFMLColor(r, g, b, a);

    renderWindow->This.clear(SFMLColor);
}



void sfRenderWindow_setView(sfRenderWindow* renderWindow, const sfView* view)
{
    renderWindow->This.setView(view->This);
    renderWindow->CurrentView.This = view->This;
}



sfView* sfRenderWindow_getView(const sfRenderWindow* renderWindow)
{
    //Safe because this is only used when user calls RenderWindow.getView, which returns a
    //const(View)
    return const_cast<sfView*>(&renderWindow->CurrentView);
}



sfView* sfRenderWindow_getDefaultView(const sfRenderWindow* renderWindow)
{
    //Safe because this is only used when user calls RenderWindow.getDefaultView, which returns a
    //const(View)
    return const_cast<sfView*>(&renderWindow->DefaultView);
}



void sfRenderWindow_getViewport(const sfRenderWindow* renderWindow, const sfView* view, DInt* left, DInt* top, DInt* width, DInt* height)
{
    

    sf::IntRect SFMLrect = renderWindow->This.getViewport(view->This);
    *left   = SFMLrect.left;
    *top    = SFMLrect.top;
    *width  = SFMLrect.width;
    *height = SFMLrect.height;

}



void sfRenderWindow_mapPixelToCoords(const sfRenderWindow* renderWindow, DInt xIn, DInt yIn, float* xOut, float* yOut, const sfView* targetView)
{
    

    sf::Vector2f sfmlPoint;
    if (targetView)
        sfmlPoint = renderWindow->This.mapPixelToCoords(sf::Vector2i(xIn, yIn), targetView->This);
    else
        sfmlPoint = renderWindow->This.mapPixelToCoords(sf::Vector2i(xIn, yIn));

    *xOut = sfmlPoint.x;
    *yOut = sfmlPoint.y;

}



void sfRenderWindow_mapCoordsToPixel(const sfRenderWindow* renderWindow, float xIn, float yIn, DInt* xOut, DInt* yOut, const sfView* targetView)
{

    sf::Vector2i sfmlPoint;
    if (targetView)
        sfmlPoint = renderWindow->This.mapCoordsToPixel(sf::Vector2f(xIn, yIn), targetView->This);
    else
        sfmlPoint = renderWindow->This.mapCoordsToPixel(sf::Vector2f(xIn, yIn));

    *xOut = sfmlPoint.x;
    *yOut = sfmlPoint.y;
}



void sfRenderWindow_drawPrimitives(sfRenderWindow* renderWindow,
                                                      const void* vertices, DUint vertexCount, DInt type, DInt blendMode,const float* transform, const sfTexture* texture, const sfShader* shader)
{
    renderWindow->This.draw(static_cast<const sf::Vertex*>(vertices), vertexCount, static_cast<sf::PrimitiveType>(type), createRenderStates(blendMode, transform, texture, shader));
}



void sfRenderWindow_pushGLStates(sfRenderWindow* renderWindow)
{
    renderWindow->This.pushGLStates();
}



void sfRenderWindow_popGLStates(sfRenderWindow* renderWindow)
{
    renderWindow->This.popGLStates();
}



void sfRenderWindow_resetGLStates(sfRenderWindow* renderWindow)
{
    renderWindow->This.resetGLStates();
}



sfImage* sfRenderWindow_capture(const sfRenderWindow* renderWindow)
{

    sfImage* image = new sfImage;
    image->This = renderWindow->This.capture();

    return image;
}



void sfMouse_getPositionRenderWindow(const sfRenderWindow* relativeTo, DInt* x, DInt* y)
{
    sf::Vector2i sfmlPos;
   
   //Will always be called with a Window
    sfmlPos = sf::Mouse::getPosition(relativeTo->This);
    
    *x = sfmlPos.x;
    *y = sfmlPos.y;

}



void sfMouse_setPositionRenderWindow(DInt x, DInt y, const sfRenderWindow* relativeTo)
{
    //Will always be called with a Window
    sf::Mouse::setPosition(sf::Vector2i(x, y), relativeTo->This);
    
}
