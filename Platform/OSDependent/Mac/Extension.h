//
//  Extension.h
//  Platform
//
//  Created by Wahid Tanner on 6/15/14.
//

#ifndef Platform_Extension_h
#define Platform_Extension_h

#include "../../ExtensionInterface.h"

namespace MuddledManaged
{
    namespace Platform
    {
        class Extension : public ExtensionInterface
        {
        public:
            Extension (void * handle, const std::string & path);
            virtual ~Extension ();

            virtual int protocolVersion () const;
            virtual std::string address () const;
            virtual std::string sendMessage (const std::string & message) const;
            virtual void setExtensionManager (ExtensionManager * pExtensionManager) const;

        private:
            Extension (const Extension & src) = delete;
            Extension & operator = (const Extension & rhs) = delete;

            void * mHandle;
            std::string mPath;

            int (*mmGetExtensionProtocolVersion)();
            char * (*mmGetExtensionAddress)();
            char * (*mmSendMessage)(const char *);
            void (*mmSetExtensionManager)(ExtensionManager *);
        };

    } // namespace Platform

} // namespace MuddledManaged

#endif // Platform_Extension_h
