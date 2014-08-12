//
//  ExtensionLoaderInterface.h
//  Platform
//
//  Created by Wahid Tanner on 6/15/14.
//

#ifndef Platform_ExtensionLoaderInterface_h
#define Platform_ExtensionLoaderInterface_h

#include <list>
#include <string>

#include "ExtensionInterface.h"

namespace MuddledManaged
{
    namespace Platform
    {
        class ExtensionLoaderInterface
        {
            virtual ExtensionInterface load (const std::string & path) const = 0;
            virtual std::list<ExtensionInterface> loadAll (const std::string & path) const = 0;
        };

    } // namespace Platform

} // namespace MuddledManaged

#endif // Platform_ExtensionLoaderInterface_h
