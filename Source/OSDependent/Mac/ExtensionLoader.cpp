//
//  ExtensionLoader.cpp
//  Platform
//
//  Created by Wahid Tanner on 6/15/14.
//

#include <dlfcn.h>

#include "../../../Include/Exceptions.h"
#include "../../../Include/ExtensionManager.h"
#include "../../../Include/OSDependent/Mac/Extension.h"

using namespace std;
using namespace MuddledManaged;

 shared_ptr<Platform::ExtensionInterface> Platform::ExtensionManager::ExtensionLoader::load (const string & path)
{
    void * handle = dlopen(path.c_str(), RTLD_LOCAL);
    if (handle)
    {
        return shared_ptr<ExtensionInterface>(new Extension(handle));
    }
    throw Platform::InvalidArgumentException("path", "Cannot open extension.");
}

list<shared_ptr<Platform::ExtensionInterface>> Platform::ExtensionManager::ExtensionLoader::loadAll (const string & path)
{
    list<shared_ptr<Platform::ExtensionInterface>> extensions;

    return extensions;
}
