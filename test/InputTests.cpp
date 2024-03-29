#include "Test.hpp"

#include "Input/Input.hpp"

#include <iostream>
#include <sstream>
#include <string>

namespace UnLOGO::Test
{

    namespace Utilities 
    {

        void passInput(const std::string& input)
        {
            static std::istringstream iss;

            iss = std::istringstream(input);
            std::cin.rdbuf(iss.rdbuf());
        }

    }

    SCENARIO("Input")
    {

        GIVEN("Input instance") {
            Input input;

            WHEN("Not call init function")
            THEN("It could be deleted")
                REQUIRE_NOTHROW(input.~Input());

        }
        
        GIVEN("Input instance, String reference of input, testInput array") {
            Input input;
            std::string testInput[2] {"one", "two"};
            auto& string = input.getInput();

            THEN("Input string is empty")
                REQUIRE(string.empty() == true);

            WHEN("Call input init") {
                input.init();

                AND_WHEN("Pass the empty input") {
                    Utilities::passInput("");
                    
                    THEN("Input string is still empty") {
                        std::this_thread::sleep_for(std::chrono::milliseconds(1));
                        REQUIRE(string.empty() == true);
                    }
                }
                AND_WHEN("Pass the first test input") {
                    Utilities::passInput(testInput[0]);
                    
                    THEN("Input string is equal to the first test input") {
                        std::this_thread::sleep_for(std::chrono::milliseconds(6));
                        REQUIRE(string == testInput[0]);
                    }
                }

                AND_WHEN("Pass the second test input") {
                    Utilities::passInput(testInput[1]);

                    THEN("Input string is equal to the second test input") {
                        std::this_thread::sleep_for(std::chrono::milliseconds(1));
                        REQUIRE(string == testInput[1]); 
                    }
                }

            }

        }

    }

}