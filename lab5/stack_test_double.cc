#include <random>
#include <iostream>

#include "catch.hpp"
#include "Stack.h"


//=======================================================================
// Test cases
//=======================================================================

TEST_CASE( "Create an empty list" ) 
{
    Stack<double> l{};
    REQUIRE( l.is_empty() );
    REQUIRE( l.size() == 0 );
} 

TEST_CASE( "push an item in an empty list" ) 
{
    Stack<double> l{};

    l.push(5);

    REQUIRE( l.is_empty() == false);
    REQUIRE( l.size() == 1 );
}

TEST_CASE( "print list with one or more items in it" ) 
{
    Stack<double> l{};
    l.push(5);
  
    REQUIRE( l.to_string() == "List: [5.000000]" );
	l.print_list();

    l.pop();

    REQUIRE( l.to_string() == "List: []" );
	l.print_list();

    l.push(3);
    l.push(4);

    REQUIRE( l.to_string() == "List: [4.000000, 3.000000]" );
	l.print_list();
}
  
SCENARIO( "Empty lists" ) 
{
    GIVEN( "An empty list" ) 
    {
		Stack<double> l{};

		REQUIRE( l.is_empty() );
		REQUIRE( l.size() == 0 );

		WHEN( "an item is pushed" )
		{
			// push an item
			l.push(5);

			THEN( "the size increase and the item is first in the list" )
			{
			REQUIRE( l.is_empty() == false );
			REQUIRE( l.size() == 1 );
			/* test that item is first in list */
			REQUIRE(l.get_value_at_index(0) == 5);
			}
		}
    
		WHEN( "an item is removed" )
		{
			l.push(5);
			// remove an item
			l.pop();

			
			THEN( "the list is still empty" )
			{
			// add your REQUIRE statements
			REQUIRE( l.is_empty() == true);
			REQUIRE( l.size() == 0 );
			}
		}
    
		WHEN( "the list is copied to a new list" )
		{
			// copy your list to a new variable (copy constructor)
			Stack<double> new_list{l};
		
			THEN( "the new list is also empty" )
			{
			// add your REQUIRE statements
			REQUIRE( new_list.is_empty() );
			REQUIRE( new_list.size() == 0 );
			}
		}
    
		WHEN( "the list is copied to an existing non-empty list" )
		{
			// create and fill a list to act as the existing list
			// copy (assign) your empty list to the existing
			Stack<double> new_list{};
			l.push(5);

			l = new_list;
		
			THEN( "the existing list is also empty" )
			{
			// add your REQUIRE statements
			REQUIRE(l.is_empty());
			REQUIRE(l.size() == 0);
			}
		}
    }
}
SCENARIO( "Single item lists" )
{
    GIVEN( "A list with one item in it" )
    {
        Stack<double> l{};
        l.push(5);
    
		WHEN( "a smaller item is pushed" )
		{
			l.push(3);

			THEN( "The smaller item is pushed before the first item" )
			{
				REQUIRE(l.get_value_at_index(0) == 3);
				REQUIRE(l.get_value_at_index(1) == 5);
				REQUIRE(l.size() == 2);
			}
		}

		WHEN( "a larger item is pushed" )
		{
			l.push(7);
			THEN( "The larger item is still pushed before the first item" )
			{
				REQUIRE(l.get_value_at_index(0) == 7);
				REQUIRE(l.get_value_at_index(1) == 5);
				REQUIRE(l.size() == 2);
			}
		}

		WHEN( "an item is removed" )
		{
			l.push(2);
			l.pop();

			THEN( "The first item is removed" )
			{
				REQUIRE(l.get_value_at_index(0) == 5);
				REQUIRE(l.size() == 1);
			}
		}

		WHEN( "the list is copied to a new list" )
		{
			Stack<double> new_list{l};

			THEN( "The new list now has the same values as the first list" )
			{
				REQUIRE(new_list.get_value_at_index(0) == 5);
				REQUIRE(new_list.size() == 1);
				REQUIRE(l.get_value_at_index(0) == 5);
				REQUIRE(l.size() == 1);
			}
		}

		WHEN( "the list is copied to an existing non-empty list" )
		{
			Stack<double> new_list{};
			new_list = l;

			THEN( "The new list now has the same values as the first list" )
			{
				REQUIRE(new_list.get_value_at_index(0) == 5);
				REQUIRE(new_list.size() == 1);
				REQUIRE(l.get_value_at_index(0) == 5);
				REQUIRE(l.size() == 1);
			}
		}
    }
}

