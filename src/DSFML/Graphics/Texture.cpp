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
#include <DSFML/Graphics/Texture.h>
#include <DSFML/Graphics/TextureStruct.h>
#include <DSFML/Graphics/ImageStruct.h>
#include <DSFML/Graphics/RenderWindowStruct.h>
#include <DSFML/Window/WindowStruct.h>




sfTexture* sfTexture_create(DUint width, DUint height)
{
    sfTexture* texture = new sfTexture;
    
    if (!texture->This->create(width, height))
    {
        delete texture;
        texture = 0;
    }

    return texture;
}


sfTexture* sfTexture_createFromFile(const char* filename, DInt left, DInt top, DInt width, DInt height)
{
    sfTexture* texture = new sfTexture;

    
    sf::IntRect rect = sf::IntRect(left, top, width, height);

    if (!texture->This->loadFromFile(filename, rect))
    {
        delete texture;
        texture = 0;
    }

    return texture;
}


sfTexture* sfTexture_createFromMemory(const void* data, size_t sizeInBytes, DInt left, DInt top, DInt width, DInt height)
{
    sfTexture* texture = new sfTexture;

    
    
    sf::IntRect rect = sf::IntRect(left, top, width, height);

    if (!texture->This->loadFromMemory(data, sizeInBytes, rect))
    {
        delete texture;
        texture = 0;
    }

    return texture;
}


sfTexture* sfTexture_createFromStream(DStream* stream, DInt left, DInt top, DInt width, DInt height)
{

    sfTexture* texture = new sfTexture;

    sf::IntRect rect = sf::IntRect(left, top, width, height);

    sfmlStream Stream = sfmlStream(stream);

    if (!texture->This->loadFromStream(Stream, rect))
    {
        delete texture;
        texture = 0;
    }

    return texture;
}


sfTexture* sfTexture_createFromImage(const sfImage* image, DInt left, DInt top, DInt width, DInt height)
{
    sfTexture* texture = new sfTexture;

    
    sf::IntRect rect = sf::IntRect(left, top, width, height);

    if (!texture->This->loadFromImage(image->This, rect))
    {
        delete texture;
        texture = 0;
    }

    return texture;
}


sfTexture* sfTexture_copy(const sfTexture* texture)
{
    return new sfTexture(*texture);
}


void sfTexture_destroy(sfTexture* texture)
{
    delete texture;
}


void sfTexture_getSize(const sfTexture* texture, DUint* x, DUint* y)
{
    sf::Vector2u sfmlSize = texture->This->getSize();

    *x = sfmlSize.x;
    *y = sfmlSize.y;

}


sfImage* sfTexture_copyToImage(const sfTexture* texture)
{
    sfImage* image = new sfImage;
    image->This = texture->This->copyToImage();

    return image;
}


void sfTexture_updateFromPixels(sfTexture* texture, const DUbyte* pixels, DUint width, DUint height, DUint x, DUint y)
{
   texture->This->update(pixels, width, height, x, y);
}


void sfTexture_updateFromImage(sfTexture* texture, const sfImage* image, DUint x, DUint y)
{
    texture->This->update(image->This, x, y);
}


void sfTexture_updateFromWindow(sfTexture* texture, const void* window, DUint x, DUint y)
{
    texture->This->update(static_cast<const sfWindow*>(window)->This, x, y);
}


void sfTexture_updateFromRenderWindow(sfTexture* texture, const sfRenderWindow* renderWindow, DUint x, DUint y)
{
    texture->This->update(renderWindow->This, x, y);
}


void sfTexture_setSmooth(sfTexture* texture, DBool smooth)
{
    texture->This->setSmooth(smooth == DTrue);
}


DBool sfTexture_isSmooth(const sfTexture* texture)
{
    return texture->This->isSmooth();
}


void sfTexture_setRepeated(sfTexture* texture, DBool repeated)
{
    texture->This->setRepeated(repeated == DTrue);
}


DBool sfTexture_isRepeated(const sfTexture* texture)
{
    return texture->This->isRepeated();
}


void sfTexture_bind(const sfTexture* texture)
{
    sf::Texture::bind(texture ? texture->This : NULL);
}


DUint sfTexture_getMaximumSize()
{
    return sf::Texture::getMaximumSize();
}
