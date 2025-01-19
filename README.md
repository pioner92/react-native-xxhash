# react-native-xxhash

A React Native library for hashing strings using the fast and deterministic xxHash algorithm, written in C++ with JSI for high performance. This library provides support for both 64-bit and 128-bit hashing.


## Features

- **High Performance**: xxHash is one of the fastest non-cryptographic hash functions.
- **Deterministic Hashing**: Ensures consistent results for the same input.
- **128-bit and 64-bit Support**: Choose between 128-bit and 64-bit hash outputs based on your use case.
- **Cross-Platform**: Supports both iOS and Android in React Native projects.

## Installation

To install the library, use either `npm` or `yarn`:

```sh
npm install react-native-xxhash
```

```sh
yarn add react-native-xxhash
```

## iOS
```sh
pod install
```

---

## Usage

Here’s how to use the `react-native-xxhash` library in your React Native project:

### Import the Functions
```javascript
import { hash128, hash64 } from 'react-native-xxhash';
```

### Hash a String (128-bit)
This function generates a fast and deterministic 128-bit hash for a given string input.

```javascript
const resultHash128 = hash128("hello world");
console.log('128-bit hash:', resultHash128);
// Output: A 128-bit hash string
```

### Hash a String (64-bit)
This function generates a fast and deterministic 64-bit hash for a given string input.

```javascript
const resultHash64 = hash64("hello world");
console.log('64-bit hash:', resultHash64);
// Output: A 64-bit hash string
```

### Example Usage in a Component
```javascript
import React, { useEffect } from 'react';
import { Text, View } from 'react-native';
import { hash128, hash64 } from 'react-native-xxhash';

const App = () => {
  useEffect(() => {
    const hash128Result = hash128("react-native");
    const hash64Result = hash64("react-native");

    console.log("128-bit hash:", hash128Result);
    console.log("64-bit hash:", hash64Result);
  }, []);

  return (
    <View style={{ flex: 1, justifyContent: 'center', alignItems: 'center' }}>
      <Text>Check your console for hash results!</Text>
    </View>
  );
};

export default App;
```

---

## API Reference

### `hash128(input: string): string`
- **Description**: Generates a 128-bit hash for the given string input.
- **Parameters**:
  - `input` (string): The string to hash.
- **Returns**: A 128-bit hash as a string.

### `hash64(input: string): string`
- **Description**: Generates a 64-bit hash for the given string input.
- **Parameters**:
  - `input` (string): The string to hash.
- **Returns**: A 64-bit hash as a string.

---

## License

`react-native-xxhash` is released under the MIT License. See the [LICENSE](LICENSE) file for details.
