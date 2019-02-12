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
            auto& string = input.getInput();

            THEN("String is empty")
                REQUIRE(string.empty() == true);

            WHEN("Call input init") {
                input.init();

                AND_WHEN("") {

                }
            
            }


        }
    }

}