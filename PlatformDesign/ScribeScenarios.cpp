//
//  ScribeScenarios.cpp
//  Platform
//
//  Created by Wahid Tanner on 1/21/15.
//

#include <string>

#include "../Submodules/Designer/Designer/Designer.h"

#include "../Platform/Scribe.h"

using namespace std;
using namespace MuddledManaged;

DESIGNER_SCENARIO( Scribe, "Construction/Normal", "Scribe can be constructed." )
{
    Platform::Scribe scribe;
}

DESIGNER_SCENARIO( Scribe, "Construction/Edge", "Multiple Scribe instancescan be constructed." )
{
    Platform::Scribe scribe1;
    Platform::Scribe scribe2;
}

DESIGNER_SCENARIO( Scribe, "Operation/Normal", "Scribe can accept info." )
{
    Platform::Scribe scribe;

    scribe << "This is a test." << Platform::endl;
}
