typedef struct cut_rod_result {
  int *r;
  int *s;
} cut_rod_result;

int MemoisedCutRod(int *p, int n);
int BottomUpCutRod(int *p, int n);
cut_rod_result ExtendedBottomUpCutRod(int *p, int n);
void PrintCutRodSolution(int *p, int n);