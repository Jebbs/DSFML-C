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
#include <DSFML/Graphics/Shader.h>
#include <DSFML/Graphics/ShaderStruct.h>
#include <DSFML/Graphics/TextureStruct.h>
#include <DSFML/Graphics/CreateTransform.hpp>



sfShader* sfShader_createFromFile(const char* vertexShaderFilename, const char* fragmentShaderFilename)
{
    bool success = false;
    sfShader* shader = new sfShader;
    if (vertexShaderFilename || fragmentShaderFilename)
    {
        if (!vertexShaderFilename)
        {
            // fragment shader only
            success = shader->This.loadFromFile(fragmentShaderFilename, sf::Shader::Fragment);
        }
        else if (!fragmentShaderFilename)
        {
            // vertex shader only
            success = shader->This.loadFromFile(vertexShaderFilename, sf::Shader::Vertex);
        }
        else
        {
            // vertex + fragment shaders
            success = shader->This.loadFromFile(vertexShaderFilename, fragmentShaderFilename);
        }
    }

    if (!success)
    {
        delete shader;
        shader = 0;
    }

    return shader;
}


sfShader* sfShader_createFromMemory(const char* vertexShader, const char* fragmentShader)
{
    bool success = false;
    sfShader* shader = new sfShader;
    if (vertexShader || fragmentShader)
    {
        if (!vertexShader)
        {
            // fragment shader only
            success = shader->This.loadFromMemory(fragmentShader, sf::Shader::Fragment);
        }
        else if (!fragmentShader)
        {
            // vertex shader only
            success = shader->This.loadFromMemory(vertexShader, sf::Shader::Vertex);
        }
        else
        {
            // vertex + fragment shaders
            success = shader->This.loadFromMemory(vertexShader, fragmentShader);
        }
    }

    if (!success)
    {
        delete shader;
        shader = 0;
    }

    return shader;
}


sfShader* sfShader_createFromStream(void* vertexShaderStream, void* fragmentShaderStream)
{
    bool success = false;
    
    sfShader* shader = new sfShader;
    /*
    if (vertexShaderStream || fragmentShaderStream)
    {
        if (!vertexShaderStream)
        {
            // fragment shader only
            CallbackStream stream(fragmentShaderStream);
            success = shader->This.loadFromStream(stream, sf::Shader::Fragment);
        }
        else if (!fragmentShaderStream)
        {
            // vertex shader only
            CallbackStream stream(vertexShaderStream);
            success = shader->This.loadFromStream(stream, sf::Shader::Vertex);
        }
        else
        {
            // vertex + fragment shaders
            CallbackStream vertexStream(vertexShaderStream);
            CallbackStream fragmentStream(fragmentShaderStream);
            success = shader->This.loadFromStream(vertexStream, fragmentStream);
        }
    }
    */

    if (!success)
    {
        delete shader;
        shader = 0;
    }

    return shader;
}


void sfShader_destroy(sfShader* shader)
{
    delete shader;
}


void sfShader_setFloatParameter(sfShader* shader, const char* name, float x)
{
    shader->This.setParameter(name, x);
}


void sfShader_setFloat2Parameter(sfShader* shader, const char* name, float x, float y)
{
    shader->This.setParameter(name, x, y);
}


void sfShader_setFloat3Parameter(sfShader* shader, const char* name, float x, float y, float z)
{
    shader->This.setParameter(name, x, y, z);
}


void sfShader_setFloat4Parameter(sfShader* shader, const char* name, float x, float y, float z, float w)
{
    shader->This.setParameter(name, x, y, z, w);
}


void sfShader_setColorParameter(sfShader* shader, const char* name, DUbyte r, DUbyte g, DUbyte b, DUbyte a)
{
    shader->This.setParameter(name, sf::Color(r, g, b, a));
}


void sfShader_setTransformParameter(sfShader* shader, const char* name, float* transform)
{
    shader->This.setParameter(name, createTransform(transform));
}


void sfShader_setTextureParameter(sfShader* shader, const char* name, const sfTexture* texture)
{
    shader->This.setParameter(name, *texture->This);
}


void sfShader_setCurrentTextureParameter(sfShader* shader, const char* name)
{
    shader->This.setParameter(name, sf::Shader::CurrentTexture);
}


void sfShader_bind(const sfShader* shader)
{
    sf::Shader::bind(shader ? &shader->This : 0);
}


DBool sfShader_isAvailable(void)
{
    return sf::Shader::isAvailable() ? DTrue : DFalse;
}
