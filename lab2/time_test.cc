#include "catch.hpp"
#include "Time.cc"
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
    REQUIRE(t1.get_formated_time() == "[00:00:00]");
    Time t2{10,11,12};
    REQUIRE(t2.get_formated_time() == "[10:11:12]");
    Time t3{t1};
    REQUIRE(t3.get_formated_time() == "[00:00:00]");
    Time t4{t1 + 5};
    REQUIRE(t4.get_formated_time() == "[00:00:05]");
    Time t2{30,90,90};
    REQUIRE(t2.get_formated_time() == "[10:11:12]");
}

TEST_CASE("Test adding time")
{
    Time t1{23,59,59};
    t1 = t1 + 5;
    REQUIRE(t1.get_formated_time() == "[00:00:04]");
}
