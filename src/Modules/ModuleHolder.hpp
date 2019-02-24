#pragma once

namespace UnLogo
{

    template <typename... T>
    class ModuleHolder
    {
    public:
        static const std::tuple<(T*)...> Modules;
        
    };

}
