#pragma once
#include <cstddef>

namespace mpi
{
template <typename T>
struct t_vec1
{
    using value_type = T;
    static constexpr size_t component_count = 1;

    T x;
};

template <typename T>
struct t_vec2
{
    using value_type = T;
    static constexpr size_t component_count = 2;

    T x;
    T y;
};

template <typename T>
struct t_vec3
{
    using value_type = T;
    static constexpr size_t component_count = 3;

    T x;
    T y;
    T z;
};

template <typename T>
struct t_vec4
{
    using value_type = T;
    static constexpr size_t component_count = 4;

    T x;
    T y;
    T z;
    T w;
};

using vec1 = t_vec1<float>;
using vec2 = t_vec2<float>;
using vec3 = t_vec3<float>;
using vec4 = t_vec4<float>;
using dvec1 = t_vec1<double>;
using dvec2 = t_vec2<double>;
using dvec3 = t_vec3<double>;
using dvec4 = t_vec4<double>;
using ivec1 = t_vec1<int>;
using ivec2 = t_vec2<int>;
using ivec3 = t_vec3<int>;
using ivec4 = t_vec4<int>;
}
