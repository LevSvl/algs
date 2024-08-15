#include "stdio.h"
#include "stdlib.h"

// O(n^2)

#define N 5
#define M 4

void randMatr(int matr[N][M]);
void printMatr(int matr[N][M]);

int main(int argc, char const *argv[])
{
  int matr[N][M];

  randMatr(matr);
  printMatr(matr);
  printf("\n\n");

  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      if(matr[i][j] > 0)
        continue;
      
      for(int k = 0; k < M; k++)
        matr[i][k] = 0;
      
      for(int k = 0; k < N; k++)
        matr[k][j] = 0;

    }
  }
  printMatr(matr);

  return 0;
}

void randMatr(int matr[N][M])
{
  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      matr[i][j] = rand() % 2;
    }
  }
}
void printMatr(int matr[N][M])
{
  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      printf("%4d", matr[i][j]);
    }
    printf("\n");
  }
}