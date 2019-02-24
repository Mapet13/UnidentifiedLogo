#include "Test.hpp"

#include "Commands/Command.hpp"
#include "Commands/CommandKeeper.hpp"

namespace UnLOGO::Test
{

    namespace Utilities 
    {

        class CommandWithNoParameters : public Command
        {
            REGISTER(CommandWithNoParameters, "NoParamerers")
        public:
            inline static bool executed { false };
            void execute(CommandParam_t param) override { executed = true; }
        };

        class CommandWithParameters : public Command
        {
            REGISTER(CommandWithParameters, "WithParameters")
        public:
            inline static int value { 0 };
            void execute(CommandParam_t param) override {
                if(param.type() == typeid(int))
                    value = std::any_cast<int>(param);
            }
        };

    }

    SCENARIO("Commands") 
    {
        GIVEN("Command with no parameters returned by CommandKeeper") {
            auto testCommand = CommandKeeper::Get("NoParamerers");

            THEN("It isn't a NULL")
                REQUIRE(*testCommand != nullptr);

            WHEN("Call execute function") {
                (*testCommand)->execute(NULL);

                THEN("Function was called")
                    REQUIRE(Utilities::CommandWithNoParameters::executed == true);
            }

        }

        GIVEN("Command with no parameters returned by CommandKeeper, some value") {
            auto testCommand = CommandKeeper::Get("WithParameters");
            auto correct_value = 5;
            auto incorrect_value = 5.5;

            THEN("It isn't a NULL")
                REQUIRE(*testCommand != nullptr);

            WHEN("Call execute function with correct parameter type {int}") {
                (*testCommand)->execute(correct_value);

                THEN("Function was correctly called [value was changed to parameter]")
                   REQUIRE(Utilities::CommandWithParameters::value == correct_value);
            }

            WHEN("Call execute function with incorrect parameter type {float}") {
                THEN("Not throw an exception") {
                    REQUIRE_NOTHROW((*testCommand)->execute(incorrect_value));
                }
                AND_THEN("Function was correctly called [value was not changed to parameter]") {
                   REQUIRE(Utilities::CommandWithParameters::value != incorrect_value);
                   REQUIRE(Utilities::CommandWithParameters::value == correct_value);
                }
            }

        }
    }
}
