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

    mmGetExtensionProtocolVersion = reinterpret_cast<decltype(mmGetExtensionProtocolVersion)>(dlsym(handle, "mmGetExtensionProtocolVersion"));
    if (mmGetExtensionProtocolVersion == nullptr)
    {
        throw Platform::InvalidArgumentException("Cannot find mmGetExtensionProtocolVersion.");
    }

    mmGetExtensionAddress = reinterpret_cast<decltype(mmGetExtensionAddress)>(dlsym(handle, "mmGetExtensionAddress"));
    if (mmGetExtensionAddress == nullptr)
    {
        throw Platform::InvalidArgumentException("Cannot find mmGetExtensionAddress.");
    }

    mmSendMessage = reinterpret_cast<decltype(mmSendMessage)>(dlsym(handle, "mmSendMessage"));
    if (mmSendMessage == nullptr)
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
    return mmGetExtensionProtocolVersion();
}

const std::string Platform::Extension::address () const
{
    return mmGetExtensionAddress();
}

const std::string Platform::Extension::sendMessage (const std::string & message) const
{
    return mmSendMessage(message);
}

