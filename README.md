# react-native-hashcash

Expo-compatible C++ turbo module for the new architecture which implements SHA-256 based Hashcash algorithm against brute-force

(See [react-native-hashcash-old](https://github.com/tolgaatam/react-native-hashcash-old) for the version for the old architecture)

## Installation

```sh
npm i github:tolgaatam/react-native-hashcash#v0.1.0
```

## Usage

Import async function `calculateHashcash` and execute it with k (difficulty multiplier) and resource identifier

```js
import { calculateHashcash } from 'react-native-hashcash-old'

const result = await calculateHashcash(19, "tolgaatam")

console.log(result) // 1:19:230505:tolgaatam::dwhWzS19EA2rnOes:157149
```

k must be an integer and the resource identifier must be a string.

With the current situation of smartphone chips, k=19 is the highest comfortable difficult multiplier to choose.

It is advisable to not allow colons in the resource identifier. It could make parsing the resulting hashcash string difficult. URL-encoding the resource identifier would be even safer.

## Ceveats

- Only the most recent Hashcash version 1 is supported. 

- Date format only supports yyMMdd. 

- Salt size is not configurable (16 chars fixed).

## Contributing

See the [contributing guide](CONTRIBUTING.md) to learn how to contribute to the repository and the development workflow.

## License

MIT

---

Made with [create-react-native-library](https://github.com/callstack/react-native-builder-bob)

Uses [stbrumme's C++ hashing library](https://github.com/stbrumme/hash-library) for calculating SHA256 hashes
