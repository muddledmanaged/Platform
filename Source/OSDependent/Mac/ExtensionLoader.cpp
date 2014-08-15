//
//  ExtensionLoader.cpp
//  Platform
//
//  Created by Wahid Tanner on 6/15/14.
//

#include "../../../Include/ExtensionManager.h"
#include "../../../Include/OSDependent/Mac/Extension.h"

using namespace std;
using namespace MuddledManaged;

static shared_ptr<ExtensionInterface> Platform::ExtensionManager::ExtensionLoader::load (const string & path)
{
    void * handle = dlopen(path, RTLD_LOCAL);
    if (handle)
    {
        return shared_ptr<ExtensionInterface>(new Extension(handle));
    }
    throw Platform::InvalidArgumentException("path", "Cannot open extension.");
}

static list<shared_ptr<ExtensionInterface>> Platform::ExtensionManager::ExtensionLoader::loadAll (const string & path)
{
    list<shared_ptr<ExtensionInterface>> extensions;

    return extensions;
}
