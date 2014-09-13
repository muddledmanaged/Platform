//
//  SimpleTestClass.cpp
//  SimpleTestExtension
//
//  Created by Wahid Tanner on 6/12/14.
//

#include "SimpleTestClass.h"

using namespace std;

namespace Extensions
{
    SimpleTestClass::SimpleTestClass ()
    { }

    std::string SimpleTestClass::process (const std::string & message)
    {
        return "Success from SimpleTestClass: " + message;
    }
}