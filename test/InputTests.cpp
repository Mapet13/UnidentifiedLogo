#include "Test.hpp"

#include "App/Input/Input.hpp"

#include <iostream>
#include <sstream>

namespace UnLOGO::Test
{

    SCENARIO("Input")
    {

        GIVEN("Input instance") {
            Input input;

            WHEN("Not call init function")
            THEN("It could be deleted")
                REQUIRE_NOTHROW(input.~Input());

        }
        
        GIVEN("String reference of input") {
            Input input;
            std::string testInput[2] {"one", "two"};
            auto& string = input.getInput();

            THEN("Input string is empty")
                REQUIRE(string.empty() == true);

            WHEN("Call input init") {
                input.init();

                AND_WHEN("Pass the first test input") 
                    THEN("Input string is equal to the first test input")

                AND_WHEN("Pass the second test input") 
                    THEN("Input string is equal to the second test input")
            
            }


        }
    }

}