#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define INITIAL_STACK_CAPACITY  4

struct stack
{
  char *arr;
  int size;
  int capacity;
};

typedef struct stack stack_t; 

void init(stack_t **stack);
void destroy(stack_t **stack);
void stackRealloc(stack_t *stack);

void push(stack_t *stack, char data);
char pop(stack_t *stack);
int getSize(stack_t* stack);
char top(stack_t *stack);
void peek(stack_t *stack);

int main(int argc, char const *argv[])
{
  char *str;
  int strSize;
  str = "]";
  strSize = strlen(str);

  stack_t *stack;

  init(&stack);

  for(int i = 0; i < strSize; i++){
    char currentSymbol = str[i];

    switch (currentSymbol)
    {
    case '(':
      push(stack, currentSymbol);
      break;
    case '{':
      push(stack, currentSymbol);
      break;
    case '[':
      push(stack, currentSymbol);
      break;
    default:
      char opened = 0;
      opened = (currentSymbol == ')') ? '(': opened;
      opened = (currentSymbol == '}') ? '{': opened;
      opened = (currentSymbol == ']') ? '[': opened;
      if((getSize(stack) && opened != top(stack)) || !getSize(stack)){
        printf("invalid\n");
        return 0;
      }
      pop(stack);
      break;
    }
  }


  if(getSize(stack))
    printf("invalid\n");
  else
    printf("valid\n");

  destroy(&stack);

  return 0;
}

void init(stack_t **stack)
{
  stack_t* p;

  p = (stack_t*)malloc(sizeof(stack_t));
  p->size = 0;
  p->capacity = INITIAL_STACK_CAPACITY;

  p->arr = (char*)malloc(p->capacity*sizeof(char));

  *stack = p;
}

void destroy(stack_t **stack)
{
  free((*stack)->arr);
  *stack = 0;
}

void push(stack_t *stack, char data)
{
  stack->arr[stack->size++] = data;
  if(stack->size == stack->capacity)
    stackRealloc(stack);
}

char pop(stack_t *stack)
{
  if(!stack->size)
    return '0';
  stack->size--;
  return stack->arr[stack->size];
}

int getSize(stack_t* stack)
{
  return stack->size;
}

char top(stack_t *stack)
{
  int stackSize = stack->size;
  return stack->arr[--stackSize];
}

void peek(stack_t *stack)
{
  int stackSize, i;

  stackSize = stack->size;

  for(i = 0; i < stackSize; i++)
    printf("%d: %c\n", i, stack->arr[i]);

}

void stackRealloc(stack_t *stack)
{
  int newCapacity;
  char *newArr; 

  newCapacity = 2*stack->capacity;
  newArr = (char*)malloc(newCapacity*sizeof(char));

  int i = stack->size - 1;
  while(i >= 0){
    newArr[i] = stack->arr[i];
    i--;  
  }

  free(stack->arr);
  
  stack->arr = newArr;
  stack->capacity = newCapacity;
}
