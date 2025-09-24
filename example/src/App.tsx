import { StyleSheet, Text, View } from 'react-native';
import { hash128, hash64 } from 'react-native-xxhash';

export default function App() {
  const testString = 'hello world';
  const result64 = hash64(testString);
  const result128 = hash128(testString);

  return (
    <View style={styles.container}>
      <Text style={styles.text}>Test String: {testString}</Text>
      <Text style={styles.text}>Hash64: {result64}</Text>
      <Text style={styles.text}>Hash128: {result128}</Text>
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    alignItems: 'center',
    justifyContent: 'center',
    backgroundColor: '#fff',
  },
  text: {
    fontSize: 16,
    color: '#333',
    marginBottom: 10,
  },
});
