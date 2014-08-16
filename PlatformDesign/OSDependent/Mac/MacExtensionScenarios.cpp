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
