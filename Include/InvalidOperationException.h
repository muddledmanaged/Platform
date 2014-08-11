//
//  InvalidOperationException.h
//  Platform
//
//  Created by Wahid Tanner on 3/26/13.
//

#ifndef Platform_InvalidOperationException_h
#define Platform_InvalidOperationException_h

#include <stdexcept>
#include <string>

namespace MuddledManaged
{
    namespace Platform
    {
        class InvalidOperationException : public std::logic_error
        {
        public:
            InvalidOperationException (const std::string & message = std::string(""))
            : std::logic_error("")
            {
                mMessage = "Opperation is not allowed";
                
                if (message.size() != 0)
                {
                    mMessage += ": " + message;
                }
            }
            
            virtual ~InvalidOperationException ()
            { }
            
            virtual const char * what () const noexcept
            {
                return mMessage.c_str();
            }
            
        protected:
            std::string mMessage;
        };
        
    } // namespace Platform
    
} // namespace MuddledManaged

#endif // Platform_InvalidOperationException_h




