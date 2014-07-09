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

#ifndef DSFML_VIEW_H
#define DSFML_VIEW_H


// Headers
#include <DSFML/Graphics/Export.h>
#include <DSFML/Graphics/Types.h>




//Create a default view
DSFML_GRAPHICS_API sfView* sfView_create(void);

//Construct a view from a rectangle
DSFML_GRAPHICS_API sfView* sfView_createFromRect(float left, float top, float width, float height);


//Copy an existing view
DSFML_GRAPHICS_API sfView* sfView_copy(const sfView* view);


//Destroy an existing view
DSFML_GRAPHICS_API void sfView_destroy(sfView* view);


//Set the center of a view
DSFML_GRAPHICS_API void sfView_setCenter(sfView* view, float centerX, float centerY);


//Set the size of a view
DSFML_GRAPHICS_API void sfView_setSize(sfView* view, float sizeX, float sizeY);


//Set the orientation of a view
DSFML_GRAPHICS_API void sfView_setRotation(sfView* view, float angle);


//Set the target viewport of a view
DSFML_GRAPHICS_API void sfView_setViewport(sfView* view, float left, float top, float width, float height);


//Reset a view to the given rectangle
DSFML_GRAPHICS_API void sfView_reset(sfView* view, float left, float top, float width, float height);


//Get the center of a view
DSFML_GRAPHICS_API void sfView_getCenter(const sfView* view, float* x, float* y);


//Get the size of a view
DSFML_GRAPHICS_API void sfView_getSize(const sfView* view, float* x, float* y);


//Get the current orientation of a view
DSFML_GRAPHICS_API float sfView_getRotation(const sfView* view);


//Get the target viewport rectangle of a view
DSFML_GRAPHICS_API void sfView_getViewport(const sfView* view, float* left, float* top, float* width, float* height);

//Move a view relatively to its current position
DSFML_GRAPHICS_API void sfView_move(sfView* view, float offsetX, float offsetY);


//Rotate a view relatively to its current orientation
DSFML_GRAPHICS_API void sfView_rotate(sfView* view, float angle);


//Resize a view rectangle relatively to its current size
DSFML_GRAPHICS_API void sfView_zoom(sfView* view, float factor);


#endif // SFML_VIEW_H
