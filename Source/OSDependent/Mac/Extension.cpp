//
//  Extension.cpp
//  Platform
//
//  Created by Wahid Tanner on 6/15/14.
//

#include <dlfcn.h>

#include "../../../Include/Exceptions.h"
#include "../../../Include/OSDependent/Mac/Extension.h"

using namespace MuddledManaged;

Platform::Extension::Extension (void * handle)
: handle(handle)
{
    if (handle == nullptr)
    {
        throw Platform::NullArgumentException("handle");
    }

    fdGetExtensionProtocolVersion = reinterpret_cast<decltype(fdGetExtensionProtocolVersion)>(dlsym(handle, "mmGetExtensionProtocolVersion"));
    if (fdGetExtensionProtocolVersion == nullptr)
    {
        throw Platform::InvalidArgumentException("Cannot find mmGetExtensionProtocolVersion.");
    }

    fdGetExtensionAddress = reinterpret_cast<decltype(fdGetExtensionAddress)>(dlsym(handle, "mmGetExtensionAddress"));
    if (fdGetExtensionAddress == nullptr)
    {
        throw Platform::InvalidArgumentException("Cannot find mmGetExtensionAddress.");
    }

    fdSendMessage = reinterpret_cast<decltype(fdSendMessage)>(dlsym(handle, "mmSendMessage"));
    if (fdSendMessage == nullptr)
    {
        throw Platform::InvalidArgumentException("Cannot find mmSendMessage.");
    }
}

Platform::Extension::~Extension ()
{
    dlclose(handle);
}

const int Platform::Extension::protocolVersion () const
{

}

const std::string Platform::Extension::address () const
{

}

const std::string Platform::Extension::sendMessage (const std::string & message) const
{

}

