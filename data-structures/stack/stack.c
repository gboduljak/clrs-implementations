#include "stack.h"
#include <stdlib.h>

stack *AllocateStack(int size) {
  stack *new = (stack *)malloc(sizeof(stack));
  new->S = malloc(sizeof(int) * size);
  new->top = -1;
  new->size = size;
  return new;
}
void DeallocateStack(stack *stack) {
  free(stack->S);
  free(stack);
}

int StackEmpty(stack *stack) { return stack->top == -1; }

void Push(stack *stack, int x) {
  stack->top++;
  stack->S[stack->top] = x;
}

int Pop(stack *stack) {
  stack->top--;
  return stack->S[stack->top + 1];
}