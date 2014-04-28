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


***All code is based on Laurent Gomila's SFML library.***


External Libraries Used:

SFML - The Simple and Fast Multimedia Library
Copyright (C) 2007-2013 Laurent Gomila (laurent.gom@gmail.com)

All Libraries used by SFML
*/

// Headers
#include <DSFML/Network/Http.h>
#include <DSFML/Network/HttpStruct.h>


///HTTP Request Functions

sfHttpRequest* sfHttpRequest_create(void)
{
    return new sfHttpRequest;
}



void sfHttpRequest_destroy(sfHttpRequest* httpRequest)
{
    delete httpRequest;
}



void sfHttpRequest_setField(sfHttpRequest* httpRequest, const char* field, const char* value)
{
    if (field)
        httpRequest->This.setField(field, value);
}



void sfHttpRequest_setMethod(sfHttpRequest* httpRequest, DInt method)
{
    httpRequest->This.setMethod(static_cast<sf::Http::Request::Method>(method));
}



void sfHttpRequest_setUri(sfHttpRequest* httpRequest, const char* uri)
{
    httpRequest->This.setUri(uri ? uri : "");
}



void sfHttpRequest_setHttpVersion(sfHttpRequest* httpRequest, DUint major, DUint minor)
{
    httpRequest->This.setHttpVersion(major, minor);
}



void sfHttpRequest_setBody(sfHttpRequest* httpRequest, const char* body)
{
    httpRequest->This.setBody(body ? body : "");
}


///HTTP Response Functions

void sfHttpResponse_destroy(sfHttpResponse* httpResponse)
{
    delete httpResponse;
}


const char* sfHttpResponse_getField(const sfHttpResponse* httpResponse, const char* field)
{
    if (!field)
        return NULL;

    return httpResponse->This.getField(field).c_str();
}


DInt sfHttpResponse_getStatus(const sfHttpResponse* httpResponse)
{
    return httpResponse->This.getStatus();
}



DUint sfHttpResponse_getMajorVersion(const sfHttpResponse* httpResponse)
{
    httpResponse->This.getMajorHttpVersion();
}



DUint sfHttpResponse_getMinorVersion(const sfHttpResponse* httpResponse)
{
    httpResponse->This.getMinorHttpVersion();
}



const char* sfHttpResponse_getBody(const sfHttpResponse* httpResponse)
{

    return httpResponse->This.getBody().c_str();
}


///HTTP Functions

sfHttp* sfHttp_create(void)
{
    return new sfHttp;
}



void sfHttp_destroy(sfHttp* http)
{
    delete http;
}



void sfHttp_setHost(sfHttp* http, const char* host, DUshort port)
{
    http->This.setHost(host ? host : "", port);
}



sfHttpResponse* sfHttp_sendRequest(sfHttp* http, const sfHttpRequest* request, DLong timeout)
{
    sfHttpResponse* response = new sfHttpResponse;
    response->This = http->This.sendRequest(request->This, sf::microseconds(timeout));

    return response;
}
