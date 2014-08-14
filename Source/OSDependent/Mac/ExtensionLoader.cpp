//
//  ExtensionLoader.cpp
//  Platform
//
//  Created by Wahid Tanner on 6/15/14.
//

#include "../../../Include/ExtensionManager.h"
#include "../../../Include/OSDependent/Mac/Extension.h"

using namespace MuddledManaged;

static ExtensionInterface Platform::ExtensionManager::ExtensionLoader::load (const std::string & path)
{
    void * handle = dlopen(path, RTLD_LOCAL);
    if (handle)
    {
        return Extension(handle);
    }
}

static std::list<ExtensionInterface> Platform::ExtensionManager::ExtensionLoader::loadAll (const std::string & path)
{

}
