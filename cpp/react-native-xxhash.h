#pragma once
#ifndef XXHASH_H
#define XXHASH_H
#include "xxhash.h"
#include <iomanip>
#include <jsi/jsi.h>
#include <sstream>

using namespace facebook;

namespace xxhash {

inline void make_hash_64(const std::string_view str, char result[17]) noexcept {
  XXH64_hash_t hash = XXH3_64bits(str.data(), str.size());

  static constexpr char hex[] = "0123456789abcdef";

  for (int i = 0; i < 16; ++i) {
    const uint8_t nibble = (hash >> ((15 - i) * 4)) & 0xF;
    result[i] = hex[nibble];
  }

  result[16] = '\0';
};

inline void make_hash_128(std::string_view str, char result[33]) noexcept {
  const XXH128_hash_t hash = XXH3_128bits(str.data(), str.size());

  static constexpr char hex[] = "0123456789abcdef";

  // high64 → first 16
  for (int i = 0; i < 16; ++i) {
    const uint8_t nibble = (hash.high64 >> ((15 - i) * 4)) & 0xF;
    result[i] = hex[nibble];
  }

  // low64 → next 16
  for (int i = 0; i < 16; ++i) {
    const uint8_t nibble = (hash.low64 >> ((15 - i) * 4)) & 0xF;
    result[16 + i] = hex[nibble];
  }

  result[32] = '\0';
}

void install(jsi::Runtime *rt);
} // namespace xxhash

#endif /* XXHASH_H */
