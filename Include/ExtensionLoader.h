//
//  ExtensionLoader.h
//  Platform
//
//  Created by Wahid Tanner on 6/15/14.
//

#ifndef Platform_ExtensionLoader_h
#define Platform_ExtensionLoader_h

#include "ExtensionLoaderInterface.h"

namespace MuddledManaged
{
    namespace Platform
    {
        class ExtensionLoader : public ExtensionLoaderInterface
        {
        public:
            ExtensionLoader ();
            ~ExtensionLoader ();

            virtual ExtensionInterface load (const std::string & path) const;
            virtual std::list<ExtensionInterface> loadAll (const std::string & path) const;
        };

    } // namespace Platform

} // namespace MuddledManaged

#endif // Platform_ExtensionLoader_h
