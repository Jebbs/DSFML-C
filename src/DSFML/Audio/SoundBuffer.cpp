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

//Headers
#include <DSFML/Audio/SoundBuffer.h>
#include <DSFML/Audio/SoundBufferStruct.h>

sfSoundBuffer* sfSoundBuffer_create()
{
    return new sfSoundBuffer;
}

sfSoundBuffer* sfSoundBuffer_createFromFile(const char* filename)
{
    sfSoundBuffer* buffer = new sfSoundBuffer;

    if (!buffer->This.loadFromFile(filename))
    {
        delete buffer;
        buffer = NULL;
    }

    return buffer;
}

sfSoundBuffer* sfSoundBuffer_createFromMemory(const void* data, size_t sizeInBytes)
{
    sfSoundBuffer* buffer = new sfSoundBuffer;

    if (!buffer->This.loadFromMemory(data, sizeInBytes))
    {
        delete buffer;
        buffer = NULL;
    }

    return buffer;
}

sfSoundBuffer* sfSoundBuffer_createFromStream(DStream* stream)
{
    sfSoundBuffer* buffer = new sfSoundBuffer;

    sfmlStream Stream = sfmlStream(stream);

    if (!buffer->This.loadFromStream(Stream))
    {
        delete buffer;
        buffer = NULL;
    }

    return buffer;
}

sfSoundBuffer* sfSoundBuffer_createFromSamples(const DShort* samples, size_t sampleCount, DUint channelCount, DUint sampleRate)
{
    sfSoundBuffer* buffer = new sfSoundBuffer;

    if (!buffer->This.loadFromSamples(samples, sampleCount, channelCount, sampleRate))
    {
        delete buffer;
        buffer = NULL;
    }

    return buffer;
}

sfSoundBuffer* sfSoundBuffer_copy(const sfSoundBuffer* soundBuffer)
{
     return new sfSoundBuffer(*soundBuffer);
}

void sfSoundBuffer_destroy(sfSoundBuffer* soundBuffer)
{
    delete soundBuffer;
}

DBool sfSoundBuffer_saveToFile(const sfSoundBuffer* soundBuffer, const char* filename)
{
    return (soundBuffer->This.saveToFile(filename))? DTrue: DFalse;
}

const DShort* sfSoundBuffer_getSamples(const sfSoundBuffer* soundBuffer)
{
    return soundBuffer->This.getSamples();
}

size_t sfSoundBuffer_getSampleCount(const sfSoundBuffer* soundBuffer)
{
    return soundBuffer->This.getSampleCount();
}

DUint sfSoundBuffer_getSampleRate(const sfSoundBuffer* soundBuffer)
{
    return soundBuffer->This.getSampleRate();
}

DUint sfSoundBuffer_getChannelCount(const sfSoundBuffer* soundBuffer)
{
    soundBuffer->This.getChannelCount();
}

DLong sfSoundBuffer_getDuration(const sfSoundBuffer* soundBuffer)
{
    return soundBuffer->This.getDuration().asMicroseconds();
}



/*
void sfSoundBuffer_alGenBuffers(DUint* bufferID)
{
    alCheck(alGenBuffers(1, bufferID));
}

void sfSoundBuffer_alDeleteBuffer(DUint* bufferID)
{
     alCheck(alDeleteBuffers(1, bufferID));
}

DUint sfSoundBuffer_getSampleRate(DUint bufferID)
{
    ALint sampleRate;
    alCheck(alGetBufferi(bufferID, AL_FREQUENCY, &sampleRate));

    return sampleRate;
}

DUint sfSoundBuffer_getChannelCount(DUint bufferID)
{
    ALint channelCount;
    alCheck(alGetBufferi(bufferID, AL_CHANNELS, &channelCount));

    return channelCount;
}

void sfSoundBuffer_fillBuffer(DUint bufferID, DShort* samples, DLong sampleSize, DUint sampleRate, DUint format)
{
    ALsizei size = static_cast<ALsizei>( sampleSize* sizeof(DShort));
    alCheck(alBufferData(bufferID, format, samples, size, sampleRate));
}
*/
