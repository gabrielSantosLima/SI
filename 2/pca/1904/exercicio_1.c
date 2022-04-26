#include <stdio.h>
#include <stdbool.h>

#define ORDER 2

int main(){
  int matrix[ORDER][ORDER];
  int row = 0;
  int column = 0;

  for(row = 0; row < ORDER; row++){
    for(column = 0; column < ORDER; column++){
      scanf("%d", &matrix[row][column]);
    } 
  }

  int maior = matrix[0][0];
  int menor = matrix[0][0];

  for(row = 0; row < ORDER; row++){
    for(column = 0; column < ORDER; column++){
      bool isEqual = row == column;
      if (isEqual && (matrix[row][column] > maior)){
        maior = matrix[row][column]; 
      }else if(isEqual && (matrix[row][column] < menor)){
        menor = matrix[row][column]; 
      }
    } 
  }

  printf("O maior numero eh: %d\n", maior);
  printf("O menor numero eh: %d\n", menor);

  return 0;
}