# react-native-xxhash

react-native-xxhash

## Installation

```sh
npm install react-native-xxhash
```

```sh
yarn add react-native-xxhash
```

## Usage


```js
import { hash128, hash64 } from 'react-native-xxhash';

// ...

//This function provides a fast and deterministic 128-bit hash for a given string input.
const result_hash_128_bits = hash128("hello world");

//This function provides a fast and deterministic 64-bit hash for a given string input.
const result_hash_64_bits = hash64("hello world");
```


## Contributing

See the [contributing guide](CONTRIBUTING.md) to learn how to contribute to the repository and the development workflow.

## License

MIT

---

Made with [create-react-native-library](https://github.com/callstack/react-native-builder-bob)
