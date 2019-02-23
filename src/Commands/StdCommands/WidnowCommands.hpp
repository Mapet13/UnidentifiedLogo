#pragma once

#include "Commands/Command.hpp"
#include "Commands/CommandKeeper.hpp"
#include "Window/Board/Board.hpp"
#include "Modules/ModuleGetter.hpp"

namespace UnLOGO 
{

    class ClearScreenCommand : public Command, public ModuleGetter<Board>
    {
        REGISTER(ClearScreenCommand, "CLEARSCREEN")

    public:
        void execute(CommandParam_t param param) override {
            auto& color = std::any_cast<sf::Color&>(param);

            module.get<Board>().setBackgroudColor(sf::Color(0, 0, 0));
        }
    };

}