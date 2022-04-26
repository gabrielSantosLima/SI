/*
Aluno: Gabriel Dos Santos Lima
Matrícula: 2115310010

1) Crie um programa em C que declare uma variável do tipo float e um ponteiro do tipo float. 
Faça o ponteiro criado apontar para a variável declarada e altere o valor da variável 
utilizando o ponteiro.
*/
#include <stdio.h>

int main(){
  float number = 10.0;
  
  printf("Current number value: %f\n", number);
  
  float *pointer = &number;
  *pointer = 11.0;

  printf("Current number value: %f\n", number);

  return 0;
}