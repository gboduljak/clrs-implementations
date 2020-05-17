#include "linked-list.h"

typedef struct stack {
  linked_list *s;
} stack;

stack *AllocateStack();
void DeallocateStack(stack *stack);
int StackEmpty(stack *stack);
void Push(stack *stack, int x);
int Pop(stack *stack);