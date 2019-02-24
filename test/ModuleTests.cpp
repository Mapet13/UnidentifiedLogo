#include "Test.hpp"

#include "Modules/ModuleGetter.hpp"
#include "Modules/ModuleUnit.hpp"

namespace UnLOGO::Test
{

    namespace Utilities 
    {

        class TestModule : public ModuleUnit
        {
            MODULE_REGISTER(TestModule);

        private:
            int value;

        public:
            void set(int v) { value = v; }
            int  get()      { return value; }

        }

        class ModuleUser
        {
            MODULE_USER(TestModule);

        public:
            void executed(int val) {
                module.get<TestModule>()->set(val);
            }

        }

    }

    SCENARIO("Modules") 
    {
        GIVEN("TestModule and ModuleUser instances") {
            


        }
    }
}
