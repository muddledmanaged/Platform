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

void Platform::ExtensionManager::load (const string & path) const
{
    shared_ptr<ExtensionInterface> extension = ExtensionLoader::load(path);
    string address = extension->address();

    //mLoadedExtensions.emplace(address, extension);
}

void Platform::ExtensionManager::loadAll (const string & path) const
{

}

const string Platform::ExtensionManager::sendMessage (const string & address, const string & message) const
{
    shared_ptr<ExtensionInterface> extension = mLoadedExtensions.at(address);

    return extension->sendMessage(message);
}
