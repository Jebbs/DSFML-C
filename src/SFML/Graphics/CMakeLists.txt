#DSFML Graphics CMake
set(INCROOT ${CMAKE_SOURCE_DIR}/include/SFML/Graphics)
set(SRCROOT ${CMAKE_SOURCE_DIR}/src/SFML/Graphics)

# all source files
set(SRC
 ${INCROOT}/Export.h
 ${SRCROOT}/CreateRenderStates.hpp
 ${SRCROOT}/CreateTransform.hpp
 ${INCROOT}/Err.h
 ${SRCROOT}/Err.cpp
 ${SRCROOT}/Font.cpp
 ${SRCROOT}/FontStruct.h
 ${INCROOT}/Font.h
 ${SRCROOT}/Image.cpp
 ${SRCROOT}/ImageStruct.h
 ${INCROOT}/Image.h
 ${SRCROOT}/RenderTexture.cpp
 ${SRCROOT}/RenderTextureStruct.h
 ${INCROOT}/RenderTexture.h
 ${SRCROOT}/RenderWindow.cpp
 ${SRCROOT}/RenderWindowStruct.h
 ${INCROOT}/RenderWindow.h
 ${SRCROOT}/Shader.cpp
 ${SRCROOT}/ShaderStruct.h
 ${INCROOT}/Shader.h
 ${SRCROOT}/TextStruct.h
 ${SRCROOT}/Texture.cpp
 ${SRCROOT}/TextureStruct.h
 ${INCROOT}/Texture.h
 ${SRCROOT}/Transform.cpp
 ${INCROOT}/Transform.h
 ${INCROOT}/Types.h
 ${SRCROOT}/View.cpp
 ${SRCROOT}/ViewStruct.h
 ${INCROOT}/View.h
)

# define the csfml-graphics target
csfml_add_library(dsfml-graphics
                  SOURCES ${SRC}
                  DEPENDS ${SFML_GRAPHICS_LIBRARY} ${SFML_WINDOW_LIBRARY} ${SFML_SYSTEM_LIBRARY})

