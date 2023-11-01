#include "catch.hpp"
#include "Time.h"
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
    Time t2{10,11,12};
    REQUIRE(t2.to_string() == "10:11:12");
    Time t3{t1};
    REQUIRE(t3.to_string() == "00:00:00");
    Time t4{t1 + 5};
    REQUIRE(t4.to_string() == "00:00:05");
}

TEST_CASE("Test time math")
{
    Time t1{23,59,59};
    t1 = t1 + 5;
    REQUIRE(t1.to_string() == "00:00:04");
    t1 = t1 - 2;
    REQUIRE(t1.to_string() == "00:00:02");
    t1 = t1 - 2;
    REQUIRE(t1.to_string() == "00:00:00");
    t1 = t1 - 4;
    REQUIRE(t1.to_string() == "23:59:56");
    t1++;
    REQUIRE(t1.to_string() == "23:59:57");
    ++t1;
    REQUIRE(t1.to_string() == "23:59:58");
    --t1;
    REQUIRE(t1.to_string() == "23:59:57");
    t1--;
    REQUIRE(t1.to_string() == "23:59:56");
}

TEST_CASE("Test comparison operator")
{
    Time t1{};
    Time t2{};
    Time t3{10,11,12};
    REQUIRE((t1 == t2) == true);
    REQUIRE((t1 == t3) == false);
    REQUIRE((t1 != t3) == true);
    REQUIRE((t1 > t3) == false);
    REQUIRE((t1 < t3) == true);
    REQUIRE((t1 >= t2) == true);
    REQUIRE((t1 <= t2) == true);

}

