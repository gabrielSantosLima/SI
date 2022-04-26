#include <stdio.h>
#include <stdbool.h>

#define ORDER 3

int main(){
  int matrix[ORDER][ORDER];
  int transposeMatrix[ORDER][ORDER];
  int row, column;

  for(row = 0; row < ORDER; row++){
    for(column = 0; column < ORDER; column++){
      scanf("%d", &matrix[row][column]);
    }
  }

  for(row = 0; row < ORDER; row++){
    for(column = 0; column < ORDER; column++){
      transposeMatrix[column][row] = matrix[row][column];
    }
  }

  printf("Matriz Transposta: \n");
  for(row = 0; row < ORDER; row++){
    for(column = 0; column < ORDER; column++){
      printf("%d ", transposeMatrix[row][column]);
    }
    printf("\n");
  }

  return 0;
}