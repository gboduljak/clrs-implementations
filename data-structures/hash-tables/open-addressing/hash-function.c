#include "hash-function.h"

bigint KeyLinearCombinationHash(bigint key) {
  bigint p = 524287; // nice mersenne prime
  bigint a = 8191;   // another mersenne prime
  bigint b = 127;    // another mersenne prime
  return (a * key + b) % p;
}

int KeyLinearCombinationHash2(int i, int m) {
  int p = 227832; // nice mersenne prime
  int a = 6987;   // another mersenne prime
  int b = 2203;   // another mersenne prime
  bigint poly = a * i;
  return ((poly + b) % p) % m;
}

int ProbeSequenceHash(bigint k, int i, int m) {
  return (KeyLinearCombinationHash(k) + i * KeyLinearCombinationHash2(k, m)) %
         m;
}