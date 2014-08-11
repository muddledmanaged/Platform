//
//  StringHelper.h
//  Platform
//
//  Created by Wahid Tanner on 6/14/13.
//

#ifndef Platform_StringHelper_h
#define Platform_StringHelper_h

#include <locale>
#include <string>

namespace MuddledManaged
{
    namespace Platform
    {
        class StringHelper
        {
        public:
            static std::string narrow (const std::wstring & wideString)
            {
                std::locale loc;
                std::vector<char> narrowCharBuf(wideString.size());
                std::use_facet<std::ctype<wchar_t>>(loc).narrow(
                    wideString.data(),
                    wideString.data() + wideString.size(),
                    '?',
                    narrowCharBuf.data());
                std::string narrowString = narrowCharBuf.data();
                return narrowString;
            }
        };
        
    } // namespace Platform
    
} // namespace MuddledManaged

#endif // Platform_StringHelper_h
