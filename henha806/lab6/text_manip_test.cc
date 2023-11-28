#include <string>
#include <vector>
#include <sstream>
#include "catch.hpp"
#include "Text_Manip.h"


//=======================================================================
// Test cases
//=======================================================================

TEST_CASE( "Test manipulating a vector of string representing a text" ) 
{
    std::vector<std::string> text{"Programming", "is", "the", "the", "shit"};

    remove(text, "the");
    REQUIRE(text == std::vector<std::string>{"Programming", "is", "shit"});

    substitute(text, "shit+nice");
    REQUIRE(text == std::vector<std::string>{"Programming", "is", "nice"});
}


