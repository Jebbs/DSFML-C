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
#include <SFML/Graphics/View.h>
#include <SFML/Graphics/ViewStruct.h>
#include <SFML/Internal.h>


sfView* sfView_create(void)
{
    return new sfView;
}



sfView* sfView_createFromRect(float left, float top, float width, float height)
{
    sfView* view = new sfView;
    sfView_reset(view,left, top, width, height);

    return view;
}



sfView* sfView_copy(const sfView* view)
{
    CSFML_CHECK_RETURN(view, NULL);

    return new sfView(*view);
}



void sfView_destroy(sfView* view)
{
    delete view;
}



void sfView_setCenter(sfView* view, float centerX, float centerY)
{
    CSFML_CALL(view, setCenter(centerX, centerY));
}



void sfView_setSize(sfView* view, float sizeX, float sizeY)
{
    CSFML_CALL(view, setSize(sizeX, sizeY));
}



void sfView_setRotation(sfView* view, float angle)
{
    CSFML_CALL(view, setRotation(angle));
}



void sfView_setViewport(sfView* view, float left, float top, float width, float height)
{
    CSFML_CALL(view, setViewport(sf::FloatRect(left, top, width, height)));
}



void sfView_reset(sfView* view, float left, float top, float width, float height)
{
    CSFML_CALL(view, reset(sf::FloatRect(left, top, width, height)));
}



void sfView_getCenter(const sfView* view, float* x, float* y)
{
    //sfVector2f center = {0, 0};
    //CSFML_CHECK_RETURN(view, center);

    sf::Vector2f sfmlCenter = view->This.getCenter();
    *x = sfmlCenter.x;
    *y = sfmlCenter.y;
}



void sfView_getSize(const sfView* view, float* x, float* y)
{
    //sfVector2f size = {0, 0};
    //CSFML_CHECK_RETURN(view, size);

    sf::Vector2f sfmlSize = view->This.getSize();
    *x = sfmlSize.x;
    *y = sfmlSize.y;

}



float sfView_getRotation(const sfView* view)
{
    CSFML_CALL_RETURN(view, getRotation(), 0.f);
}



void sfView_getViewport(const sfView* view, float* left, float* top, float* width, float* height)
{
    //sfFloatRect rect = {0, 0, 0, 0};
    //CSFML_CHECK_RETURN(view, rect);

    sf::FloatRect SFMLRect = view->This.getViewport();
    *left   = SFMLRect.left;
    *top    = SFMLRect.top;
    *width  = SFMLRect.width;
    *height = SFMLRect.height;

}



void sfView_move(sfView* view, float offsetX, float offsetY)
{
    CSFML_CALL(view, move(offsetX, offsetY));
}



void sfView_rotate(sfView* view, float angle)
{
    CSFML_CALL(view, rotate(angle));
}



void sfView_zoom(sfView* view, float factor)
{
    CSFML_CALL(view, zoom(factor));
}
