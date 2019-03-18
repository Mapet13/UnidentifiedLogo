#include "Test.hpp"

#include "Display/DrawableElements.hpp"
#include "Display/Drawable.hpp"

#include <SFML/Graphics/RenderWindow.hpp>

#include <vector>
#include <string>

namespace UnLOGO::Test
{

    namespace Utilities
    {

        struct TestData
        {   
            inline static std::vector<std::string> order;
        };
        
        class FakeWindow 
        {
        public:
            void draw() {
                win.draw(drawable);
            }

        private:
            DrawableElements drawable;
            sf::RenderWindow win;

        };

        class fakeDrawable_BACK : public Drawable<Prority::back> {
            virtual void draw([[maybe_unused]]sf::RenderTarget& target, [[maybe_unused]]sf::RenderStates states) const {
                TestData::order.push_back("BACK");
            }
        };
        class fakeDrawable_MID : public Drawable<Prority::mid> {
            virtual void draw([[maybe_unused]]sf::RenderTarget& target, [[maybe_unused]]sf::RenderStates states) const {
                TestData::order.push_back("MID");
            }
        };
        class fakeDrawable_FRONT : public Drawable<Prority::front> {
            virtual void draw([[maybe_unused]]sf::RenderTarget& target, [[maybe_unused]]sf::RenderStates states) const {
                TestData::order.push_back("FRONT");
            }
        };

    }

    SCENARIO("Display")
    {
        GIVEN("FakeWindow instance") {
            Utilities::FakeWindow win;

            WHEN("None of drawable objects was declared")
            THEN("Not throw an exception while drawing")
                REQUIRE_NOTHROW(win.draw());

        }

        GIVEN("FakeWindow instance, vector with the order of calling draw functions, counter[test performed 10 times], drawables[back, mid, front]") {
            Utilities::FakeWindow win;
            Utilities::fakeDrawable_BACK back;
            Utilities::fakeDrawable_MID mid;
            Utilities::fakeDrawable_FRONT front;
            const std::vector<std::string> correctOrder {"BACK", "MID", "FRONT"};

            WHEN("Draw is called")
            THEN("Order of calling is correct [back, mid, front]") {
                for (auto i = 0; i < 10; ++i) {
                    win.draw();
                    REQUIRE(correctOrder == Utilities::TestData::order);
                    Utilities::TestData::order.clear();
                }
            }
               

        }

    }

}