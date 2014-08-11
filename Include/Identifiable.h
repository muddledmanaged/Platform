//
//  Identifiable.h
//  Platform
//
//  Created by Wahid Tanner on 2/28/13.
//

#ifndef Platform_Identifiable_h
#define Platform_Identifiable_h

#include <memory>
#include <string>

#include "IdentifiableToken.h"

namespace MuddledManaged
{
    namespace Platform
    {
        class Identifiable
        {
        public:
            virtual ~Identifiable ()
            { }
            
            IdentifiableToken idToken () const
            {
                return IdentifiableToken(*mIdToken);
            }
            
        protected:
            Identifiable (const std::string & token)
            : mIdToken(new IdentifiableToken(token))
            { }
            
            Identifiable (const std::string & token, const std::string & identity)
            : mIdToken(new IdentifiableToken(token, identity))
            { }
            
            Identifiable (const IdentifiableToken & idToken)
            : mIdToken(new IdentifiableToken(idToken))
            { }
            
            Identifiable (const Identifiable & src)
            : mIdToken(new IdentifiableToken(*src.mIdToken))
            { }
            
            Identifiable (Identifiable && src)
            : mIdToken(src.mIdToken.release())
            { }
                        
            Identifiable & operator = (const Identifiable & rhs)
            {
                if (this == &rhs)
                {
                    return *this;
                }
                
                mIdToken.reset(new IdentifiableToken(*rhs.mIdToken));
                
                return *this;
            }
            
            Identifiable & operator = (Identifiable && rhs)
            {
                if (this == &rhs)
                {
                    return *this;
                }
                
                mIdToken.reset(rhs.mIdToken.release());
                
                return *this;
            }
            
            void swap (Identifiable & other)
            {
                std::unique_ptr<IdentifiableToken> thisIdToken(mIdToken.release());
                std::unique_ptr<IdentifiableToken> otherIdToken(other.mIdToken.release());
                
                mIdToken.reset(otherIdToken.release());
                other.mIdToken.reset(thisIdToken.release());
            }
            
        private:
            std::unique_ptr<IdentifiableToken> mIdToken;
        };
        
    } // namespace Platform
    
} // namespace MuddledManaged

#endif // Platform_Identifiable_h




