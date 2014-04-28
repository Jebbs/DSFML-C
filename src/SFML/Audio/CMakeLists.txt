
set(INCROOT ${PROJECT_SOURCE_DIR}/include/SFML/Audio)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/SFML/Audio)

set(DINCROOT ${PROJECT_SOURCE_DIR}/include/DSFML/Audio)
set(DSRCROOT ${PROJECT_SOURCE_DIR}/src/DSFML/Audio)

# all source files
set(SRC
    ${SRCROOT}/ALCheck.cpp
    ${SRCROOT}/ALCheck.hpp
    ${SRCROOT}/AudioDevice.cpp
    ${SRCROOT}/AudioDevice.hpp
    ${INCROOT}/Export.hpp
    ${SRCROOT}/Listener.cpp
    ${INCROOT}/Listener.hpp
    ${SRCROOT}/Music.cpp
    ${INCROOT}/Music.hpp
    ${SRCROOT}/Sound.cpp
    ${INCROOT}/Sound.hpp
    ${SRCROOT}/SoundBuffer.cpp
    ${INCROOT}/SoundBuffer.hpp
    ${SRCROOT}/SoundBufferRecorder.cpp
    ${INCROOT}/SoundBufferRecorder.hpp
    ${SRCROOT}/SoundFile.cpp
    ${SRCROOT}/SoundFile.hpp
    ${SRCROOT}/SoundRecorder.cpp
    ${INCROOT}/SoundRecorder.hpp
    ${SRCROOT}/SoundSource.cpp
    ${INCROOT}/SoundSource.hpp
    ${SRCROOT}/SoundStream.cpp
    ${INCROOT}/SoundStream.hpp

     ${DINCROOT}/Export.h
     ${DINCROOT}/Err.h
     ${DSRCROOT}/Err.cpp
     ${DSRCROOT}/Listener.cpp
     ${DINCROOT}/Listener.h
     ${DSRCROOT}/Sound.cpp
     ${DINCROOT}/Sound.h
     ${DSRCROOT}/SoundBuffer.cpp
     ${DINCROOT}/SoundBuffer.h
     ${DSRCROOT}/SoundFile.cpp
     ${DINCROOT}/SoundFile.h
     ${DSRCROOT}/InternalSoundRecorder.cpp
     ${DINCROOT}/InternalSoundRecorder.hpp
     ${DSRCROOT}/SoundFileStruct.h
     ${DSRCROOT}/SoundRecorder.cpp
     ${DINCROOT}/SoundRecorder.h
     ${DSRCROOT}/SoundSource.cpp
     ${DINCROOT}/SoundSource.h
     ${DSRCROOT}/SoundStream.cpp
     ${DINCROOT}/SoundStream.h
)
source_group("" FILES ${SRC})

# let CMake know about our additional audio libraries paths (on Windows and OSX)
if(WINDOWS)
    set(CMAKE_INCLUDE_PATH ${CMAKE_INCLUDE_PATH} "${PROJECT_SOURCE_DIR}/extlibs/headers/AL")
    set(CMAKE_INCLUDE_PATH ${CMAKE_INCLUDE_PATH} "${PROJECT_SOURCE_DIR}/extlibs/headers/libsndfile/windows")
elseif (MACOSX)
    set(CMAKE_INCLUDE_PATH ${CMAKE_INCLUDE_PATH} "${PROJECT_SOURCE_DIR}/extlibs/headers/libsndfile/osx")
    set(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} "${PROJECT_SOURCE_DIR}/extlibs/libs-osx/Frameworks")
endif()

# find external libraries
find_package(OpenAL REQUIRED)
find_package(Sndfile REQUIRED)

# add include paths of external libraries
include_directories(${OPENAL_INCLUDE_DIR} ${SNDFILE_INCLUDE_DIR})

# define the sfml-audio target
sfml_add_library(sfml-audio
                 SOURCES ${SRC}
                 DEPENDS dsfml-system
                 EXTERNAL_LIBS ${OPENAL_LIBRARY} ${SNDFILE_LIBRARY})
