#pragma once
#include <mpi/core/vec.hpp>

namespace mpi
{
template <typename t_vec>
constexpr typename t_vec::value_type& get_component(size_t i, t_vec& v)
{
    constexpr size_t count = t_vec::component_count;

    //assert(i < t_vec::component_count, "incompatible index");

    if(i == 3)
    {
        if constexpr (count > 3)
            return v.w;
    }
    else if(i == 2)
    {
        if constexpr (count > 2)
            return v.z;
    }
    else if(i == 1)
    {
        if constexpr (count > 1)
            return v.y;
    }

    return v.x;
}

template <size_t i, typename t_vec>
constexpr typename t_vec::value_type& get_component(t_vec& v)
{
    static_assert(i < t_vec::component_count, "incompatible index");

    return get_component(i, v);
}
}
