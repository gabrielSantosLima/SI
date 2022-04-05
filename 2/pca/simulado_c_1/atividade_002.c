// Nome: Gabriel Dos Santos Lima
// Matrícula: 2115310010
#include <stdio.h>

int main(){
  int numero = 0, counter = 0;
  scanf("%d", &numero);
  for(counter = 1; counter < numero; counter++){
    if((numero % counter) == 0){
      printf("%d\n", counter);
    }
  }
  return 0;
}