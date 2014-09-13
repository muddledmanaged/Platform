//
//  StringLiteralScenarios.cpp
//  PlatformDesign
//
//  Created by Wahid Tanner on 8/3/14.
//

#include <string>

#include "../Submodules/Designer/Designer/Designer.h"

#include "../Platform/StringLiteral.h"

using namespace MuddledManaged;

DESIGNER_SCENARIO( StringLiteral, "Compilation/Normal", "StringLiteral can be constructed with a string literal." )
{
    constexpr Platform::StringLiteral literal = "ABC";

    verifyEqual('A', literal[0]);
    verifyEqual('B', literal[1]);
    verifyEqual('C', literal[2]);
    verifyEqual('\0', literal[3]);
}

DESIGNER_SCENARIO( StringLiteral, "Compilation/Normal", "StringLiteral can be constructed with concatenated string literals." )
{
    constexpr Platform::StringLiteral literal = "ABC";
    Platform::StringLiteral combinedLiteral = literal + "DEF" + "GHI";

    verifyEqual('A', combinedLiteral[0]);
    verifyEqual('B', combinedLiteral[1]);
    verifyEqual('C', combinedLiteral[2]);
    verifyEqual('D', combinedLiteral[3]);
    verifyEqual('E', combinedLiteral[4]);
    verifyEqual('F', combinedLiteral[5]);
    verifyEqual('G', combinedLiteral[6]);
    verifyEqual('H', combinedLiteral[7]);
    verifyEqual('I', combinedLiteral[8]);
    verifyEqual('\0', combinedLiteral[9]);
}

DESIGNER_SCENARIO( StringLiteral, "Compilation/Normal", "StringLiteral can be constructed with concatenated StringLiterals." )
{
    constexpr Platform::StringLiteral literal1 = "ABC";
    constexpr Platform::StringLiteral literal2 = "DEF";
    constexpr Platform::StringLiteral literal3 = "GHI";
    Platform::StringLiteral combinedLiteral = literal1 + literal2 + literal3;

    verifyEqual('A', combinedLiteral[0]);
    verifyEqual('B', combinedLiteral[1]);
    verifyEqual('C', combinedLiteral[2]);
    verifyEqual('D', combinedLiteral[3]);
    verifyEqual('E', combinedLiteral[4]);
    verifyEqual('F', combinedLiteral[5]);
    verifyEqual('G', combinedLiteral[6]);
    verifyEqual('H', combinedLiteral[7]);
    verifyEqual('I', combinedLiteral[8]);
    verifyEqual('\0', combinedLiteral[9]);
}

DESIGNER_SCENARIO( StringLiteral, "Compilation/Normal", "StringLiteral can be constructed with mixed concatenations." )
{
    constexpr Platform::StringLiteral literal1 = "ABC";
    constexpr Platform::StringLiteral literal3 = "GHI";
    Platform::StringLiteral combinedLiteral = literal1 + "DEF" + literal3;

    verifyEqual('A', combinedLiteral[0]);
    verifyEqual('B', combinedLiteral[1]);
    verifyEqual('C', combinedLiteral[2]);
    verifyEqual('D', combinedLiteral[3]);
    verifyEqual('E', combinedLiteral[4]);
    verifyEqual('F', combinedLiteral[5]);
    verifyEqual('G', combinedLiteral[6]);
    verifyEqual('H', combinedLiteral[7]);
    verifyEqual('I', combinedLiteral[8]);
    verifyEqual('\0', combinedLiteral[9]);
}

DESIGNER_SCENARIO( StringLiteral, "Compilation/Empty", "StringLiteral can be constructed with an empty string literal." )
{
    constexpr Platform::StringLiteral literal = "";

    verifyEqual('\0', literal[0]);
}

DESIGNER_SCENARIO( StringLiteral, "Compilation/Empty", "StringLiteral can append an empty string literal." )
{
    constexpr Platform::StringLiteral literal = "ABC";
    Platform::StringLiteral combinedLiteral = literal + "";

    verifyEqual('A', combinedLiteral[0]);
    verifyEqual('B', combinedLiteral[1]);
    verifyEqual('C', combinedLiteral[2]);
    verifyEqual('\0', combinedLiteral[3]);
}

DESIGNER_SCENARIO( StringLiteral, "Compilation/Empty", "StringLiteral can append multiple empty string literals." )
{
    constexpr Platform::StringLiteral literal = "ABC";
    Platform::StringLiteral combinedLiteral = literal + "" + "";

    verifyEqual('A', combinedLiteral[0]);
    verifyEqual('B', combinedLiteral[1]);
    verifyEqual('C', combinedLiteral[2]);
    verifyEqual('\0', combinedLiteral[3]);
}

DESIGNER_SCENARIO( StringLiteral, "Compilation/Empty", "StringLiteral can be constructed with an embedded empty string literal." )
{
    constexpr Platform::StringLiteral literal1 = "ABC";
    constexpr Platform::StringLiteral literal3 = "DEF";
    Platform::StringLiteral combinedLiteral = literal1 + "" + literal3;

    verifyEqual('A', combinedLiteral[0]);
    verifyEqual('B', combinedLiteral[1]);
    verifyEqual('C', combinedLiteral[2]);
    verifyEqual('D', combinedLiteral[3]);
    verifyEqual('E', combinedLiteral[4]);
    verifyEqual('F', combinedLiteral[5]);
    verifyEqual('\0', combinedLiteral[6]);
}
