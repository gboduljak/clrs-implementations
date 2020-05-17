#include "hash-function.h"

// a nice universal hash function inspired by discussion in CLRS 11.3
int LinearCombinationHash(bigint key, int m) {
  int p = 524287; // nice mersenne prime
  int a = 8191;   // another mersenne prime
  int b = 127;    // another mersenne prime
  return ((a * key + b) % p) % m;
}