//
//  SimpleTestEntry.cpp
//  SimpleTestExtension
//
//  Created by Wahid Tanner on 6/12/14.
//

#include <string>

#include "../Include/SimpleTestEntry.h"
#include "../Include/SimpleTestClass.h"

using namespace std;
using namespace Extensions;

const int mmGetExtensionProtocolVersion ()
{
    return 1;
}

const char * mmGetExtensionAddress ()
{
    return "com.muddledmanaged.simpletestextension";
}

const char * mmSendMessage (const char * message)
{
    const string msg = message;

    if (msg == "test")
    {
        SimpleTestClass target;
        return target.process(msg).data();
    }

    return "SimpleTestExtension failed to recognize message";
}
