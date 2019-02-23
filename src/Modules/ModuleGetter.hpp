#pragma once

namespace UnLogo
{
    
    template <typename... T>
    class ModuleGetter
    {
    private:
        std::tuple<*T...> modules;
    };

}
