import * as React from 'react';
import { useEffect, useState } from 'react';

import { StyleSheet, View, Text, ActivityIndicator, Button } from 'react-native';
import {calculateHashcash} from 'react-native-hashcash';

export default function App() {

  let [time, setTime] = useState(0);
  let [result, setResult] = useState('');
  let [animating, setAnimating] = useState(true);

  const start = async () => {
    setTimeout(async ()=>{
      const now = new Date();
      const result = await calculateHashcash(19, "example");
      const then = new Date();

      setTime(then.getTime() - now.getTime());
      setResult(result);
      setAnimating(false);
    }, 200);
  }

  const retry = () => {
    setTime(0);
    setResult('');
    setAnimating(true);
    start().then(()=>{}).catch(()=>{});
  }

  useEffect(()=>{
    start().then(()=>{}).catch(()=>{});
  }, [])

  return (
    <View style={styles.container}>
      <ActivityIndicator animating={animating} size={32} color={'rgb(60,200,130)'}/>
      <Text>{result}</Text>
      <View style={styles.divider}/>
      <Text>Time Elapsed: {time}ms</Text>
      <View style={styles.divider}/>
      <Button title="Retry" onPress={retry} disabled={animating}/>
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    alignItems: 'center',
    justifyContent: 'center',
    paddingHorizontal: 8,
  },
  divider: {
    height: 12,
  },
});
