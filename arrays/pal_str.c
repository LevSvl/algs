#include "stdio.h"
#include "string.h"

// O(n)

int main(int argc, char const *argv[])
{
  if (argc < 2){
    printf("Usage: pal_str [string_value]\n");
    return 1;
  }

  const char* str;
  int left, right;

  str = argv[1];

  left = 0;
  right = strlen(str) - 1; // strlen returns position of '0'

  while(left < right){
    if (str[left] != str[right]){
      printf("not palindrome\n");
      return 0;
    }
    left++;
    right--;
  }

  printf("palindrome\n");
  return 0;
}
