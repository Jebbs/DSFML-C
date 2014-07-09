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

#ifndef DSFML_SOUNDBUFFER_H
#define DSFML_SOUNDBUFFER_H

//Headers
#include <DSFML/Audio/Export.h>
#include <DSFML/System/DStream.hpp>
#include <DSFML/Audio/Types.h>
#include <stddef.h>

DSFML_AUDIO_API sfSoundBuffer* sfSoundBuffer_create();

DSFML_AUDIO_API sfSoundBuffer* sfSoundBuffer_createFromFile(const char* filename);

DSFML_AUDIO_API sfSoundBuffer* sfSoundBuffer_createFromMemory(const void* data, size_t sizeInBytes);

DSFML_AUDIO_API sfSoundBuffer* sfSoundBuffer_createFromStream(DStream* stream);

DSFML_AUDIO_API sfSoundBuffer* sfSoundBuffer_createFromSamples(const DShort* samples, size_t sampleCount, DUint channelCount, DUint sampleRate);

DSFML_AUDIO_API sfSoundBuffer* sfSoundBuffer_copy(const sfSoundBuffer* soundBuffer);

DSFML_AUDIO_API void sfSoundBuffer_destroy(sfSoundBuffer* soundBuffer);

DSFML_AUDIO_API DBool sfSoundBuffer_saveToFile(const sfSoundBuffer* soundBuffer, const char* filename);

DSFML_AUDIO_API const DShort* sfSoundBuffer_getSamples(const sfSoundBuffer* soundBuffer);

DSFML_AUDIO_API size_t sfSoundBuffer_getSampleCount(const sfSoundBuffer* soundBuffer);

DSFML_AUDIO_API DUint sfSoundBuffer_getSampleRate(const sfSoundBuffer* soundBuffer);

DSFML_AUDIO_API DUint sfSoundBuffer_getChannelCount(const sfSoundBuffer* soundBuffer);

DSFML_AUDIO_API DLong sfSoundBuffer_getDuration(const sfSoundBuffer* soundBuffer);


/*
//Generate a new buffer
DSFML_AUDIO_API void sfSoundBuffer_alGenBuffers(DUint* bufferID);

//Delete a buffer
DSFML_AUDIO_API void sfSoundBuffer_alDeleteBuffer(DUint* bufferID);

//Get the sample rate associated with the buffer
DSFML_AUDIO_API DUint sfSoundBuffer_getSampleRate(DUint bufferID);

//Get the channel count associated wiht the buffer
DSFML_AUDIO_API DUint sfSoundBuffer_getChannelCount(DUint bufferID);

//Fill the buffer up with samples
DSFML_AUDIO_API void sfSoundBuffer_fillBuffer(DUint bufferID, DShort* samples, DLong sampleSize, DUint sampleRate, DUint format);

*/
#endif // DSFML_SOUNDBUFFER_H
