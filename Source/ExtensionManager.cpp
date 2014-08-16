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

void Platform::ExtensionManager::load (const string & path) const
{
    shared_ptr<ExtensionInterface> extension = ExtensionLoader::load(path);
    string address = extension->address();

    //loadedExtensions.emplace(address, extension);
}

void Platform::ExtensionManager::loadAll (const string & path) const
{

}

const string Platform::ExtensionManager::sendMessage (const string & address, const string & message) const
{
    shared_ptr<ExtensionInterface> extension = loadedExtensions.at(address);

    return extension->sendMessage(message);
}
