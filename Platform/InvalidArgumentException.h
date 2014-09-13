//
//  InvalidArgumentException.h
//  Platform
//
//  Created by Wahid Tanner on 3/25/13.
//

#ifndef Platform_InvalidArgumentException_h
#define Platform_InvalidArgumentException_h

#include <stdexcept>
#include <string>

namespace MuddledManaged
{
    namespace Platform
    {
        class InvalidArgumentException : public std::invalid_argument
        {
        public:
            InvalidArgumentException (const std::string & argumentName, const std::string & message = std::string(""))
            : std::invalid_argument("")
            {
                mMessage = "Argument is invalid";
                
                if (argumentName.size() != 0)
                {
                    mMessage += ": " + argumentName;
                }
                
                if (message.size() != 0)
                {
                    mMessage += ": " + message;
                }
            }
            
            virtual ~InvalidArgumentException ()
            { }
            
            virtual const char * what () const noexcept
            {
                return mMessage.c_str();
            }            
            
        protected:
            InvalidArgumentException ()
            : std::invalid_argument("")
            { }

            std::string mMessage;
        };
        
    } // namespace Platform
    
} // namespace MuddledManaged

#endif // Platform_InvalidArgumentException_h




