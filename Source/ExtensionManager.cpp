//
//  ExtensionManager.cpp
//  Platform
//
//  Created by Wahid Tanner on 6/15/14.
//

#include "../Include/ExtensionManager.h"

using namespace std;
using namespace MuddledManaged;

Platform::ExtensionManager * Platform::ExtensionManager::mpInstance = nullptr;

Platform::ExtensionManager::ExtensionManager ()
{ }

Platform::ExtensionManager::~ExtensionManager ()
{ }

Platform::ExtensionManager * Platform::ExtensionManager::instance ()
{
    if (mpInstance == nullptr)
    {
        mpInstance = new Platform::ExtensionManager();
    }
    return mpInstance;
}

char * Platform::ExtensionManager::marshal (const std::string & extensionData) const
{
    size_t length = extensionData.length();
    char * localData = new char[length + 1];
    extensionData.copy(localData, length);
    localData[length] = '\0';

    return localData;
}

void Platform::ExtensionManager::load (const string & path)
{
    shared_ptr<Platform::ExtensionInterface> extension = ExtensionLoader::load(path);
    extension->setExtensionManager(this);
    string address = extension->address();

    mLoadedExtensions.emplace(address, extension);
}

void Platform::ExtensionManager::loadAll (const string & path)
{
    list<shared_ptr<ExtensionInterface>> extensions = ExtensionLoader::loadAll(path);

    for (auto & singleExtension : extensions)
    {
        singleExtension->setExtensionManager(this);
        string address = singleExtension->address();

        mLoadedExtensions.emplace(address, singleExtension);
    }
}

const string Platform::ExtensionManager::sendMessage (const string & address, const string & message) const
{
    shared_ptr<ExtensionInterface> extension = mLoadedExtensions.at(address);

    return extension->sendMessage(message);
}
