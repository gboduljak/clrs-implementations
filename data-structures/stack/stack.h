typedef struct stack {
  int *S;
  int top;
  int size;
} stack;

stack *AllocateStack(int size);
void DeallocateStack(stack *stack);
int StackEmpty(stack *stack);
void Push(stack *stack, int x);
int Pop(stack *stack);