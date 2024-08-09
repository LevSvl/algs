#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void peek(int *arr, int sz);
void mergeSort(int *arr, int size);

int main(int argc, char const *argv[])
{
  if(argc < 2){
    printf("usage: rec_sort [size]\n");
    return 1;
  }
  
  int n, *arr;

  n = atoi(argv[1]);
  arr = (int*)malloc(n*sizeof(int));

  printf("input %d nums\n", n);

  for(int i = 0; i < n; i++)
    scanf("%d", &arr[i]);

  peek(arr, n);

  mergeSort(arr, n);

  peek(arr, n);

  free(arr);

  return 0;
}

void peek(int *arr, int sz)
{
  for(int i = 0; i < sz; i++)
    printf("%d\t", arr[i]);
  printf("\n");
}

void mergeSort(int *arr, int size) 
{
  if(size <= 1)
    return;
  
  int mid, *left, *right;
  int i, j, k;

  mid = size / 2;
  left = (int*)malloc(mid*sizeof(int));
  right = (int*)malloc((size-mid)*sizeof(int));

  memcpy(left, arr, sizeof(int)*mid);
  memcpy(right, arr+mid, sizeof(int)*(size-mid));  
  
  
  mergeSort(left, mid);
  mergeSort(right, size - mid);

  i = j = k = 0;

  while(i < mid && j < size - mid){
    if (left[i] < right[j])
      arr[k] = left[i++];
    else
      arr[k] = right[j++];
    
    k++;
  }

  while (i < mid)
    arr[k++] = left[i++];
  
  while (j < size - mid)
    arr[k++] = right[j++];

  free(left);
  free(right);
}