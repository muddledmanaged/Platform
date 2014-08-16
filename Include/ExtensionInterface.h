//
//  ExtensionInterface.h
//  Platform
//
//  Created by Wahid Tanner on 6/15/14.
//

#ifndef Platform_ExtensionInterface_h
#define Platform_ExtensionInterface_h

#include <string>

namespace MuddledManaged
{
    namespace Platform
    {
        class ExtensionInterface
        {
        public:
            virtual ~ExtensionInterface ()
            { }
            
            virtual const int protocolVersion () const = 0;
            virtual const std::string address () const = 0;
            virtual const std::string sendMessage (const std::string & message) const = 0;

        protected:
            ExtensionInterface ()
            { }
            
        private:
            ExtensionInterface (const ExtensionInterface & src) = delete;
            ExtensionInterface & operator = (const ExtensionInterface & rhs) = delete;
        };

    } // namespace Platform

} // namespace MuddledManaged

#endif // Platform_ExtensionInterface_h
