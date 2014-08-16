//
//  InvalidExtensionException.h
//  Platform
//
//  Created by Wahid Tanner on 8/16/14.
//

#ifndef Platform_InvalidExtensionException_h
#define Platform_InvalidExtensionException_h

#include <stdexcept>
#include <string>

namespace MuddledManaged
{
    namespace Platform
    {
        class InvalidExtensionException : public std::logic_error
        {
        public:
            InvalidExtensionException (const std::string & path, const std::string & message = std::string(""))
            : std::logic_error("")
            {
                mMessage = "Extension is invalid";
                
                if (path.size() != 0)
                {
                    mMessage += ": " + path;
                }

                if (message.size() != 0)
                {
                    mMessage += ": " + message;
                }
            }
            
            virtual ~InvalidExtensionException ()
            { }
            
            virtual const char * what () const noexcept
            {
                return mMessage.c_str();
            }            
            
        protected:
            InvalidExtensionException ()
            : std::logic_error("")
            { }

            std::string mMessage;
        };
        
    } // namespace Platform
    
} // namespace MuddledManaged

#endif // Platform_InvalidExtensionException_h




