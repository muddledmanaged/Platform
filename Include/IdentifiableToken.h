//
//  IdentifiableToken.h
//  Platform
//
//  Created by Wahid Tanner on 3/20/13.
//

#ifndef Platform_IdentifiableToken_h
#define Platform_IdentifiableToken_h

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/random_generator.hpp>
#include <boost/uuid/string_generator.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <string>

#include "Exceptions.h"

namespace MuddledManaged
{
    namespace Platform
    {
        class IdentifiableToken
        {
        public:
            explicit IdentifiableToken (const std::string & token)
            : mToken(token),
              mId(boost::uuids::random_generator()())
            { }
            
            IdentifiableToken (const std::string & token, const std::string & identity)
            : mToken(token),
              mId(boost::uuids::string_generator()(identity))
            { }
            
            IdentifiableToken (const IdentifiableToken & src)
            : mToken(src.mToken),
              mId(src.mId)
            { }
            
            IdentifiableToken (IdentifiableToken && src)
            : mToken(std::move(src.mToken)),
              mId(std::move(src.mId))
            { }
            
            ~IdentifiableToken ()
            { }
            
            std::string token () const
            {
                return std::string(mToken);
            }
            
            std::string identity () const
            {
                return to_string(mId);
            }
            
            std::string toString () const
            {
                return "(" + std::string(mToken) + ": " + to_string(mId) + ")";
            }            
            
            bool operator == (const IdentifiableToken & rhs) const
            {
                return mId == rhs.mId;
            }
            
            bool operator != (const IdentifiableToken & rhs) const
            {
                return mId != rhs.mId;
            }
            
            bool operator < (const IdentifiableToken & rhs) const
            {
                return mId < rhs.mId;
            }
            
            bool operator > (const IdentifiableToken & rhs) const
            {
                return mId > rhs.mId;
            }
            
            bool operator <= (const IdentifiableToken & rhs) const
            {
                return mId <= rhs.mId;
            }
            
            bool operator >= (const IdentifiableToken & rhs) const
            {
                return mId >= rhs.mId;
            }
            
            bool tokenEqual (const IdentifiableToken & other) const
            {
                return mToken == other.mToken;
            }
            
            bool tokenNotEqual (const IdentifiableToken & other) const
            {
                return mToken != other.mToken;
            }
            
            bool tokenLess (const IdentifiableToken & other) const
            {
                return mToken < other.mToken;
            }
            
            bool tokenGreater (const IdentifiableToken & other) const
            {
                return mToken > other.mToken;
            }
            
            bool tokenLessEqual (const IdentifiableToken & other) const
            {
                return mToken <= other.mToken;
            }
            
            bool tokenGreaterEqual (const IdentifiableToken & other) const
            {
                return mToken >= other.mToken;
            }
            
        private:
            IdentifiableToken & operator = (const IdentifiableToken &) = delete;
            
            std::string mToken;
            boost::uuids::uuid mId;
        };
        
    } // namespace Platform
    
} // namespace MuddledManaged

#endif // Platform_IdentifiableToken_h




