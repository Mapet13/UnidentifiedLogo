#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include "Utilities/Log.hpp"

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

    TEST_CASE("Adding and using new standard command", "[CommandKeeper]") 
    {
        auto testCommand = CommandKeeper::Get("TEST");

        SECTION("Test if CommandKeeper correctly returned the command") {
            REQUIRE(*testCommand != nullptr);
        }

        SECTION("Test if CommandKeeper correctly executed the command") {
            (*testCommand)->execute();
            REQUIRE(TestCommand::executed == true);
        }

    }
}
