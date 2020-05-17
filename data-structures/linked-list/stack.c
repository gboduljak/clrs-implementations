#include "stack.h"
#include <stdlib.h>

stack *AllocateStack() {
  stack *new = (stack *)malloc(sizeof(stack));
  new->s = AllocateLinkedList();
  return new;
}

void DeallocateStack(stack *stack) {
  DellocateLinkedList(stack->s);
  free(stack);
}

int StackEmpty(stack *stack) { return stack->s->length == 0; }

void Push(stack *stack, int x) { ListInsert(stack->s, x); }

int Pop(stack *stack) {
  int x = stack->s->nil->next->key;
  ListDelete(stack->s, stack->s->nil->next);
  return x;
}