#include <random>
#include <iostream>

#include "catch.hpp"
#include "Sorted_List.h"


//=======================================================================
// Test cases
//=======================================================================

TEST_CASE( "Create an empty list" ) 
{
    Sorted_List l{};
    REQUIRE( l.is_empty() );
    REQUIRE( l.size() == 0 );
} 

TEST_CASE( "Insert an item in an empty list" ) 
{
    Sorted_List l{};

    l.insert(5);

    REQUIRE( l.is_empty() == false);
    REQUIRE( l.size() == 1 );
}

TEST_CASE( "Print list with one or more items in it" ) 
{
    Sorted_List l{};
    l.insert(5);
  
    REQUIRE( l.to_string() == "List: [5]" );
	l.print_list();

    l.remove_index(0);

    REQUIRE( l.to_string() == "List: []" );
	l.print_list();

    l.insert(3);
    l.insert(4);

    REQUIRE( l.to_string() == "List: [3, 4]" );
	l.print_list();
}
  
SCENARIO( "Empty lists" ) 
{
    GIVEN( "An empty list" ) 
    {
		Sorted_List l{};

		REQUIRE( l.is_empty() );
		REQUIRE( l.size() == 0 );

		WHEN( "an item is inserted" )
		{
			// insert an item
			l.insert(5);

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
			l.insert(5);
			// remove an item
			l.remove_index(0);

			
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
			Sorted_List new_list{l};
		
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
			Sorted_List new_list{};
			l.insert(5);

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
        Sorted_List l{};
        l.insert(5);
    
		WHEN( "a smaller item is inserted" )
		{
			l.insert(3);

			THEN( "The smaller item is inserted before the first item" )
			{
				REQUIRE(l.get_value_at_index(0) == 3);
				REQUIRE(l.get_value_at_index(1) == 5);
				REQUIRE(l.size() == 2);
			}
		}

		WHEN( "a larger item is inserted" )
		{
			l.insert(7);
			THEN( "The larger item is inserted after the first item" )
			{
				REQUIRE(l.get_value_at_index(0) == 5);
				REQUIRE(l.get_value_at_index(1) == 7);
				REQUIRE(l.size() == 2);
			}
		}

		WHEN( "an item is removed" )
		{
			l.insert(2);
			l.remove_index(0);

			THEN( "The first item is removed" )
			{
				REQUIRE(l.get_value_at_index(0) == 5);
				REQUIRE(l.size() == 1);
			}
		}

		WHEN( "the list is copied to a new list" )
		{
			Sorted_List new_list{l};

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
			Sorted_List new_list{};
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

		Sorted_List l{};
		l.insert(2);
		l.insert(4);
		l.insert(6);
		l.insert(8);
		l.insert(10);
		
		WHEN( "an item smaller than all other is inserted" )
		{
			l.insert(1);
			THEN( "The new item is inserted at the beginning of the list" )
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

		WHEN( "an item larger than all other is inserted" )
		{
			l.insert(11);
			THEN( "The new item is inserted at the end of the list" )
			{
				REQUIRE(l.get_value_at_index(0) == 2);
				REQUIRE(l.get_value_at_index(1) == 4);
				REQUIRE(l.get_value_at_index(2) == 6);
				REQUIRE(l.get_value_at_index(3) == 8);
				REQUIRE(l.get_value_at_index(4) == 10);
				REQUIRE(l.get_value_at_index(5) == 11);
				REQUIRE(l.size() == 6);
			}	
		}

		WHEN( "an item smaller than all but one item is inserted" )
		{
			l.insert(3);
			THEN( "The new item is inserted at the second position in the list" )
			{
				REQUIRE(l.get_value_at_index(0) == 2);
				REQUIRE(l.get_value_at_index(1) == 3);
				REQUIRE(l.get_value_at_index(2) == 4);
				REQUIRE(l.get_value_at_index(3) == 6);
				REQUIRE(l.get_value_at_index(4) == 8);
				REQUIRE(l.get_value_at_index(5) == 10);
				REQUIRE(l.size() == 6);
			}	
		}

		WHEN( "an item larger than all but one item is inserted" )
		{
			l.insert(9);
			THEN( "The new item is inserted at the second to last position in the list" )
			{
				REQUIRE(l.get_value_at_index(0) == 2);
				REQUIRE(l.get_value_at_index(1) == 4);
				REQUIRE(l.get_value_at_index(2) == 6);
				REQUIRE(l.get_value_at_index(3) == 8);
				REQUIRE(l.get_value_at_index(4) == 9);
				REQUIRE(l.get_value_at_index(5) == 10);
				REQUIRE(l.size() == 6);
			}
		}

		WHEN( "an item is removed" )
		{
			l.remove_index(0);
			THEN( "The remaining items are still in the list and the corresponding pointers are corrected" )
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
			l.remove_index(4);
			l.remove_index(3);
			l.remove_index(2);
			l.remove_index(1);
			l.remove_index(0);

			THEN( "The list becomes empty" )
			{
				REQUIRE(l.size() == 0);
				REQUIRE(l.is_empty());
			}
		}

		WHEN( "the list is copied to a new list" )
		{
			Sorted_List new_list{l};
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
			Sorted_List new_list{};
			new_list.insert(1);
			new_list.insert(3);

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
        Sorted_List l{};
        l.insert(2);
        l.insert(4);
        l.insert(6);
        l.insert(8);
        l.insert(10);
        Sorted_List new_list{l};

        WHEN( "the original list is changed" )
        {
            l.remove_index(4);
            l.remove_index(3);
            l.remove_index(2);
            l.remove_index(1);
            l.remove_index(0);
            l.insert(1);

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
            new_list.remove_index(4);
            new_list.remove_index(3);
            new_list.remove_index(2);
            new_list.remove_index(1);
            new_list.remove_index(0);
            new_list.insert(1);
			
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

SCENARIO( "Lists can be heavily used" )
{

    GIVEN( "A list with 1000 random items in it" )
    {
        Sorted_List l{};
    
        // create the given list with 1000 random items
        std::random_device rd;
        std::uniform_int_distribution<int> uniform(1,1000);
        
        for (int i{0}; i < 1000; ++i)
        {
            int random { uniform(rd) }; // generate a random number
            l.insert(random);
        }
        
        WHEN( "the list have 1000 random numbers inserted" )
        {
            for (int i{0}; i < 1000; ++i)
            {
                int random { uniform(rd) }; // generate a random number
                l.insert(random);
            }
            
            THEN("the list have 2000 items in correct order")
            {
                REQUIRE(l.size() == 2000);

                // l.size()-1 ensures to loop does not go out of bounds.
                for (int i {0}; i < l.size()-1; i++)
                {
                    REQUIRE(l.get_value_at_index(i) <= l.get_value_at_index(i+1));
                }
            }
        }

        WHEN( "the list have 2000 random numbers removed" )
        {
            for (int i{0}; i < 1000; ++i)
            {
                int random { uniform(rd) }; // generate a random number
                l.insert(random);
            }

            for (int i{0}; i < 2000; i++)
            {
                std::uniform_int_distribution<int> uniform(1,l.size());

                int random { uniform(rd) };
                l.remove_index(random - 1);
            }

            THEN("The list is empty")
            {
                REQUIRE(l.is_empty());
                REQUIRE(l.size() == 0);
            }
        }
    }
}

Sorted_List trigger_move(Sorted_List l)
{
	l.insert(5);
	l.insert(9);
	l.insert(3);
    return l;
}

SCENARIO( "Lists can be passed to functions" )
{

    GIVEN( "A list with 5 items in it" )
    {
		Sorted_List given{};
		given.insert(2);
		given.insert(4);
		given.insert(6);
		given.insert(8);
		given.insert(10);
  
		WHEN( "the list is passed to trigger_move()" )
		{
			Sorted_List l{ trigger_move(given) };
		
			THEN( "the given list remain and the result have the change" )
			{
				REQUIRE(l.get_value_at_index(0) == 2);
				REQUIRE(l.get_value_at_index(1) == 3);
				REQUIRE(l.get_value_at_index(2) == 4);
				REQUIRE(l.get_value_at_index(3) == 5);
				REQUIRE(l.get_value_at_index(4) == 6);
				REQUIRE(l.get_value_at_index(5) == 8);
				REQUIRE(l.get_value_at_index(6) == 9);
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
// sense also on a immutable list (eg all operations but insert):  
void use_const_list(Sorted_List const& l)
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
        Sorted_List l{};
        l.insert(2);
        l.insert(4);
        l.insert(6);
        l.insert(8);
        l.insert(10);

        WHEN( "The list is sent into the modify function" )
        {
            THEN( "The list remains unmodified and does not throw any exceptions" )
            {
                REQUIRE_NOTHROW(use_const_list(l));
            }
        }
    }
}
