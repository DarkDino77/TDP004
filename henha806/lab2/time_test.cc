#include "catch.hpp"
#include "Time.h"
#include <sstream>

TEST_CASE( "Test to_string and setters")
{
    Time t1{};
    t1.set_hour(10);
    t1.set_minute(11);
    t1.set_second(12);
    REQUIRE( t1.to_string() == "10:11:12" );
}

TEST_CASE( "Test to_string in am/pm format" )
{
    Time t1{};
    t1.set_hour(10);
    t1.set_minute(11);
    t1.set_second(12);
    REQUIRE( t1.to_string(true) == "10:11:12 am" );
}

TEST_CASE( "Test the time constructor" ) 
{
    Time t1{};
    REQUIRE( t1.to_string() == "00:00:00" );
    Time t2{10,25,50};
    REQUIRE( t2.to_string() == "10:25:50" );
    Time t3{t1};
    REQUIRE( t3.to_string() == "00:00:00");

    REQUIRE_THROWS(Time{-10,10,10});
    REQUIRE_THROWS(Time{10,-10,10});
    REQUIRE_THROWS(Time{10,10,-10});

    REQUIRE_THROWS(Time{24,10,10});
    REQUIRE_THROWS(Time{10,60,10});
    REQUIRE_THROWS(Time{10,10,60});

    REQUIRE_NOTHROW(Time{0,10,10});
    REQUIRE_NOTHROW(Time{10,0,10});
    REQUIRE_NOTHROW(Time{10,10,0});

    REQUIRE_NOTHROW(Time{23,10,10});
    REQUIRE_NOTHROW(Time{10,59,10});
    REQUIRE_NOTHROW(Time{10,10,59});
}

TEST_CASE( "Test operator+" )
{
    Time t1{23,59,59};
    Time t2{t1 + 1};
    REQUIRE( t2.to_string() == "00:00:00" );
    Time t3{t2 + (-1)};
    REQUIRE( t3.to_string() == "23:59:59" );
    Time t4{1+t1};
    REQUIRE( t4.to_string() == "00:00:00" );
}

TEST_CASE( "Test operator++" )
{
    Time t1{10,10,10};
    t1++;
    REQUIRE( t1.to_string() == "10:10:11" );
    ++t1;
    REQUIRE( t1.to_string() == "10:10:12" );
}

TEST_CASE( "Test operator-" )
{
    Time t1{10,10,10};
    Time t2{t1 - 5};
    REQUIRE( t2.to_string() == "10:10:05" );
    Time t3{t2 - (-1)};
    REQUIRE( t3.to_string() == "10:10:06" );
}

TEST_CASE( "Test operator--" )
{
    Time t1{10,10,10};
    t1--;
    REQUIRE( t1.to_string() == "10:10:09" );
    --t1;
    REQUIRE( t1.to_string() == "10:10:08" );
}

TEST_CASE( "Test operator>" )
{
    Time t1{10,10,10};
    Time t2{20,20,20};
    REQUIRE( (t2 > t1) == true );
    REQUIRE( (t1 > t2) == false );
}

TEST_CASE( "Test operator>=" )
{
    Time t1{10,10,10};
    Time t2{20,20,20};
    Time t3{t2};
    REQUIRE( (t2 >= t1) == true );
    REQUIRE( (t1 >= t2) == false );
    REQUIRE( (t2 >= t3) == true );
}

TEST_CASE( "Test operator<" )
{
    Time t1{10,10,10};
    Time t2{20,20,20};
    REQUIRE( (t1 < t2) == true );
    REQUIRE( (t2 < t1) == false );
}

TEST_CASE( "Test operator<=" )
{
    Time t1{10,10,10};
    Time t2{20,20,20};
    Time t3{t2};
    REQUIRE( (t1 <= t2) == true );
    REQUIRE( (t2 <= t1) == false );
    REQUIRE( (t2 <= t3) == true );
}

TEST_CASE( "Test operator==" )
{
    Time t1{10,10,10};
    Time t2{20,20,20};
    Time t3{t2};
    REQUIRE( (t1 == t2) == false );
    REQUIRE( (t2 == t3) == true );
}

TEST_CASE( "Test operator!=" )
{
    Time t1{10,10,10};
    Time t2{20,20,20};
    Time t3{t2};
    REQUIRE( (t1 != t2) == true );
    REQUIRE( (t2 != t3) == false );
}

TEST_CASE( "Test operator<<" )
{
    Time t1{10,10,10};
    std::ostringstream oss{};
    oss << t1 << std::flush;
    REQUIRE(oss.str() == "10:10:10");
}

TEST_CASE( "Test operator>>" )
{
    Time t1{10,10,10};
    std::istringstream iss{"23:59:59"};
    iss >> t1;
    REQUIRE( t1.to_string() == "23:59:59" );
}

TEST_CASE( "Test invalid data in operator>>" )
{
    Time t1{10,10,10};
    std::istringstream iss{"10:70:59"};
    REQUIRE_THROWS( iss >> t1 );
}
