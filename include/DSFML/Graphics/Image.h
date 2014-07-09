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

#ifndef SFML_IMAGE_H
#define SFML_IMAGE_H

// Headers
#include <DSFML/Graphics/Export.h>
#include <DSFML/Graphics/Types.h>
#include <DSFML/System/DStream.hpp>
#include <stddef.h>


//Create an image
DSFML_GRAPHICS_API sfImage* sfImage_create(DUint width, DUint height);

//Create an image and fill it with a unique color
DSFML_GRAPHICS_API sfImage* sfImage_createFromColor(DUint width, DUint height, DUbyte r, DUbyte b, DUbyte g, DUbyte a);

//Create an image from an array of pixels
DSFML_GRAPHICS_API sfImage* sfImage_createFromPixels(DUint width, DUint height, const DUbyte* pixels);

//Create an image from a file on disk
DSFML_GRAPHICS_API sfImage* sfImage_createFromFile(const char* filename);

//Create an image from a file in memory
DSFML_GRAPHICS_API sfImage* sfImage_createFromMemory(const void* data, size_t size);

//Create an image from a custom stream
DSFML_GRAPHICS_API sfImage* sfImage_createFromStream(DStream* stream);

//Copy an existing image
DSFML_GRAPHICS_API sfImage* sfImage_copy(const sfImage* image);

//Destroy an existing image
DSFML_GRAPHICS_API void sfImage_destroy(sfImage* image);

//Save an image to a file on disk
DSFML_GRAPHICS_API DBool sfImage_saveToFile(const sfImage* image, const char* filename);

//Return the size of an image
DSFML_GRAPHICS_API void sfImage_getSize(const sfImage* image, DUint* width, DUint* height);

//Create a transparency mask from a specified color-key
DSFML_GRAPHICS_API void sfImage_createMaskFromColor(sfImage* image, DUbyte r, DUbyte b, DUbyte g, DUbyte a, DUbyte alpha);

//Copy pixels from an image onto another
DSFML_GRAPHICS_API void sfImage_copyImage(sfImage* image, const sfImage* source, DUint destX, DUint destY, DInt sourceRectTop, DInt sourceRectLeft, DInt sourceRectWidth, DInt sourceRectHeight, DBool applyAlpha);

//Change the color of a pixel in an image
DSFML_GRAPHICS_API void sfImage_setPixel(sfImage* image, DUint x, DUint y, DUbyte r, DUbyte b, DUbyte g, DUbyte a);

//Get the color of a pixel in an image
DSFML_GRAPHICS_API void sfImage_getPixel(const sfImage* image, DUint x, DUint y, DUbyte* r, DUbyte* b, DUbyte* g, DUbyte* a);

//Get a read-only pointer to the array of pixels of an image
DSFML_GRAPHICS_API const DUbyte* sfImage_getPixelsPtr(const sfImage* image);

//Flip an image horizontally (left <-> right)
DSFML_GRAPHICS_API void sfImage_flipHorizontally(sfImage* image);

//Flip an image vertically (top <-> bottom)
DSFML_GRAPHICS_API void sfImage_flipVertically(sfImage* image);

#endif // SFML_IMAGE_H