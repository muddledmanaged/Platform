//
//  IdentifiableTokenScenarios.cpp
//  PlatformDesign
//
//  Created by Wahid Tanner on 6/24/13.
//

#include <string>

#include "../Submodules/Designer/Designer/Designer.h"

#include "../Platform/IdentifiableToken.h"

using namespace MuddledManaged;

DESIGNER_SCENARIO( IdentifiableToken, "Construction/Normal", "IdentifiableToken can be constructed with a token value." )
{
    std::string token = "test";
    Platform::IdentifiableToken idToken(token);
    
    verifyEqual(token, idToken.token());
}

DESIGNER_SCENARIO( IdentifiableToken, "Construction/Normal", "IdentifiableToken can be constructed with token and id values." )
{
    std::string token = "test";
    std::string identity = "01234567-89ab-cdef-0123-456789abcdef";
    Platform::IdentifiableToken idToken(token, identity);
    
    verifyEqual(token, idToken.token());
    verifyEqual(identity, idToken.identity());
}
