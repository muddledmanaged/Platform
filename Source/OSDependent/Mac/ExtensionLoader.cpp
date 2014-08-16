//
//  ExtensionLoader.cpp
//  Platform
//
//  Created by Wahid Tanner on 6/15/14.
//

#include <dirent.h>
#include <dlfcn.h>

#include "../../../Include/Exceptions.h"
#include "../../../Include/ExtensionManager.h"
#include "../../../Include/OSDependent/Mac/Extension.h"

using namespace std;
using namespace MuddledManaged;

shared_ptr<Platform::ExtensionInterface> Platform::ExtensionManager::ExtensionLoader::load (const string & path)
{
    void * handle = dlopen(path.c_str(), RTLD_LOCAL);
    if (handle == nullptr)
    {
        throw Platform::InvalidExtensionException(path);
    }
    return shared_ptr<ExtensionInterface>(new Extension(handle, path));
}

list<shared_ptr<Platform::ExtensionInterface>> Platform::ExtensionManager::ExtensionLoader::loadAll (const string & path)
{
    DIR * pDir = opendir(path.c_str());
    if (pDir == nullptr)
    {
        throw Platform::InvalidArgumentException("path", "Cannot open extension folder.");
    }

    struct dirent * entry;
    list<shared_ptr<Platform::ExtensionInterface>> extensions;
    while ((entry = readdir(pDir)) != nullptr)
    {
        string name = entry->d_name;
        if ((name != ".") && (name != ".."))
        {
            shared_ptr<Platform::ExtensionInterface> singleExtension;
            try
            {
                singleExtension = load(name);
            }
            catch (const Platform::InvalidExtensionException & ex)
            {
                continue;
            }
            extensions.push_back(singleExtension);
        }
    }
    closedir(pDir);

    return extensions;
}
