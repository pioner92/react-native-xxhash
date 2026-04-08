#include "react-native-xxhash.h"

constexpr size_t XXH128_HEX_LEN = 32;
constexpr size_t XXH64_HEX_LEN = 16;
constexpr size_t XXH128_HEX_LEN_NT = XXH128_HEX_LEN + 1;
constexpr size_t XXH64_HEX_LEN_NT = XXH64_HEX_LEN + 1;

void xxhash::install(jsi::Runtime *rt_ptr) {
  jsi::Runtime &runtime = *rt_ptr;

  jsi::Function hash128 = jsi::Function::createFromHostFunction(
      runtime, jsi::PropNameID::forAscii(runtime, "hash128"), 1,
      [](jsi::Runtime &rt, const jsi::Value &thisVal, const jsi::Value *args,
         size_t count) {
        const jsi::Value &arg = args[0];

        if (!arg.isString()) [[unlikely]] {
          throw jsi::JSError(rt, "Argument is not a 'string'");
        }

        char result[XXH128_HEX_LEN_NT];

        xxhash::make_hash_128(arg.asString(rt).utf8(rt), result);

        return jsi::String::createFromAscii(rt, result, XXH128_HEX_LEN);
      });

  jsi::Function hash64 = jsi::Function::createFromHostFunction(
      runtime, jsi::PropNameID::forAscii(runtime, "hash64"), 1,
      [](jsi::Runtime &rt, const jsi::Value &thisVal, const jsi::Value *args,
         size_t count) {
        const jsi::Value &arg = args[0];

        if (!arg.isString()) [[unlikely]] {
          throw jsi::JSError(rt, "Argument is not a 'string'");
        }

        char result[XXH64_HEX_LEN_NT];

        xxhash::make_hash_64(arg.asString(rt).utf8(rt), result);

        return jsi::String::createFromAscii(rt, result, XXH64_HEX_LEN);
      });

  runtime.global().setProperty(runtime, "__xxhash128", std::move(hash128));

  runtime.global().setProperty(runtime, "__xxhash64", std::move(hash64));
}
