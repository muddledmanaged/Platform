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

DESIGNER_SCENARIO( Extension, "Construction/Singleton", "Extension manager instances are the same." )
{
    Platform::ExtensionManager * pExtMgr1 = Platform::ExtensionManager::instance();
    Platform::ExtensionManager * pExtMgr2 = Platform::ExtensionManager::instance();

    verifyTrue(pExtMgr1 != nullptr);
    verifySame(pExtMgr1, pExtMgr2);
}
