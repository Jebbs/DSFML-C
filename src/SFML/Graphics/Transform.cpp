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
#include <SFML/Graphics/Transform.h>
#include <SFML/Graphics/Transform.hpp>
#include <SFML/Graphics/CreateTransform.hpp>
#include <SFML/Internal.h>
#include <cstring>








void sfTransform_getMatrix(const float* transform, float* matrix)
{
    CSFML_CHECK(transform);

    sf::Transform createed = createTransform(transform);
    if (matrix)
        std::memcpy(matrix, createed.getMatrix(), 16 * sizeof(float));
}


void sfTransform_getInverse(const float* transform, float* inverse)
{
    //CSFML_CHECK_RETURN(transform, sfTransform_Identity);

    createTransform(createTransform(transform).getInverse(), inverse);


}


void sfTransform_transformPoint(const float* transform, float xIn, float yIn, float* xOut, float* yOut)
{
    //sfVector2f p = {0, 0};
    //CSFML_CHECK_RETURN(transform, p);

    sf::Vector2f sfmlPoint = createTransform(transform).transformPoint(xIn, yIn);

    *xOut = sfmlPoint.x;
    *yOut = sfmlPoint.y;

}


void sfTransform_transformRect(const float* transform, float leftIn, float topIn, float widthIn, float heightIn, float* leftOut, float* topOut, float* widthOut, float* heightOut)
{
    //sfFloatRect rect = {0, 0, 0, 0};
    //CSFML_CHECK_RETURN(transform, rect);

    sf::FloatRect sfmlRect = createTransform(transform).transformRect(sf::FloatRect(leftIn, topIn, widthIn, heightIn));

    *leftOut = sfmlRect.left;
    *topOut = sfmlRect.top;
    *widthOut = sfmlRect.width;
    *heightOut = sfmlRect.height;

    //return rect;
}


void sfTransform_combine(float* transform, const float* other)
{
    CSFML_CHECK(transform);
    CSFML_CHECK(other);

    createTransform(createTransform(transform).combine(createTransform(other)),transform);
}


void sfTransform_translate(float* transform, float x, float y)
{
    CSFML_CHECK(transform);

    createTransform(createTransform(transform).translate(x, y), transform);
}


void sfTransform_rotate(float* transform, float angle)
{
    CSFML_CHECK(transform);

    createTransform(createTransform(transform).rotate(angle),transform);
}


void sfTransform_rotateWithCenter(float* transform, float angle, float centerX, float centerY)
{
    CSFML_CHECK(transform);

    createTransform(createTransform(transform).rotate(angle, centerX, centerY),transform);
}


void sfTransform_scale(float* transform, float scaleX, float scaleY)
{
    CSFML_CHECK(transform);

    createTransform(createTransform(transform).scale(scaleX, scaleY),transform);
}


void sfTransform_scaleWithCenter(float* transform, float scaleX, float scaleY, float centerX, float centerY)
{
    CSFML_CHECK(transform);

    createTransform(createTransform(transform).scale(scaleX, scaleY, centerX, centerY),transform);
}
