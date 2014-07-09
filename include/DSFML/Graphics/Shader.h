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

#ifndef SFML_SHADER_H
#define SFML_SHADER_H


// Headers
#include <DSFML/Graphics/Export.h>
#include <DSFML/Graphics/Types.h>
#include <DSFML/System/DStream.hpp>




//Load both the vertex and fragment shaders from files
DSFML_GRAPHICS_API sfShader* sfShader_createFromFile(const char* vertexShaderFilename, const char* fragmentShaderFilename);


//Load both the vertex and fragment shaders from source codes in memory
DSFML_GRAPHICS_API sfShader* sfShader_createFromMemory(const char* vertexShader, const char* fragmentShader);


//Load both the vertex and fragment shaders from custom streams
DSFML_GRAPHICS_API sfShader* sfShader_createFromStream(void* vertexShaderStream, void* fragmentShaderStream);


//Destroy an existing shader
DSFML_GRAPHICS_API void sfShader_destroy(sfShader* shader);


//Change a float parameter of a shader
DSFML_GRAPHICS_API void sfShader_setFloatParameter(sfShader* shader, const char* name, float x);


//Change a 2-components vector parameter of a shader
DSFML_GRAPHICS_API void sfShader_setFloat2Parameter(sfShader* shader, const char* name, float x, float y);


//Change a 3-components vector parameter of a shader
DSFML_GRAPHICS_API void sfShader_setFloat3Parameter(sfShader* shader, const char* name, float x, float y, float z);


//Change a 4-components vector parameter of a shader
DSFML_GRAPHICS_API void sfShader_setFloat4Parameter(sfShader* shader, const char* name, float x, float y, float z, float w);


//Change a color parameter of a shader
DSFML_GRAPHICS_API void sfShader_setColorParameter(sfShader* shader, const char* name, DUbyte r, DUbyte g, DUbyte b, DUbyte a);


//Change a matrix parameter of a shader
DSFML_GRAPHICS_API void sfShader_setTransformParameter(sfShader* shader, const char* name, float* transform);


//Change a texture parameter of a shader
DSFML_GRAPHICS_API void sfShader_setTextureParameter(sfShader* shader, const char* name, const sfTexture* texture);


//Change a texture parameter of a shader
DSFML_GRAPHICS_API void sfShader_setCurrentTextureParameter(sfShader* shader, const char* name);


//Bind a shader for rendering (activate it)
DSFML_GRAPHICS_API void sfShader_bind(const sfShader* shader);


//Tell whether or not the system supports shaders
DSFML_GRAPHICS_API DBool sfShader_isAvailable(void);


#endif // SFML_SHADER_H
