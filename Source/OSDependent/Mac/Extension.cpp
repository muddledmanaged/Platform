//
//  Extension.cpp
//  Platform
//
//  Created by Wahid Tanner on 6/15/14.
//

#include <dlfcn.h>

#include "../../../Include/Exceptions.h"
#include "../../../Include/OSDependent/Mac/Extension.h"

using namespace std;
using namespace MuddledManaged;

Platform::Extension::Extension (void * handle, const std::string & path)
: mHandle(handle), mPath(path)
{
    if (handle == nullptr)
    {
        throw Platform::NullArgumentException("handle");
    }
    if (path == "")
    {
        throw Platform::InvalidArgumentException("path", "path cannot be empty.");
    }

    mmGetExtensionProtocolVersion = reinterpret_cast<decltype(mmGetExtensionProtocolVersion)>(dlsym(mHandle, "mmGetExtensionProtocolVersion"));
    if (mmGetExtensionProtocolVersion == nullptr)
    {
        throw Platform::InvalidExtensionException(mPath, "Cannot find mmGetExtensionProtocolVersion.");
    }

    mmGetExtensionAddress = reinterpret_cast<decltype(mmGetExtensionAddress)>(dlsym(mHandle, "mmGetExtensionAddress"));
    if (mmGetExtensionAddress == nullptr)
    {
        throw Platform::InvalidExtensionException(mPath, "Cannot find mmGetExtensionAddress.");
    }

    mmSendMessage = reinterpret_cast<decltype(mmSendMessage)>(dlsym(mHandle, "mmSendMessage"));
    if (mmSendMessage == nullptr)
    {
        throw Platform::InvalidExtensionException(mPath, "Cannot find mmSendMessage.");
    }

    mmSetExtensionManager = reinterpret_cast<decltype(mmSetExtensionManager)>(dlsym(mHandle, "mmSetExtensionManager"));
    if (mmSetExtensionManager == nullptr)
    {
        throw Platform::InvalidExtensionException(mPath, "Cannot find mmSetExtensionManager.");
    }
}

Platform::Extension::~Extension ()
{
    dlclose(mHandle);
}

int Platform::Extension::protocolVersion () const
{
    return mmGetExtensionProtocolVersion();
}

string Platform::Extension::address () const
{
    char * marshalledResult = mmGetExtensionAddress();
    string result = marshalledResult;
    delete [] marshalledResult;

    return result;
}

string Platform::Extension::sendMessage (const string & message) const
{
    char * marshalledResult = mmSendMessage(message.c_str());
    string result = marshalledResult;
    delete [] marshalledResult;

    return result;
}

void Platform::Extension::setExtensionManager (ExtensionManager * pExtensionManager) const
{
    mmSetExtensionManager(pExtensionManager);
}

