#include "math.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define infinity 9223372036854775807
int N, M;

char **words;
int *word_lengths;
unsigned long long *badness;
int *break_word;

unsigned long long neatest_print_from(int i) {
  if (i >= N)
    return 0;
  if (badness[i] != infinity)
    return badness[i];

  int k;
  int last_word_first_line = 0;
  int words_in_line_length;
  unsigned long long first_line_badness;
  for (k = i; k < N && words_in_line_length <= M; k++)
    words_in_line_length += word_lengths[k];
  int line_length = N - i - 1 + words_in_line_length;

  if (line_length <= M) // base case
  {
    badness[i] = 0;
    break_word[i] = N - 1;
    return badness[i];
  }

  words_in_line_length = 0;
  first_line_badness = 0;
  for (k = i; k < N; k++) {
    words_in_line_length += word_lengths[k];
    first_line_badness =
        (unsigned long long)pow((M - k + i - words_in_line_length), 2);
    if (first_line_badness + neatest_print_from(k + 1) < badness[i]) {
      badness[i] = first_line_badness + neatest_print_from(k + 1);
      break_word[i] = k;
    }
  }
  return badness[i];
}

void print_neatly(int i) {
  if (i >= N)
    return;
  int j;
  int bw = break_word[i];
  for (j = i; j <= break_word[i]; j++) {
    if (j != break_word[i])
      printf("%s ", words[j]);
    else
      printf("%s", words[j]);
  }
  printf("\n");
  print_neatly(break_word[i] + 1);
}

int main() {
  int i, word_length;
  scanf("%d %d", &N, &M);

  words = (char **)malloc(sizeof(char *) * N);
  word_lengths = (int *)malloc(sizeof(int) * N);
  badness = (unsigned long long *)malloc(sizeof(unsigned long long) * N);
  break_word = (int *)malloc(sizeof(int) * N);

  for (i = 0; i < N; i++) {
    badness[i] = (unsigned long long)infinity;
    scanf("%d", &word_length);
    char *word = malloc(sizeof(char) * (word_length + 1));
    scanf("%s", word);
    words[i] = word;
    word_lengths[i] = word_length;
  }

  neatest_print_from(0);
  print_neatly(0);

  int t = 3;
}