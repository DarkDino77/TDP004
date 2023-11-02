#include "catch.hpp"
#include "Time.h"
#include <sstream>
// här lägger ni era testfall. 
// Jobba enligt TDD; 
//  1. Lägg till testfall
//  2. Testa
//  3. Lägg till (minsta möjliga) implementation
//  4. Testa alla testfall
//  5. Refaktorera (skriv om) så att allt ser bra ut

TEST_CASE("Test constructor")
{
    Time t1{};
    REQUIRE(t1.to_string() == "00:00:00");
    Time const t2{10,11,12};
    REQUIRE(t2.to_string() == "10:11:12");
    Time t3{t1};
    REQUIRE(t3.to_string() == "00:00:00");
    Time t4{t1 + 5};
    REQUIRE(t4.to_string() == "00:00:05");
}

TEST_CASE("Test opperator + math")
{
    Time t1{23,59,59};
    t1 = t1 + 5;
    REQUIRE(t1.to_string() == "00:00:04");
    t1 = t1 + 56;
    REQUIRE(t1.to_string() == "00:01:00");
    t1 = 5 + t1;
    REQUIRE(t1.to_string() == "00:01:05");
    t1 = t1 + (-1);
    REQUIRE(t1.to_string() == "00:01:04");
    t1 = t1 + 3600;
    REQUIRE(t1.to_string() == "01:01:04");
    t1 = t1 + (3600*24);
    REQUIRE(t1.to_string() == "01:01:04");
    t1 = t1 + (-3665);
    REQUIRE(t1.to_string() == "23:59:59");
}
TEST_CASE("Test opperator++")
{
    Time t1{};
    t1++;
    ++t1;
    REQUIRE(t1.to_string() == "00:00:02");
}
TEST_CASE("Test subtraction math")
{
    Time t1{23,59,59};
    t1 = t1 + 5;
    REQUIRE(t1.to_string() == "00:00:04");
}


TEST_CASE("Test equal operator"){
    Time const t1{};
    Time const t2{};
    Time const t3{10,11,12};
    REQUIRE((t1 == t2) == true);
    REQUIRE((t1 == t3) == false);
}
TEST_CASE("Test not equal operator"){
    Time const t1{};
    Time const t2{};
    Time const t3{10,11,12};
    REQUIRE((t1 != t3) == true);
    REQUIRE((t1 != t2) == false);
}
TEST_CASE("Test less operator"){
    Time const t1{};
    Time const t2{};
    Time const t3{10,11,12};
    REQUIRE((t1 > t3) == false);
    REQUIRE((t1 > t2) == false);
    REQUIRE((t3 > t1) == true);
}
TEST_CASE("Test greater operator"){
    Time const t1{};
    Time const t2{};
    Time const t3{10,11,12};
    REQUIRE((t3 < t1) == false);
    REQUIRE((t1 < t3) == true);
    REQUIRE((t1 < t2) == false);
}
TEST_CASE("Test less than equal operator"){
    Time const t1{};
    Time const t2{};
    Time const t3{10,11,12};
    REQUIRE((t1 >= t2) == true);
    REQUIRE((t1 >= t3) == false);
    REQUIRE((t3 >= t2) == true);
}
TEST_CASE("Test greater than equal operator"){
    Time const t1{};
    Time const t2{};
    Time const t3{10,11,12};
    REQUIRE((t1 <= t2) == true);
    REQUIRE((t1 <= t3) == true);
    REQUIRE((t3 <= t1) == false);
}
TEST_CASE("TEST string stream operater output")
{
    Time t1{};
    std::ostringstream oss{};
    oss << t1 << std::flush;
    REQUIRE(oss.str() == "00:00:00");

}
TEST_CASE("TEST string stream operater input")
{
    Time t1{};
    std::istringstream iss{"23:59:59"};
    iss >> t1;
    REQUIRE(t1.to_string() == "23:59:59");
}
