import { StyleSheet, Text, View } from 'react-native';
import { hash128 } from 'react-native-xxhash';

export default function App() {
  const result = hash128('hello world');

  return (
    <View style={styles.container}>
      <Text>Result: {result}</Text>
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    alignItems: 'center',
    justifyContent: 'center',
  },
});
