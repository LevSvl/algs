#include "stdio.h"
#include <stdlib.h>
#include "string.h"

#define MAX_LINE  32

void peek(int *arr, int sz);
void mergeSort(int *arr, int size);
int binSearch(int *arr, int size, int dstData);
int binSearchRec(int *arr, int size, int dstData);

int main(int argc, char const *argv[])
{
  if(argc < 2){
    printf("usage: bin_search [size]\n");
    return 1;
  } 

  int n, *arr;

  n = atoi(argv[1]);
  arr = (int*)malloc(sizeof(int)*n);
  
  printf("input %d array elements\n", n);
  
  int i = 0;
  while(i < n && fscanf(stdin, "%d", &arr[i++]) == 1) {;}

  printf("array:\n");
  peek(arr, n);

  printf("sorted array:\n");
  mergeSort(arr, n);
  peek(arr, n);

  int dstData, dstIndex;
  printf("input target data to find:\n");
  scanf("%d", &dstData);

  dstIndex = binSearchRec(arr, n, dstData);

  if (dstIndex < 0)
    printf("not found\n");
  else
    printf("position %d, data %d\n", dstIndex, dstData);

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

int binSearch(int *arr, int size, int dstData)
{
  int low, high, mid;

  low = 0;
  high = size - 1;

  do{
    mid = (high + low) / 2;
    
    int attemp = arr[mid];
    
    if(attemp > dstData)
      high = mid - 1;
    else if(attemp < dstData)
      low = mid + 1;
    else if(attemp == dstData)
      return mid;

  } while (low <= high);
  
  return -1;
}

int binSearchRec(int *arr, int size, int dstData)
{
  int low, high, mid;

  low = 0;
  high = size - 1;

  while (low <= high){
    mid = (high + low) / 2;
    
    int attemp = arr[mid];
    
    if(attemp > dstData)
      return binSearchRec(&arr[0], mid, dstData);
    else if(attemp < dstData)
      return mid + 1 + binSearch(&arr[mid + 1], size - mid, dstData);
    else if(attemp == dstData)
      return mid;

  }
  
  return -1;
}
