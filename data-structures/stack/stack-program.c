#include "stack.h"
#include "stdio.h"

int main() {
  stack *s = AllocateStack(10);
  Push(s, 1);
  Push(s, 2);
  Push(s, 3);
  int empty = StackEmpty(s);
  while (!empty)
    printf("%d \n", Pop(s)), empty = StackEmpty(s);
  DeallocateStack(s);
  return 0;
}