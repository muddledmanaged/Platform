//
//  ExtensionScenarios.cpp
//  PlatformDesign
//
//  Created by Wahid Tanner on 8/15/14.
//

#include <string>

#include "../Submodules/Designer/Include/Designer.h"

#include "../Include/ExtensionManager.h"

using namespace std;
using namespace MuddledManaged;

DESIGNER_SCENARIO( Extension, "Construction/Normal", "Extension can be loaded." )
{
    Platform::ExtensionManager extMgr;
    string path = "libSimpleTestExtension.dylib";
    extMgr.load(path);
}