SCENARIO( "Multi-item lists" )
{

    GIVEN( "A list with five items in it" )
    {

		Stack<double> l{};
		l.push(10);
		l.push(8);
		l.push(6);
		l.push(4);
		l.push(2);
		
		WHEN( "an item is pushed" )
		{
			l.push(1);
			THEN( "The new item is pushed at the beginning of the list" )
			{
				REQUIRE(l.get_value_at_index(0) == 1);
				REQUIRE(l.get_value_at_index(1) == 2);
				REQUIRE(l.get_value_at_index(2) == 4);
				REQUIRE(l.get_value_at_index(3) == 6);
				REQUIRE(l.get_value_at_index(4) == 8);
				REQUIRE(l.get_value_at_index(5) == 10);
				REQUIRE(l.size() == 6);
			}			
		}

		WHEN( "an item is removed" )
		{
			l.pop();
			THEN( "The remaining items are still in the list and the corresponding podoubleers are corrected" )
			{
				REQUIRE(l.get_value_at_index(0) == 4);
				REQUIRE(l.get_value_at_index(1) == 6);
				REQUIRE(l.get_value_at_index(2) == 8);
				REQUIRE(l.get_value_at_index(3) == 10);
				REQUIRE(l.size() == 4);
			}
		}

		WHEN( "all items are removed" )
		{
			l.pop();
			l.pop();
			l.pop();
			l.pop();
			l.pop();

			THEN( "The list becomes empty" )
			{
				REQUIRE(l.size() == 0);
				REQUIRE(l.is_empty());
			}
		}

		WHEN( "the list is copied to a new list" )
		{
			Stack<double> new_list{l};
			THEN( "The new list now has the same values as the first list" )
			{
				REQUIRE(new_list.get_value_at_index(0) == 2);
				REQUIRE(new_list.get_value_at_index(1) == 4);
				REQUIRE(new_list.get_value_at_index(2) == 6);
				REQUIRE(new_list.get_value_at_index(3) == 8);
				REQUIRE(new_list.get_value_at_index(4) == 10);
				REQUIRE(new_list.size() == 5);

				REQUIRE(l.get_value_at_index(0) == 2);
				REQUIRE(l.get_value_at_index(1) == 4);
				REQUIRE(l.get_value_at_index(2) == 6);
				REQUIRE(l.get_value_at_index(3) == 8);
				REQUIRE(l.get_value_at_index(4) == 10);
				REQUIRE(l.size() == 5);
			}
		}
		
		WHEN( "the list is copied to an existing non-empty list" )
		{
			Stack<double> new_list{};
			new_list.push(1);
			new_list.push(3);

			new_list = l;

			THEN( "The new list now has the same values as the first list" )
			{
				REQUIRE(new_list.get_value_at_index(0) == 2);
				REQUIRE(new_list.get_value_at_index(1) == 4);
				REQUIRE(new_list.get_value_at_index(2) == 6);
				REQUIRE(new_list.get_value_at_index(3) == 8);
				REQUIRE(new_list.get_value_at_index(4) == 10);
				REQUIRE(new_list.size() == 5);

				REQUIRE(l.get_value_at_index(0) == 2);
				REQUIRE(l.get_value_at_index(1) == 4);
				REQUIRE(l.get_value_at_index(2) == 6);
				REQUIRE(l.get_value_at_index(3) == 8);
				REQUIRE(l.get_value_at_index(4) == 10);
				REQUIRE(l.size() == 5);
			}
		}
    }
}

