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
            Extension (void * handle);
            ~Extension ();

            virtual const int protocolVersion () const;
            virtual const std::string address () const;
            virtual const std::string sendMessage (const std::string & message) const;

        private:
            void * handle;

            const int (*mmGetExtensionProtocolVersion)();
            const char * (*mmGetExtensionAddress)();
            const char * (*mmSendMessage)(const char *);
        };

    } // namespace Platform

} // namespace MuddledManaged

#endif // Platform_Extension_h
