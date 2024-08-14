#include "stdio.h"

#define SYMBOLS_LEN 128
int chars[SYMBOLS_LEN];

int main(int argc, char const *argv[])
{
  if (argc < 2){
    printf("Usage: unique_str [string_value]");
    return 1;
  }

  char* str;
  str = argv[1];
  
  // for(int i = 0; i < strlen(str) - 1; i++)
  //   if(chars_arr[str[i]]++){
  //     printf("not unique\n");
  //     return 0;
  //   }

  int l, r;

  l = 0;
  r = strlen(str) - 1;

  while(l <= r){
    if(l!=r && chars[str[l++]]++){
      printf("not unique\n");
      return 1;
    }

    if(chars[str[r--]]++){
      printf("not unique\n");
      return 1;
    }
  }
  printf("unique\n");
  
  return 0;
}
