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
#include <SFML/Graphics/Font.h>
#include <SFML/Graphics/FontStruct.h>
#include <SFML/Internal.h>
#include <SFML/System/InputStream.hpp>



sfFont* sfFont_createFromFile(const char* filename)
{
    sfFont* font = new sfFont;

    if (!font->This.loadFromFile(filename))
    {
        delete font;
        font = NULL;
    }

    font->fontTexture = new sfTexture;

    return font;
}



sfFont* sfFont_createFromMemory(const void* data, size_t sizeInBytes)
{
    sfFont* font = new sfFont;
    if (!font->This.loadFromMemory(data, sizeInBytes))
    {
        delete font;
        font = NULL;
    }

    font->fontTexture = new sfTexture;

    return font;
}



sfFont* sfFont_createFromStream(DStream* stream)
{
   // CSFML_CHECK_RETURN(stream, NULL);

    sfFont* font = new sfFont;

     

    font->Stream = new sfmlStream(stream);
    if (!font->This.loadFromStream(*font->Stream))
    {
        delete font;
        font = NULL;
    }

    font->fontTexture = new sfTexture;

    return font;
}



sfFont* sfFont_copy(const sfFont* font)
{
    CSFML_CHECK_RETURN(font, NULL);

    return new sfFont(*font);
}



void sfFont_destroy(sfFont* font)
{
    //purposefully do not delete the texture as that is handled by the D Texture class
    delete font;
}



void sfFont_getGlyph(const sfFont* font, DUint codePoint, DInt characterSize, DBool bold, DInt* glyphAdvance, DInt* glyphBoundsLeft, DInt* glyphBoundsTop, DInt* glyphBoundsWidth, DInt* glyphBoundsHeight, DInt* glyphTextRectLeft, DInt* glyphTextRectTop, DInt* glyphTextRectWidth, DInt* glyphTextRectHeight)
{
   // sfGlyph glyph = {0, {0, 0, 0, 0}, {0, 0, 0, 0}};
    //CSFML_CHECK_RETURN(font, glyph);

    sf::Glyph SFMLGlyph = font->This.getGlyph(codePoint, characterSize, bold == DTrue);

    *glyphAdvance            = SFMLGlyph.advance;
    *glyphBoundsLeft        = SFMLGlyph.bounds.left;
    *glyphBoundsTop         = SFMLGlyph.bounds.top;
    *glyphBoundsWidth       = SFMLGlyph.bounds.width;
    *glyphBoundsHeight      = SFMLGlyph.bounds.height;
    *glyphTextRectLeft   = SFMLGlyph.textureRect.left;
    *glyphTextRectTop    = SFMLGlyph.textureRect.top;
    *glyphTextRectWidth  = SFMLGlyph.textureRect.width;
    *glyphTextRectHeight = SFMLGlyph.textureRect.height;


}



DInt sfFont_getKerning(const sfFont* font, DUint first, DUint second, DUint characterSize)
{
    CSFML_CALL_RETURN(font, getKerning(first, second, characterSize), 0);
}



DInt sfFont_getLineSpacing(const sfFont* font, DUint characterSize)
{
    CSFML_CALL_RETURN(font, getLineSpacing(characterSize), 0);
}



sfTexture* sfFont_getTexturePtr(const sfFont* font)//, DUint characterSize)
{
    CSFML_CHECK_RETURN(font, NULL);

    return font->fontTexture;
}

void sfFont_updateTexture(const sfFont* font, DUint characterSize)
{
    *font->fontTexture->This = font->This.getTexture(characterSize);
}
