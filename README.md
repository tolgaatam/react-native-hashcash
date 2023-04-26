# react-native-hashcash

C++ turbo module with the new arch for implementing SHA-256 based Hashcash algorithm against brute-force

## Installation

```sh
npm i https://github.com/tolgaatam/react-native-hashcash
```

## Usage

Import async function `calculateHashcash` and execute it with k (difficulty multiplier) and user identifier

```js
import { calculateHashcash } from 'react-native-hashcash';

// ...

const result = await calculateHashcash(19, "tolgaatam");
```

k must be an integer and the user identifier must be a string.

## Contributing

See the [contributing guide](CONTRIBUTING.md) to learn how to contribute to the repository and the development workflow.

## License

MIT

---

Made with [create-react-native-library](https://github.com/callstack/react-native-builder-bob)

Uses [stbrumme's C++ hashing library](https://github.com/stbrumme/hash-library) for calculating SHA256 hashes
