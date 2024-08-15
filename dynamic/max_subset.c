#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"

// максимальное число в подмножестве - индекс в массиве nums
#define MAX_SUBSET_INT INT16_MAX

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

void __initNums(int* nums)
{
  for(int i = 0; i < MAX_SUBSET_INT; i++)
    nums[i] = 0;
}

int maxSubsetSum(int *arr, int sz)
{
  int sum, nums[MAX_SUBSET_INT];

  __initNums(nums);
  sum = 0;

  for(int i = 0; i < sz; i++){
    if(arr[i] > INT16_MAX)
      continue;

    if(arr[i] > 0 && !(nums[arr[i]]++))
      sum += arr[i];
  }

  return sum;
}
