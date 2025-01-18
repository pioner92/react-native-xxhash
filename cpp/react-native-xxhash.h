#pragma once
#ifndef XXHASH_H
#define XXHASH_H
#include <jsi/jsi.h>
#include <iomanip>
#include <sstream>
#include "xxhash.h"

using namespace facebook;

namespace xxhash {

inline void make_hash_64(const std::string_view str, char result[17]) noexcept {
  XXH64_hash_t hash = XXH3_64bits(str.data(), str.size());
  std::snprintf(result, 17, "%016llx", hash);
};

inline void make_hash_128(const std::string_view str,
                          char result[33]) noexcept {
  XXH128_hash_t hash = XXH3_128bits(str.data(), str.size());
  std::snprintf(result, 33, "%016llx%016llx", hash.high64, hash.low64);
};

void install(jsi::Runtime* rt);
}  // namespace xxhash

#endif /* XXHASH_H */
