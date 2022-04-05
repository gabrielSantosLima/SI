// Aluno: Gabriel Dos Santos Lima
// Martícula: 2115310010
// Sistemas de Informação - PCA
#include <stdio.h>
#include <stdbool.h>

int main(){
  int number = 0;
  int currentRangeOfZero = 0;
  int maxRangeOfZero = 0;

  printf("Digite um número: ");
  scanf("%d", &number);

  int dividend = number;
  bool inTheRange = false;

  while(dividend != 0){
    int quotient = dividend / 2;
    int bit = dividend % 2;

    if (inTheRange && bit == 1){
      if (currentRangeOfZero > maxRangeOfZero){
        maxRangeOfZero = currentRangeOfZero;
      }
      inTheRange = false;
    }
    if(!(inTheRange) && bit == 1){
      currentRangeOfZero = 0;
      inTheRange = true;
    }
    if(inTheRange && bit == 0){
      currentRangeOfZero++;
    }

    dividend = quotient;
  }

  printf("O maior intervalo de 0s tem comprimento %d\n", maxRangeOfZero);
  return 0;
}