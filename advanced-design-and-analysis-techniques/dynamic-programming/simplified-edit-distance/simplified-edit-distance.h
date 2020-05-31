#define insert 1
#define delete -1
#define replace 0
#define nothing 2

typedef struct edit_distance_result {
  int **dp;
  int **op;
  int ops_required;
} edit_distance_result;

edit_distance_result MinEditOps(char *x, char *y, int m, int n);
void PrintEditSequence(int **op, char *x, char *y, int i, int j, int m, int n);