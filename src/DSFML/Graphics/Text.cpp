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
#include <DSFML/Graphics/Text.h>
#include <DSFML/Graphics/TextStruct.h>
#include <DSFML/Graphics/Font.h>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/ConvertTransform.hpp>



sfText* sfText_create(void)
{
    sfText* text = new sfText;
    text->Font = 0;

    return text;
}


sfText* sfText_copy(const sfText* text)
{
    return new sfText(*text);
}


void sfText_destroy(sfText* text)
{
    delete text;
}


void sfText_setPosition(sfText* text, sfVector2f position)
{
    text->This.setPosition(position.x, position.y);
}


void sfText_setRotation(sfText* text, float angle)
{
    text->This.setRotation(angle);
}


void sfText_setScale(sfText* text, sfVector2f scale)
{
    text->This.setScale(scale.x, scale.y);
}


void sfText_setOrigin(sfText* text, sfVector2f origin)
{
    text->This.setOrigin(origin.x, origin.y);
}


sfVector2f sfText_getPosition(const sfText* text)
{

    sf::Vector2f sfmlPos = text->This.getPosition();
    position.x = sfmlPos.x;
    position.y = sfmlPos.y;

    return position;
}


float sfText_getRotation(const sfText* text)
{
    text->This.getRotation();
}


sfVector2f sfText_getScale(const sfText* text)
{
    sf::Vector2f sfmlScale = text->This.getScale();
    scale.x = sfmlScale.x;
    scale.y = sfmlScale.y;

    return scale;
}


sfVector2f sfText_getOrigin(const sfText* text)
{
    sf::Vector2f sfmlOrigin = text->This.getOrigin();
    origin.x = sfmlOrigin.x;
    origin.y = sfmlOrigin.y;

    return origin;
}


void sfText_move(sfText* text, sfVector2f offset)
{
    text->This.move(offset.x, offset.y);
}


void sfText_rotate(sfText* text, float angle)
{
    text->This.rotate(angle);
}


void sfText_scale(sfText* text, sfVector2f factors)
{
    text->This.scale(factors.x, factors.y);
}


sfTransform sfText_getTransform(const sfText* text)
{
    text->Transform = convertTransform(text->This.getTransform());
    return text->Transform;
}


sfTransform sfText_getInverseTransform(const sfText* text)
{
    text->InverseTransform = convertTransform(text->This.getInverseTransform());
    return text->InverseTransform;
}


void sfText_setString(sfText* text, const char* string)
{
    text->This.setString(string);
}


void sfText_setUnicodeString(sfText* text, const sfUint32* string)
{
    sf::String UTF32Text = string;
    text->This.setString(UTF32Text);
}


void sfText_setFont(sfText* text, const sfFont* font)
{
    CSFML_CHECK(font);

    text->This.setFont(font->This);
    text->Font = font;
}


void sfText_setCharacterSize(sfText* text, unsigned int size)
{
    text->This.setCharacterSize(size);
}


void sfText_setStyle(sfText* text, sfUint32 style)
{
    text->This.setStyle(style);
}


void sfText_setColor(sfText* text, sfColor color)
{
    text->This.setColor(sf::Color(color.r, color.g, color.b, color.a));
}


const char* sfText_getString(const sfText* text)
{
    text->String = text->This.getString().toAnsiString();

    return text->String.c_str();
}


const sfUint32* sfText_getUnicodeString(const sfText* text)
{
    return text->This.getString().getData();
}


const sfFont* sfText_getFont(const sfText* text)
{
    return text->Font;
}


unsigned int sfText_getCharacterSize(const sfText* text)
{
    text->This.getCharacterSize();
}


sfUint32 sfText_getStyle(const sfText* text)
{
    text->This.getStyle();
}


sfColor sfText_getColor(const sfText* text)
{
    sf::Color sfmlColor = text->This.getColor();
    color.r = sfmlColor.r;
    color.g = sfmlColor.g;
    color.b = sfmlColor.b;
    color.a = sfmlColor.a;

    return color;
}


sfVector2f sfText_findCharacterPos(const sfText* text, size_t index)
{
    sf::Vector2f sfmlPos = text->This.findCharacterPos(index);
    position.x = sfmlPos.x;
    position.y = sfmlPos.y;

    return position;
}


sfFloatRect sfText_getLocalBounds(const sfText* text)
{
    sf::FloatRect sfmlRect = text->This.getLocalBounds();
    rect.left = sfmlRect.left;
    rect.top = sfmlRect.top;
    rect.width = sfmlRect.width;
    rect.height = sfmlRect.height;

    return rect;
}


sfFloatRect sfText_getGlobalBounds(const sfText* text)
{
    sf::FloatRect sfmlRect = text->This.getGlobalBounds();
    rect.left = sfmlRect.left;
    rect.top = sfmlRect.top;
    rect.width = sfmlRect.width;
    rect.height = sfmlRect.height;

    return rect;
}
