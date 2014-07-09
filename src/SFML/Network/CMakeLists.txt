
set(INCROOT ${PROJECT_SOURCE_DIR}/include/SFML/Network)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/SFML/Network)
set(DINCROOT ${PROJECT_SOURCE_DIR}/include/DSFML/Network)
set(DSRCROOT ${PROJECT_SOURCE_DIR}/src/DSFML/Network)

# all source files
set(SRC
    ${INCROOT}/Export.hpp
    ${SRCROOT}/Ftp.cpp
    ${INCROOT}/Ftp.hpp
    ${SRCROOT}/Http.cpp
    ${INCROOT}/Http.hpp
    ${SRCROOT}/IpAddress.cpp
    ${INCROOT}/IpAddress.hpp
    ${SRCROOT}/Packet.cpp
    ${INCROOT}/Packet.hpp
    ${SRCROOT}/Socket.cpp
    ${INCROOT}/Socket.hpp
    ${SRCROOT}/SocketImpl.hpp
    ${INCROOT}/SocketHandle.hpp
    ${SRCROOT}/SocketSelector.cpp
    ${INCROOT}/SocketSelector.hpp
    ${SRCROOT}/TcpListener.cpp
    ${INCROOT}/TcpListener.hpp
    ${SRCROOT}/TcpSocket.cpp
    ${INCROOT}/TcpSocket.hpp
    ${SRCROOT}/UdpSocket.cpp
    ${INCROOT}/UdpSocket.hpp

    ${DINCROOT}/Export.h
    ${DINCROOT}/Err.h
    ${DSRCROOT}/Err.cpp
    ${DSRCROOT}/Ftp.cpp
    ${DSRCROOT}/FtpStruct.h
    ${DINCROOT}/Ftp.h
    ${DSRCROOT}/Http.cpp
    ${DSRCROOT}/HttpStruct.h
    ${DINCROOT}/Http.h
    ${DSRCROOT}/IpAddress.cpp
    ${DINCROOT}/IpAddress.h
    ${DSRCROOT}/Packet.cpp
    ${DSRCROOT}/PacketStruct.h
    ${DINCROOT}/Packet.h
    ${DSRCROOT}/SocketSelector.cpp
    ${DSRCROOT}/SocketSelectorStruct.h
    ${DINCROOT}/SocketSelector.h
    ${DSRCROOT}/TcpListener.cpp
    ${DSRCROOT}/TcpListenerStruct.h
    ${DINCROOT}/TcpListener.h
    ${DSRCROOT}/TcpSocket.cpp
    ${DSRCROOT}/TcpSocketStruct.h
    ${DINCROOT}/TcpSocket.h
    ${DINCROOT}/Types.h
    ${DSRCROOT}/UdpSocket.cpp
    ${DSRCROOT}/UdpSocketStruct.h
    ${DINCROOT}/UdpSocket.h
)

# add platform specific sources
if(WINDOWS)
    set(SRC
        ${SRC}
        ${SRCROOT}/Win32/SocketImpl.cpp
        ${SRCROOT}/Win32/SocketImpl.hpp
    )
else()
    set(SRC
        ${SRC}
        ${SRCROOT}/Unix/SocketImpl.cpp
        ${SRCROOT}/Unix/SocketImpl.hpp
    )
endif()

source_group("" FILES ${SRC})

# build the list of external libraries to link
set(NETWORK_EXT_LIBS)
if(WINDOWS)
    set(NETWORK_EXT_LIBS ${NETWORK_EXT_LIBS} ws2_32)
endif()

if(BUILD_SHARED_LIBS)
    add_definitions(-DSFML_NETWORK_EXPORTS)
endif()

# define the sfml-network target
sfml_add_library(dsfml-network
                 SOURCES ${SRC}
                 DEPENDS dsfml-system
                 EXTERNAL_LIBS ${NETWORK_EXT_LIBS})
