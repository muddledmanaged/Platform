//
//  NullArgumentException.h
//  Platform
//
//  Created by Wahid Tanner on 3/25/13.
//

#ifndef Platform_NullArgumentException_h
#define Platform_NullArgumentException_h

#include "InvalidArgumentException.h"

namespace MuddledManaged
{
    namespace Platform
    {
        class NullArgumentException : public InvalidArgumentException
        {
        public:
            NullArgumentException (const std::string & argumentName = std::string(""))
            {
                mMessage = "Argument cannot be null";
                
                if (argumentName.size() != 0)
                {
                    mMessage += ": " + argumentName;
                }
            }
            
            virtual ~NullArgumentException ()
            { }
        };
        
    } // namespace Platform
    
} // namespace MuddledManaged

#endif // Platform_NullArgumentException_h




