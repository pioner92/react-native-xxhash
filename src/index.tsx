import {NativeModules} from 'react-native'
declare global {
  var __xxhash128: (input: string) => string;
  var __xxhash64: (input: string) => string;
}


let xxhashModule = globalThis.__xxhash128;

if(!xxhashModule){
  if(NativeModules.xxhash){
    NativeModules.xxhash.install();
    xxhashModule = globalThis.__xxhash128;
    console.log('✅ xxhash initialized successfully')
  }
}


/**
 * Hashes the input string using the xxhash128 algorithm.
 * This function provides a fast and deterministic 128-bit hash for a given string input.
 * 
 * @param {string} input - The string to hash.
 * @returns {string} The hashed string as a hexadecimal representation of the 128-bit hash.
 * @throws {Error} If the input is not provided.
 * @throws {Error} If the input is not of type string.
 * 
 * @example
 * const result = hash128("hello world");
 * console.log(result); // Example output: "3a2b9e6a2b5e7e5a9e6a2b5e7e5a2a2"
 * 
 * @description
 * This function uses the xxhash128 algorithm, which provides a larger hash size (128-bit) compared to xxhash64.
 * It is ideal for scenarios where a reduced collision risk is critical, such as in distributed systems or when hashing larger datasets.
 */
 export const hash128 = (input: string): string => {
  if(!input){
    throw new Error('Input is required');
  }

  if(typeof input !== 'string'){
    throw new Error('Input must be a string');
  }

  return globalThis.__xxhash128(input);
 }   

/**
 * Hashes the input string using the xxhash64 algorithm.
 * This function provides a fast and deterministic 64-bit hash for a given string input.
 * 
 * @param {string} input - The string to hash.
 * @returns {string} The hashed string as a hexadecimal representation of the 64-bit hash.
 * @throws {Error} If the input is not provided.
 * @throws {Error} If the input is not of type string.
 * 
 * @example
 * const result = hash64("hello world");
 * console.log(result); // Example output: "9e6a2b5e7e5a2a2e"
 * 
 * @description
 * This function uses the xxhash64 algorithm, known for its high performance and low collision rate.
 * It is ideal for hashing small to medium-sized strings.
 */

 export const hash64 = (input: string): string => {
  if(!input){
    throw new Error('Input is required');
  }

  if(typeof input !== 'string'){
    throw new Error('Input must be a string');
  }

  return globalThis.__xxhash64(input);
 }   