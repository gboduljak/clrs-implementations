
#ifndef bucket_h
#define bucket_h
typedef struct bucket {
  double value;
  struct bucket *next;
  struct bucket *previous;
} bucket;

bucket *Append(bucket *source, bucket *target);
bucket *InsertSortBucket(bucket *bucket);
bucket *AllocateBucket();
#endif