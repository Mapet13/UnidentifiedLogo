#pragma once

#include "ModuleHolder.hpp"

namespace UnLogo
{

    #define GET_POINTERS_TYPES_2()  
    #define GET_POINTERS_TYPES_2(M) ,#M*  
    #define GET_POINTERS_TYPES_2(M, ...) , #M* GET_POINTERS_TYPES_2(__VA_ARGS__)
    #define GET_POINTERS_TYPES_1(M, ...) #M* GET_POINTERS_TYPES_2(__VA_ARGS__)

    #define GET_MODULE_PTR_2()  
    #define GET_MODULE_PTR_2(M) , std::get<M*>(ModuleHolder::Modules) 
    #define GET_MODULE_PTR_2(M, ...) , std::get<M*>(ModuleHolder::Modules) GET_MODULE_PTR_2(__VA_ARGS__)
    #define GET_MODULE_PTR_1(M, ...) std::get<M*>(ModuleHolder::Modules) GET_MODULE_PTR_2(__VA_ARGS__)

    #define MODULE_USER(...) std::tuple<GET_POINTERS_TYPES_1(__VA_ARGS__)> modules { GET_MODULE_PTR_1(__VA_ARGS__) };  

}
