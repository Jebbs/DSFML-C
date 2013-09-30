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
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/RenderWindowStruct.h>
#include <SFML/Graphics/ImageStruct.h>
//#include <SFML/Graphics/TextStruct.h>

#include <SFML/Graphics/CreateRenderStates.hpp>
#include <SFML/Internal.h>
#include <SFML/ConvertEvent.h>

#include <iostream>



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
    CSFML_CALL(renderWindow, close());
}



DBool sfRenderWindow_isOpen(const sfRenderWindow* renderWindow)
{
    CSFML_CALL_RETURN(renderWindow, isOpen(), DFalse);
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
    CSFML_CHECK_RETURN(renderWindow, DFalse);
    CSFML_CHECK_RETURN(event,        DFalse);

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
    CSFML_CHECK_RETURN(renderWindow, DFalse);
    CSFML_CHECK_RETURN(event,        DFalse);

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
    CSFML_CALL(renderWindow, setPosition(sf::Vector2i(x, y)));
}



void sfRenderWindow_getSize(const sfRenderWindow* renderWindow, DUint* width, DUint* height)
{


    sf::Vector2u sfmlSize = renderWindow->This.getSize();
    *width = sfmlSize.x;
    *height = sfmlSize.y;

}



void sfRenderWindow_setSize(sfRenderWindow* renderWindow, DInt width, DInt height)
{
    CSFML_CALL(renderWindow, setSize(sf::Vector2u(width, height)));
}



void sfRenderWindow_setTitle(sfRenderWindow* renderWindow, const char* title)
{
    CSFML_CALL(renderWindow, setTitle(title));
}



void sfRenderWindow_setUnicodeTitle(sfRenderWindow* renderWindow, const DUint* title)
{
    CSFML_CALL(renderWindow, setTitle(title));
}



void sfRenderWindow_setIcon(sfRenderWindow* renderWindow, DUint width, DUint height, const DUbyte* pixels)
{
    CSFML_CALL(renderWindow, setIcon(width, height, pixels));
}



void sfRenderWindow_setVisible(sfRenderWindow* renderWindow, DBool visible)
{
    CSFML_CALL(renderWindow, setVisible(visible == DTrue));
}



void sfRenderWindow_setMouseCursorVisible(sfRenderWindow* renderWindow, DBool visible)
{
    CSFML_CALL(renderWindow, setMouseCursorVisible(visible == DTrue));
}



void sfRenderWindow_setVerticalSyncEnabled(sfRenderWindow* renderWindow, DBool enabled)
{
    CSFML_CALL(renderWindow, setVerticalSyncEnabled(enabled == DTrue));
}



void sfRenderWindow_setKeyRepeatEnabled(sfRenderWindow* renderWindow, DBool enabled)
{
    CSFML_CALL(renderWindow, setKeyRepeatEnabled(enabled == DTrue));
}



DBool sfRenderWindow_setActive(sfRenderWindow* renderWindow, DBool active)
{
    CSFML_CALL_RETURN(renderWindow, setActive(active == DTrue), DFalse);
}



void sfRenderWindow_display(sfRenderWindow* renderWindow)
{
    CSFML_CALL(renderWindow, display());
}



void sfRenderWindow_setFramerateLimit(sfRenderWindow* renderWindow, DUint limit)
{
    CSFML_CALL(renderWindow, setFramerateLimit(limit));
}



void sfRenderWindow_setJoystickThreshold(sfRenderWindow* renderWindow, float threshold)
{
    CSFML_CALL(renderWindow, setJoystickThreshold(threshold));
}



sfWindowHandle sfRenderWindow_getSystemHandle(const sfRenderWindow* renderWindow)
{
    CSFML_CHECK_RETURN(renderWindow, 0);

    return (sfWindowHandle)renderWindow->This.getSystemHandle();
}



void sfRenderWindow_clear(sfRenderWindow* renderWindow, DUbyte r, DUbyte g, DUbyte b, DUbyte a)
{
    sf::Color SFMLColor(r, g, b, a);

    CSFML_CALL(renderWindow, clear(SFMLColor));
}



void sfRenderWindow_setView(sfRenderWindow* renderWindow, const sfView* view)
{
    CSFML_CHECK(view);
    CSFML_CALL(renderWindow, setView(view->This));
    renderWindow->CurrentView.This = view->This;
}



sfView* sfRenderWindow_getView(const sfRenderWindow* renderWindow)
{
    CSFML_CHECK_RETURN(renderWindow, NULL);

    //Safe because this is only used when user calls RenderWindow.getView, which returns a
    //const(View), and D can't cast away the const because it doesn't know the size.
    return const_cast<sfView*>(&renderWindow->CurrentView);
}



sfView* sfRenderWindow_getDefaultView(const sfRenderWindow* renderWindow)
{
    CSFML_CHECK_RETURN(renderWindow, NULL);
    //Safe because this is only used when user calls RenderWindow.getDefaultView, which returns a
    //const(View), and D can't cast away the const because it doesn't know the size.
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



//void sfRenderWindow_drawText(sfRenderWindow* renderWindow, const sfText* object, DInt blendMode,const float* transform, const sfTexture* texture, const sfShader* shader)
//{
    //CSFML_CHECK(object);
    //CSFML_CALL(renderWindow, draw(object->This, createRenderStates(blendMode, transform, texture, shader)));
//}



void sfRenderWindow_drawPrimitives(sfRenderWindow* renderWindow,
                                                      const void* vertices, DUint vertexCount, DInt type, DInt blendMode,const float* transform, const sfTexture* texture, const sfShader* shader)
{
    CSFML_CALL(renderWindow, draw(static_cast<const sf::Vertex*>(vertices), vertexCount, static_cast<sf::PrimitiveType>(type), createRenderStates(blendMode, transform, texture, shader)));
}



void sfRenderWindow_pushGLStates(sfRenderWindow* renderWindow)
{
    CSFML_CALL(renderWindow, pushGLStates());
}



void sfRenderWindow_popGLStates(sfRenderWindow* renderWindow)
{
    CSFML_CALL(renderWindow, popGLStates());
}



void sfRenderWindow_resetGLStates(sfRenderWindow* renderWindow)
{
    CSFML_CALL(renderWindow, resetGLStates());
}



sfImage* sfRenderWindow_capture(const sfRenderWindow* renderWindow)
{
    CSFML_CHECK_RETURN(renderWindow, NULL);

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
