#pragma once

namespace mpi
{
namespace internal
{
template <typename T, size_t length>
constexpr auto vec_type_maker_helper()
{
    static_assert(length > 0, "no matching vec type for length 0");
    static_assert(length <= 4, "no matching vec type for lengths more than 4");

    if constexpr(length == 1)
        return t_vec1<T>{};
    else if constexpr(length == 2)
        return t_vec2<T>{};
    else if constexpr(length == 3)
        return t_vec3<T>{};
    else
        return t_vec4<T>{};
}
}

template <typename T, size_t length>
struct vec_type_maker
{
    using type = decltype(internal::vec_type_maker_helper<T, length>());
};
}
