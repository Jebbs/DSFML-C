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

#ifndef SFML_FONT_H
#define SFML_FONT_H


// Headers
#include <DSFML/Graphics/Export.h>
#include <DSFML/Graphics/Types.h>
#include <DSFML/System/DStream.hpp>
#include <stddef.h>



//Create a new font from a file
DSFML_GRAPHICS_API sfFont* sfFont_createFromFile(const char* filename);


//Create a new image font a file in memory
DSFML_GRAPHICS_API sfFont* sfFont_createFromMemory(const void* data, size_t sizeInBytes);


//Create a new image font a custom stream
DSFML_GRAPHICS_API sfFont* sfFont_createFromStream(DStream* stream);


// Copy an existing font
DSFML_GRAPHICS_API sfFont* sfFont_copy(const sfFont* font);


//Destroy an existing font
DSFML_GRAPHICS_API void sfFont_destroy(sfFont* font);


//Get a glyph in a font
DSFML_GRAPHICS_API void sfFont_getGlyph(const sfFont* font, DUint codePoint, DInt characterSize, DBool bold, DInt* glyphAdvance, DInt* glyphBoundsLeft, DInt* glyphBoundsTop, DInt* glyphBoundsWidth, DInt* glyphBoundsHeight, DInt* glyphTextRectLeft, DInt* glyphTextRectTop, DInt* glyphTextRectWidth, DInt* glyphTextRectHeight);


//Get the kerning value corresponding to a given pair of characters in a font
DSFML_GRAPHICS_API DInt sfFont_getKerning(const sfFont* font, DUint first, DUint second, DUint characterSize);


//Get the line spacing value
DSFML_GRAPHICS_API DInt sfFont_getLineSpacing(const sfFont* font, DUint characterSize);


//Get the texture pointer for a particular font
DSFML_GRAPHICS_API sfTexture* sfFont_getTexturePtr(const sfFont* font);

//Update the internal texture associated with the font
DSFML_GRAPHICS_API void sfFont_updateTexture(const sfFont* font, DUint characterSize);


#endif // SFML_IMAGE_H
