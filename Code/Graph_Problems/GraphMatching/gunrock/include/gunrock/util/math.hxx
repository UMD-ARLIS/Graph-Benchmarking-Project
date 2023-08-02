/**
 * @file math.hxx
 *
 * @brief
 */

#pragma once

#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <functional>

#include <gunrock/cuda/atomic_functions.hxx>

namespace gunrock {

/**
 * @namespace math
 * Math utilities.
 */
namespace math {

template <typename type_t>
constexpr __host__ __device__ __forceinline__ type_t
divide_round_up(type_t const& a, type_t const& b) {
  return (a + b - 1) / b;
}

/**
 * @brief Statically determine log2(N).
 *
 * @param n
 * @return constexpr int
 */
template <typename type_t>
constexpr type_t log2(const type_t& n) {
  return ((n < 2) ? 0 : 1 + log2(n / 2));
}

/**
 * @brief max Given a, b of type_t find: ((a > b) ? a : b) at compile time.
 * Starting C++14, std::max have support for constexpr, so we just use that.
 *
 * @tparam type_t type of value to be compared.
 * @param a l.h.s of max comparison
 * @param b r.h.s of max comparison
 * @return constexpr const type_t& the maximum value between a and b.
 */
template <typename type_t>
constexpr const type_t& max(const type_t& a, const type_t& b) {
  return std::max(a, b);
}

/**
 * @brief min Given a, b of type_t find: ((a < b) ? a : b) at compile time.
 * Starting C++14, std::min have support for constexpr, so we just use that.
 *
 * @tparam type_t type of value to be compared.
 * @param a l.h.s of min comparison
 * @param b r.h.s of min comparison
 * @return constexpr const type_t& the minimum value between a and b.
 */
template <typename type_t>
constexpr const type_t& min(const type_t& a, const type_t& b) {
  return std::min(a, b);
}

/**
 * @brief namespace atomic, for atomic operations supported on both host and
 * device. In concurrent programming, it means that there will be no context
 * switch during it - nothing can affect the execution of atomic command.
 *
 */
namespace atomic {

template <typename type_t>
__host__ __device__ __forceinline__ type_t add(type_t* address, type_t value) {
#ifdef __CUDA_ARCH__
  return atomicAdd(address, value);
#else
  // use std::atomic::fetch_add();
  auto old_value = *address;
  *address += value;
  return old_value;
#endif
}

template <typename type_t>
__host__ __device__ __forceinline__ type_t min(type_t* address, type_t value) {
#ifdef __CUDA_ARCH__
  return gcuda::atomicMin(address, value);
#else
  return std::min<type_t>(*address, value);  // use std::atomic;
#endif
}

template <typename type_t>
__host__ __device__ __forceinline__ type_t max(type_t* address, type_t value) {
#ifdef __CUDA_ARCH__
  return gcuda::atomicMax(address, value);
#else
  return std::max<type_t>(*address, value);  // use std::atomic;
#endif
}

template <typename type_t>
__host__ __device__ __forceinline__ type_t cas(type_t* address,
                                               type_t compare,
                                               type_t value) {
#ifdef __CUDA_ARCH__
  return atomicCAS(address, compare, value);
#else
  type_t old = *address;
  *address = (old == compare) ? value : old;  // use std::atomic;
  return old;
#endif
}

template <typename type_t>
__host__ __device__ __forceinline__ type_t exch(type_t* address, type_t value) {
#ifdef __CUDA_ARCH__
  return atomicExch(address, value);
#else
  type_t old = *address;
  *address = value;  // use std::atomic;
  return old;
#endif
}

}  // namespace atomic
}  // namespace math
}  // namespace gunrock