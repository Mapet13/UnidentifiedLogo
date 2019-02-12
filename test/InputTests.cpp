#include "Test.hpp"

#include "App/Input/Input.hpp"

#include <iostream>
#include <sstream>

namespace UnLOGO::Test
{

    SCENARIO("INPUT")
    {
        Input input;
        
        GIVEN("String reference of input") {
            auto& string = input.getInput();

            THEN("String is empty")
                REQUIRE(string.empty() == true);

            WHEN("Call input init") {
                   
            }


        }
    }

}