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
#include <SFML/Graphics/Image.h>
#include <SFML/Graphics/ImageStruct.h>
#include <SFML/Internal.h>

sfImage* sfImage_create(DUint width, DUint height)
{
    sfImage* image = new sfImage;
    image->This.create(width, height);

    return image;
}


sfImage* sfImage_createFromColor(DUint width, DUint height, DUbyte r, DUbyte b, DUbyte g, DUbyte a)
{
    sfImage* image = new sfImage;
    image->This.create(width, height, sf::Color(r, g, b, a));

    return image;
}


sfImage* sfImage_createFromPixels(DUint width, DUint height, const DUbyte* data)
{
    sfImage* image = new sfImage;
    image->This.create(width, height, data);

    return image;
}


sfImage* sfImage_createFromFile(const char* filename)
{
    sfImage* image = new sfImage;

    if (!image->This.loadFromFile(filename))
    {
        delete image;
        image = NULL;
    }

    return image;
}


sfImage* sfImage_createFromMemory(const void* data, size_t sizeInBytes)
{
    sfImage* image = new sfImage;

    if (!image->This.loadFromMemory(data, sizeInBytes))
    {
        delete image;
        image = NULL;
    }

    return image;
}


sfImage* sfImage_createFromStream(void* stream)
{
    CSFML_CHECK_RETURN(stream, NULL);

    sfImage* image = new sfImage;

    
    if (!image->This.loadFromStream(*reinterpret_cast<sf::InputStream*>(stream)))
    {
        delete image;
        image = NULL;
    }

    return image;
}


sfImage* sfImage_copy(const sfImage* image)
{
    CSFML_CHECK_RETURN(image, NULL);

    return new sfImage(*image);
}


void sfImage_destroy(sfImage* image)
{
    delete image;
}


DBool sfImage_saveToFile(const sfImage* image, const char* filename)
{
    CSFML_CALL_RETURN(image, saveToFile(filename), DFalse);
}


void sfImage_createMaskFromColor(sfImage* image, DUbyte r, DUbyte b, DUbyte g, DUbyte a, DUbyte alpha)
{
    CSFML_CALL(image, createMaskFromColor(sf::Color(r, g, b, a), alpha));
}


void sfImage_copyImage(sfImage* image, const sfImage* source, DUint destX, DUint destY, DInt sourceRectTop, DInt sourceRectLeft, DInt sourceRectWidth, DInt sourceRectHeight, DBool applyAlpha)
{
    CSFML_CHECK(source);
    sf::IntRect sfmlRect(sourceRectLeft, sourceRectTop, sourceRectWidth, sourceRectHeight);
    CSFML_CALL(image, copy(source->This, destX, destY, sfmlRect, applyAlpha == DTrue));
}


void sfImage_setPixel(sfImage* image, DUint x, DUint y, DUbyte r, DUbyte b, DUbyte g, DUbyte a)
{
    CSFML_CALL(image, setPixel(x, y, sf::Color(r, g, b, a)));
}


void sfImage_getPixel(const sfImage* image, DUint x, DUint y, DUbyte* r, DUbyte* b, DUbyte* g, DUbyte* a)
{
    //sfColor color = {0, 0, 0, 0};
    //CSFML_CHECK_RETURN(image, color);

    sf::Color sfmlColor = image->This.getPixel(x, y);

    *r = sfmlColor.r;
    *b = sfmlColor.b;
    *g = sfmlColor.g;
    *a = sfmlColor.a;

}


const DUbyte* sfImage_getPixelsPtr(const sfImage* image)
{
    CSFML_CALL_RETURN(image, getPixelsPtr(), NULL);
}


void sfImage_getSize(const sfImage* image, DUint* width, DUint* height)
{
    //sfVector2u size = {0, 0};
    //CSFML_CHECK_RETURN(image, size);

    sf::Vector2u sfmlSize = image->This.getSize();

    *width = sfmlSize.x;
    *height = sfmlSize.y;

}


void sfImage_flipHorizontally(sfImage* image)
{
    CSFML_CALL(image, flipHorizontally());
}


void sfImage_flipVertically(sfImage* image)
{
    CSFML_CALL(image, flipVertically());
}