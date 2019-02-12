#include "Test.hpp"

#include "Commands/Command.hpp"
#include "Commands/CommandKeeper.hpp"

namespace UnLOGO::Test
{

    class TestCommand : public StdCommand
    {
        REGISTER(TestCommand, "TEST")
    public:
        inline static bool executed { false };
        void execute() override { executed = true; }
    };

    SCENARIO("Command Keeper") 
    {
        GIVEN("Command returned by CommandKeeper") {
            auto testCommand = CommandKeeper::Get("TEST");

            THEN("It isn't a NULL")
                REQUIRE(*testCommand != nullptr);

            WHEN("Call execute function") {
                (*testCommand)->execute();

                THEN("Function was called")
                    REQUIRE(TestCommand::executed == true);
            }

        }
    }
}
