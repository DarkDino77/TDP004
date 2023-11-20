#include <random>
#include <iostream>
#include <list>
#include <vector>

#include "catch.hpp"
#include "Stack.h"


//=======================================================================
// Test cases
//=======================================================================

TEST_CASE( "Create an empty list" ) 
{
    Stack<int> l{};
    REQUIRE( l.is_empty() );
    REQUIRE( l.size() == 0 );
} 

TEST_CASE( "test converting an int list and vector to stack" ) 
{
	std::vector<int> list{1,2,3};
	Stack<int> new_stack = list_to_stack<int>(list);

    REQUIRE( new_stack.is_empty() == false);
    REQUIRE( new_stack.size() == 3 );
    REQUIRE( new_stack.get_value_at_index(0) == 3);
    REQUIRE( new_stack.get_value_at_index(1) == 2);
    REQUIRE( new_stack.get_value_at_index(2) == 1);

    std::list<int> other_list{1,2,3};
    Stack<int> other_new_stack = list_to_stack<int>(other_list);

    REQUIRE( other_new_stack.is_empty() == false);
    REQUIRE( other_new_stack.size() == 3 );
    REQUIRE( other_new_stack.get_value_at_index(0) == 3);
    REQUIRE( other_new_stack.get_value_at_index(1) == 2);
    REQUIRE( other_new_stack.get_value_at_index(2) == 1);
}

TEST_CASE( "test converting an double list and vector to stack" ) 
{
	std::vector<double> list{1,2,3};
	Stack<double> new_stack = list_to_stack<double>(list);

    REQUIRE( new_stack.is_empty() == false);
    REQUIRE( new_stack.size() == 3 );
    REQUIRE( new_stack.get_value_at_index(0) == 3);
    REQUIRE( new_stack.get_value_at_index(1) == 2);
    REQUIRE( new_stack.get_value_at_index(2) == 1);

    std::list<double> other_list{1,2,3};
    Stack<double> other_new_stack = list_to_stack<double>(other_list);

    REQUIRE( other_new_stack.is_empty() == false);
    REQUIRE( other_new_stack.size() == 3 );
    REQUIRE( other_new_stack.get_value_at_index(0) == 3);
    REQUIRE( other_new_stack.get_value_at_index(1) == 2);
    REQUIRE( other_new_stack.get_value_at_index(2) == 1);
}

TEST_CASE( "test converting an string list and vector to stack" ) 
{
	std::vector<std::string> list{"1","2","3"};
	Stack<std::string> new_stack = list_to_stack<std::string>(list);

    REQUIRE( new_stack.is_empty() == false);
    REQUIRE( new_stack.size() == 3 );
    REQUIRE( new_stack.get_value_at_index(0) == "3");
    REQUIRE( new_stack.get_value_at_index(1) == "2");
    REQUIRE( new_stack.get_value_at_index(2) == "1");

    std::list<std::string> other_list{"1","2","3"};
    Stack<std::string> other_new_stack = list_to_stack<std::string>(other_list);

    REQUIRE( other_new_stack.is_empty() == false);
    REQUIRE( other_new_stack.size() == 3 );
    REQUIRE( other_new_stack.get_value_at_index(0) == "3");
    REQUIRE( other_new_stack.get_value_at_index(1) == "2");
    REQUIRE( other_new_stack.get_value_at_index(2) == "1");
}

