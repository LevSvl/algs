#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"

void peek(int *arr, int sz);
int maxSubsetSum(int *arr, int sz);

int main(int argc, char const *argv[])
{
  int n;
  printf("input set size: ");
  scanf("%d", &n);
  
  if (n <= 0)
    return 1;

  int i, *subset;

  subset = (int*)malloc(sizeof(int)*n);
  
  printf("input set elements: ");
  i = 0;
  while(i < n) 
    fscanf(stdin, "%d", &subset[i++]);

  printf("set: \n");
  peek(subset, n);

  printf("max subset sum: %d\n", maxSubsetSum(subset, n));

  return 0;
}

void peek(int *arr, int sz)
{
  for(int i = 0; i < sz; i++)
    printf("%d\t", arr[i]);
  printf("\n");
}

int maxSubsetSum(int *arr, int sz)
{
  int min, max;
  int sum;
  
  sum = 0;
  min = max = arr[0];

  for(int i = 0; i < sz; i++){
    min = (arr[i] < min) ? arr[i] : min; 
    max = (arr[i] > max) ? arr[i] : max; 
  }

  if(min <= 0)
    min = 1;

  while(max >= min){
    sum += max--;
  }

  return sum;
}
