//
//  ExtensionManager.h
//  Platform
//
//  Created by Wahid Tanner on 6/15/14.
//

#ifndef Platform_ExtensionManager_h
#define Platform_ExtensionManager_h

#include <list>
#include <memory>
#include <string>
#include <unordered_map>

#include "ExtensionInterface.h"

namespace MuddledManaged
{
    namespace Platform
    {
        class ExtensionManager
        {
        private:
            typedef std::unordered_map<std::string, std::shared_ptr<Platform::ExtensionInterface>> ExtensionMap;
            
            class ExtensionLoader
            {
            public:
                static std::shared_ptr<ExtensionInterface> load (const std::string & path);
                static std::list<std::shared_ptr<ExtensionInterface>> loadAll (const std::string & path);
            };

        public:
            ~ExtensionManager ();

            static ExtensionManager * instance ();
            
            char * marshal (const std::string & extensionData) const;

            virtual void load (const std::string & path);
            virtual void loadAll (const std::string & path);
            virtual const std::string sendMessage (const std::string & address, const std::string & message) const;

        private:
            ExtensionManager ();
            ExtensionManager (const ExtensionManager & src) = delete;
            ExtensionManager & operator = (const ExtensionManager & rhs) = delete;

            static ExtensionManager * mpInstance;
            ExtensionMap mLoadedExtensions;
        };

    } // namespace Platform

} // namespace MuddledManaged

#endif // Platform_ExtensionManager_h