SCENARIO( "Lists can be copied" )
{
    GIVEN( "A list with five items in it, and a new copy of that list" )
    {
        Stack<double> l{};
        l.push(10);
        l.push(8);
        l.push(6);
        l.push(4);
        l.push(2);
        Stack<double> new_list{l};

        WHEN( "the original list is changed" )
        {
            l.pop();
            l.pop();
            l.pop();
            l.pop();
            l.pop();
            l.push(1);

            THEN( "the copy remain unmodified" )
            {
                REQUIRE(new_list.get_value_at_index(0) == 2);
                REQUIRE(new_list.get_value_at_index(1) == 4);
                REQUIRE(new_list.get_value_at_index(2) == 6);
                REQUIRE(new_list.get_value_at_index(3) == 8);
                REQUIRE(new_list.get_value_at_index(4) == 10);
                REQUIRE(new_list.size() == 5);
            }
        }

        WHEN( "the copied list is changed" )
        {
            new_list.pop();
            new_list.pop();
            new_list.pop();
            new_list.pop();
            new_list.pop();
            new_list.push(1);
			
            THEN( "the original remain unmodified" )
            {
                REQUIRE(l.get_value_at_index(0) == 2);
                REQUIRE(l.get_value_at_index(1) == 4);
                REQUIRE(l.get_value_at_index(2) == 6);
                REQUIRE(l.get_value_at_index(3) == 8);
                REQUIRE(l.get_value_at_index(4) == 10);
                REQUIRE(l.size() == 5);
            }
        }
    }
}


Stack<double> trigger_move(Stack<double> l)
{
	l.push(5);
	l.push(9);
	l.push(3);
    return l;
}

SCENARIO( "Lists can be passed to functions" )
{

    GIVEN( "A list with 5 items in it" )
    {
		Stack<double> given{};
		given.push(10);
		given.push(8);
		given.push(6);
		given.push(4);
		given.push(2);
  
		WHEN( "the list is passed to trigger_move()" )
		{
			Stack<double> l{ trigger_move(given) };
		
			THEN( "the given list remain and the result have the change" )
			{
				REQUIRE(l.get_value_at_index(0) == 3);
				REQUIRE(l.get_value_at_index(1) == 9);
				REQUIRE(l.get_value_at_index(2) == 5);
				REQUIRE(l.get_value_at_index(3) == 2);
				REQUIRE(l.get_value_at_index(4) == 4);
				REQUIRE(l.get_value_at_index(5) == 6);
				REQUIRE(l.get_value_at_index(6) == 8);
				REQUIRE(l.get_value_at_index(7) == 10);
				REQUIRE(l.size() == 8);

				REQUIRE(given.get_value_at_index(0) == 2);
				REQUIRE(given.get_value_at_index(1) == 4);
				REQUIRE(given.get_value_at_index(2) == 6);
				REQUIRE(given.get_value_at_index(3) == 8);
				REQUIRE(given.get_value_at_index(4) == 10);
				REQUIRE(given.size() == 5);
			}
		}
    }
}

// Finally you need to check that you can do all operations that make
// sense also on a immutable list (eg all operations but push):  
void use_const_list(Stack<double> const& l)
{
    l.is_empty();
    l.size();
    l.get_value_at_index(0);
    l.to_string();
    l.print_list();
}

SCENARIO( "All operations that do not modify the list can be performed on a list" )
{
    GIVEN( "A list with five items in it" )
    {
        Stack<double> l{};
        l.push(2);
        l.push(4);
        l.push(6);
        l.push(8);
        l.push(10);

        WHEN( "The list is sent doubleo the modify function" )
        {
            THEN( "The list remains unmodified and does not throw any exceptions" )
            {
                REQUIRE_NOTHROW(use_const_list(l));
            }
        }
    }

}
