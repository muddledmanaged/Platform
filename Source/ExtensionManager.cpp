//
//  ExtensionManager.cpp
//  Platform
//
//  Created by Wahid Tanner on 6/15/14.
//

#include "../Include/ExtensionManager.h"

using namespace std;
using namespace MuddledManaged;

Platform::ExtensionManager::ExtensionManager ()
{ }

Platform::ExtensionManager::~ExtensionManager ()
{ }

virtual void Platform::ExtensionManager::load (const string & path) const
{
    shared_ptr<ExtensionInterface> extension = ExtensionLoader::load(path);
    loadedExtensions.emplace(extension->address(), extension);
}

virtual void Platform::ExtensionManager::loadAll (const string & path) const
{

}

virtual const string Platform::ExtensionManager::sendMessage (const string & address, const string & message) const
{
    shared_ptr<ExtensionInterface> extension = loadedExtensions.at(address);
    return extension->sendMessage(message);
}
