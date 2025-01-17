#pragma once
#ifndef XXHASH_H
#define XXHASH_H
#include <jsi/jsi.h>
#include "xxhash.h"
#include <iomanip>
#include <sstream>

using namespace facebook;

namespace xxhash {
  enum class HashSize {
    BITS_64,
    BITS_128,
  };

  template <HashSize T>
  inline void make_hash(const std::string_view str, std::stringstream& ss) noexcept;

  template <>
  inline void make_hash<HashSize::BITS_64>(const std::string_view str,
                                    std::stringstream& ss) noexcept {
    XXH64_hash_t hash = XXH3_64bits(str.data(), str.size());

    ss << std::hex << std::setfill('0') << std::setw(16) << hash;
  };

  template <>
  inline void make_hash<HashSize::BITS_128>(const std::string_view str,
                                     std::stringstream& ss) noexcept {
    XXH128_hash_t hash = XXH3_128bits(str.data(), str.size());

    ss << std::hex << std::setfill('0') << std::setw(16) << hash.high64
    << std::setw(16) << hash.low64;
  };

  void install(jsi::Runtime* rt);
}




#endif /* XXHASH_H */
