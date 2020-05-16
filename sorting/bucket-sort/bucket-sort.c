#include "bucket-sort.h"
#include "bucket.h"
#include "math.h"
#include "stdio.h"
#include "stdlib.h"
int Hash(double element, int n) { return (int)floor(n * element); }

bucket *Bucketify(double element) {
  bucket *bucket = AllocateBucket();
  bucket->value = element;
  return bucket;
}

void BucketSort(double *A, int length) {
  int n = length, i, k;

  bucket **buckets = malloc(sizeof(bucket *) * length);
  for (i = 0; i < n; i++)
    buckets[i] = NULL;
  for (i = 0; i < n; i++)
    buckets[Hash(A[i], n)] = Append(buckets[Hash(A[i], n)], Bucketify(A[i]));
  for (i = 0; i < n; i++)
    buckets[i] = InsertSortBucket(buckets[i]);

  k = -1;
  for (i = 0; i < n; i++) {
    bucket *bucket = buckets[i];
    while (bucket)
      A[++k] = bucket->value, bucket = bucket->next;
    DestroyRecursively(bucket);
  }
  free(buckets);
}