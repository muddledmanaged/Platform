//
//  SimpleTestClass.h
//  SimpleTestExtension
//
//  Created by Wahid Tanner on 6/12/14.
//

#ifndef SimpleTestExtension_SimpleTestClass_h
#define SimpleTestExtension_SimpleTestClass_h

#include <string>

namespace Extensions
{
    class SimpleTestClass
    {
    public:
        SimpleTestClass ();

        std::string process (const std::string & message);
    };
}
#endif // SimpleTestExtension_SimpleTestClass_h
