// Komplettering: list_to_stack() ska gå att anropa som
// list_to_stack(list) utan att behöva typparametrar, dvs inte enbart
// list_to_stack<int>(list). Tips: använd value_tpe för detta

// Kommentar: Ni kan med fördel flytta ihop all testning som har med
// samma klass att göra till samma fil för att göra testningen mer
// överskådlig

// Kommentar: Skicka inte in onödiga (stora) filer, dvs catch.hpp, och
// binära filer

#include <iostream>
#include <list>
#include <vector>

#include "catch.hpp"
#include "Stack.h"


//=======================================================================
// Test cases
//=======================================================================

//TEST_CASE( "Create an empty list" ) 
//{
//    Stack<int> l{};
//    REQUIRE( l.is_empty() );
//    REQUIRE( l.size() == 0 );
//} 

TEST_CASE( "test converting an int list and vector to stack" ) 
{
	std::vector<int> list{1,2,3};
	Stack new_stack{list_to_stack(list)};

    REQUIRE( new_stack.is_empty() == false);
    REQUIRE( new_stack.size() == 3 );
    REQUIRE( new_stack.get_value_at_index(0) == 3);
    REQUIRE( new_stack.get_value_at_index(1) == 2);
    REQUIRE( new_stack.get_value_at_index(2) == 1);

    std::list<int> other_list{1,2,3};
    Stack other_new_stack{list_to_stack(other_list)};

    REQUIRE( other_new_stack.is_empty() == false);
    REQUIRE( other_new_stack.size() == 3 );
    REQUIRE( other_new_stack.get_value_at_index(0) == 3);
    REQUIRE( other_new_stack.get_value_at_index(1) == 2);
    REQUIRE( other_new_stack.get_value_at_index(2) == 1);
}

TEST_CASE( "test converting an double list and vector to stack" ) 
{
	std::vector<double> list{1,2,3};
	Stack<double> new_stack = list_to_stack(list);

    REQUIRE( new_stack.is_empty() == false);
    REQUIRE( new_stack.size() == 3 );
    REQUIRE( new_stack.get_value_at_index(0) == 3);
    REQUIRE( new_stack.get_value_at_index(1) == 2);
    REQUIRE( new_stack.get_value_at_index(2) == 1);

    std::list<double> other_list{1,2,3};
    Stack<double> other_new_stack = list_to_stack(other_list);

    REQUIRE( other_new_stack.is_empty() == false);
    REQUIRE( other_new_stack.size() == 3 );
    REQUIRE( other_new_stack.get_value_at_index(0) == 3);
    REQUIRE( other_new_stack.get_value_at_index(1) == 2);
    REQUIRE( other_new_stack.get_value_at_index(2) == 1);
}

TEST_CASE( "test converting an string list and vector to stack" ) 
{
	std::vector<std::string> list{"1","2","3"};
	Stack<std::string> new_stack = list_to_stack(list);

    REQUIRE( new_stack.is_empty() == false);
    REQUIRE( new_stack.size() == 3 );
    REQUIRE( new_stack.get_value_at_index(0) == "3");
    REQUIRE( new_stack.get_value_at_index(1) == "2");
    REQUIRE( new_stack.get_value_at_index(2) == "1");

    std::list<std::string> other_list{"1","2","3"};
    Stack<std::string> other_new_stack = list_to_stack(other_list);

    REQUIRE( other_new_stack.is_empty() == false);
    REQUIRE( other_new_stack.size() == 3 );
    REQUIRE( other_new_stack.get_value_at_index(0) == "3");
    REQUIRE( other_new_stack.get_value_at_index(1) == "2");
    REQUIRE( other_new_stack.get_value_at_index(2) == "1");
}

