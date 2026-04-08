import { StyleSheet, Text, View } from 'react-native';
import { hash128, hash64 } from 'react-native-xxhash';

export default function App() {
  const res_128 = hash128('hello world');
  const res_64 = hash64('hello world');

  return (
    <View style={styles.container}>
      <View style={{ flexDirection: 'row' }}>
        <Text style={{ flex: 1, fontWeight:'bold' }}>xxhash 128:</Text>
        <Text>{res_128}</Text>
      </View>
      <View style={{ flexDirection: 'row' }}>
        <Text style={{ flex: 1, fontWeight:'bold' }}>xxhash 64:</Text>
        <Text>{res_64}</Text>
      </View>
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    paddingHorizontal: 20,
    justifyContent: 'center',
  },
});
