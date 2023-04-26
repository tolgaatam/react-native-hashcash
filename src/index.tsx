const Hashcash = require('./NativeHashcash').default;

export function calculateHashcash(k: number, identifier: string): Promise<string> {
  return Hashcash.calculateHashcash(k, identifier);
}
