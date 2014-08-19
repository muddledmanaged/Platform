//
//  MacExtensionScenarios.cpp
//  PlatformDesign
//
//  Created by Wahid Tanner on 8/16/14.
//

#include <string>

#include "../../../Submodules/Designer/Include/Designer.h"

#include "../../../Include/ExtensionManager.h"

using namespace std;
using namespace MuddledManaged;

DESIGNER_SCENARIO( MacExtension, "Operation/Normal", "Extension can be loaded." )
{
    Platform::ExtensionManager * pExtMgr = Platform::ExtensionManager::instance();
    string path = "libSimpleTestExtension.dylib";

    pExtMgr->load(path);
}

DESIGNER_SCENARIO( MacExtension, "Operation/Normal", "Extension can be loaded multiple times." )
{
    Platform::ExtensionManager * pExtMgr = Platform::ExtensionManager::instance();
    string path = "libSimpleTestExtension.dylib";

    pExtMgr->load(path);
    pExtMgr->load(path);
}

DESIGNER_SCENARIO( MacExtension, "Operation/Normal", "Extension methods can be called." )
{
    Platform::ExtensionManager * pExtMgr = Platform::ExtensionManager::instance();
    string path = "libSimpleTestExtension.dylib";
    string address = "com.muddledmanaged.simpletestextension";
    string message = "test";
    string reply = "";

    pExtMgr->load(path);
    reply = pExtMgr->sendMessage(address, message);

    verifyEqual("Success from SimpleTestClass: test", reply);
}

DESIGNER_SCENARIO( MacExtension, "Operation/Unknown", "Extension methods can be unrecognized." )
{
    Platform::ExtensionManager * pExtMgr = Platform::ExtensionManager::instance();
    string path = "libSimpleTestExtension.dylib";
    string address = "com.muddledmanaged.simpletestextension";
    string message = "123";
    string reply = "";

    pExtMgr->load(path);
    reply = pExtMgr->sendMessage(address, message);

    verifyEqual("SimpleTestExtension failed to recognize message", reply);
}
