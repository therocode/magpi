#pragma once
#include <mpi/core/vec.hpp>
#include <mpi/core/component.hpp>
#include <mpi/core/meta.hpp>

namespace mpi
{
template<typename T, glm::length_t length, glm::qualifier Q>
constexpr auto from_glm(glm::vec<length, T, Q> v)
{
    static_assert(length > 0 && length <= 4, "doesn't know how to convert a glm::vec of this length");

    using mpi_vec = typename vec_type_maker<T, length>::type;

    if constexpr(length == 1)
        return mpi_vec{v.x};
    else if constexpr(length == 2)
        return mpi_vec{v.x, v.y};
    else if constexpr(length == 3)
        return mpi_vec{v.x, v.y, v.z};
    else
        return mpi_vec{v.x, v.y, v.z, v.w};
}

template<typename t_vec>
constexpr auto to_glm(t_vec v)
{
    constexpr size_t length = t_vec::component_count;
    static_assert(length > 0 && length <= 4, "doesn't know how to convert to a glm::vec of this length");

    using glm_vec = glm::vec<length, typename t_vec::value_type>;

    if constexpr(length == 1)
        return glm_vec{v.x};
    else if constexpr(length == 2)
        return glm_vec{v.x, v.y};
    else if constexpr(length == 3)
        return glm_vec{v.x, v.y, v.z};
    else
        return glm_vec{v.x, v.y, v.z, v.w};
}
}
