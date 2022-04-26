/* 
Aluno: Gabriel Dos Santos Lima
Matrícula: 2115310010

2) Explique a diferença entre os operadores * e & em ponteiros.
*/
#include <stdio.h>

int main(){
  // Operador '&' indica "endereço de" de uma determinada variável
  int x = 10;
  int *p = &x; // Armazendo "endereço de" x
  printf("Endereço de x: %p\n", p);
  
  // Operador '*' indica "valor do conteúdo do endereço de memória" de um ponteiro
  printf("Conteúdo do endereço em p: %d\n", x);

  return 0;
}