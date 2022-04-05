// Nome: Gabriel Dos Santos Lima
// Matrícula: 2115310010
#include <stdio.h>
#include <stdbool.h>

int main(){
  int numero = 0, counter = 0;
  scanf("%d", &numero);

  int sequenciaFibonacci[numero];

  printf("Primeiros %d termos da sequência de fibonacci:\n", numero);

  for(counter = 0; counter < numero; counter++){
    if(counter == 0 || counter == 1){
      sequenciaFibonacci[counter] = 1;
    }else{
      int primeiroNumero = sequenciaFibonacci[counter - 2];
      int segundoNumero = sequenciaFibonacci[counter - 1];

      sequenciaFibonacci[counter] = primeiroNumero + segundoNumero;
    }
    printf("%d\n", sequenciaFibonacci[counter]);
  }

  printf("Número primos:\n");

  for(counter = 0; counter < numero; counter++){
    int numeroFibonacci = sequenciaFibonacci[counter];
    
    if (counter == 0 || counter == 1){
      continue;
    }

    bool ePrimo = true;
    int antecessor = 0;

    for (antecessor = numeroFibonacci - 1; antecessor >= 2; antecessor--){
      if((numeroFibonacci % antecessor) == 0){
        ePrimo = false;
        break;
      }
    }

    if (ePrimo){
      printf("%d\n", numeroFibonacci);
    }

  }

  return 0;
}