//
//  SimpleTestEntry.cpp
//  SimpleTestExtension
//
//  Created by Wahid Tanner on 6/12/14.
//

#include <string>

#include "SimpleTestEntry.h"
#include "SimpleTestClass.h"

using namespace std;
using namespace MuddledManaged;
using namespace Extensions;

MuddledManaged::Platform::ExtensionManager * gpExtensionManager = nullptr;

int mmGetExtensionProtocolVersion ()
{
    return 1;
}

char * mmGetExtensionAddress ()
{
    return gpExtensionManager->marshal("com.muddledmanaged.simpletestextension");
}

char * mmSendMessage (const char * message)
{
    const string msg = message;
    string result = "";

    if (msg == "test")
    {
        SimpleTestClass target;
        result = target.process(msg).data();
    }
    else
    {
        result = "SimpleTestExtension failed to recognize message";
    }

    return gpExtensionManager->marshal(result);
}

void mmSetExtensionManager (MuddledManaged::Platform::ExtensionManager * pExtensionManager)
{
    gpExtensionManager = pExtensionManager;
}
