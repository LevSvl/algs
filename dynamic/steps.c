#include "stdio.h"
#include "stdlib.h"

int steps(int n);
int steps_rec(int n);

int main(int argc, char const *argv[])
{
  if(argc < 2){
    printf("usage: steps [n]\n");
    return 1;
  } 

  int n = atoi(argv[1]);

  printf("n = %d, steps = %d\n", n, steps(n));
  printf("n = %d, steps = %d\n", n, steps_rec(n));
  
  return 0;
}

int steps_rec(int n)
{
  if(n <= 0)
    return 0;
  if(n == 1)
    return 1;
  if(n == 2)
    return 2;
  if(n == 3)
    return 4;

  return steps_rec(n - 1) + steps_rec(n - 2) + steps_rec(n - 3);
}

int steps(int n) 
{
  int l1 = 1, l2 = 2, l3 = 4;

  if(n == 1)
    return l1;
  if(n == 2)
    return l2;
  if(n == 3)
    return l3;

  int l4 = 0;

  for(int i = 4; i <= n; i++){
    l4 = l1 + l2 + l3;
    
    l1 = l2;
    l2 = l3;
    l3 = l4;
  }

  return l4;
}