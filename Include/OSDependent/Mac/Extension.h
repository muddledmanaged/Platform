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

            virtual const int protocolVersion () const;
            virtual const std::string address () const;
            virtual const std::string sendMessage (const std::string & message) const;

        private:
            Extension (const Extension & src) = delete;
            Extension & operator = (const Extension & rhs) = delete;

            void * mHandle;
            std::string mPath;

            const int (*mmGetExtensionProtocolVersion)();
            const char * (*mmGetExtensionAddress)();
            const char * (*mmSendMessage)(const char *);
        };

    } // namespace Platform

} // namespace MuddledManaged

#endif // Platform_Extension_h
