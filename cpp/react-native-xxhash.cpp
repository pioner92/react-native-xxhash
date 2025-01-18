#include "react-native-xxhash.h"

void xxhash::install(jsi::Runtime* rt_ptr) {
  jsi::Runtime& runtime = *rt_ptr;

  jsi::Function hash128 = jsi::Function::createFromHostFunction(
      runtime, jsi::PropNameID::forAscii(runtime, "hash128"), 1,
      [](jsi::Runtime& rt, const jsi::Value& thisVal, const jsi::Value* args,
         size_t count) {
        const jsi::Value& arg = args[0];

        if (!arg.isString()) [[unlikely]] {
          throw jsi::JSError(rt, "Argument is not a 'string'");
        }

        char result[33];

        xxhash::make_hash_128(arg.asString(rt).utf8(rt), result);

        return jsi::String::createFromUtf8(rt, result);
      });

  jsi::Function hash64 = jsi::Function::createFromHostFunction(
      runtime, jsi::PropNameID::forAscii(runtime, "hash64"), 1,
      [](jsi::Runtime& rt, const jsi::Value& thisVal, const jsi::Value* args,
         size_t count) {
        const jsi::Value& arg = args[0];

        if (!arg.isString()) [[unlikely]] {
          throw jsi::JSError(rt, "Argument is not a 'string'");
        }

        char result[17];

        xxhash::make_hash_64(arg.asString(rt).utf8(rt), result);

        return jsi::String::createFromUtf8(rt, result);
      });

  runtime.global().setProperty(runtime, "__xxhash128", std::move(hash128));

  runtime.global().setProperty(runtime, "__xxhash64", std::move(hash64));
}
