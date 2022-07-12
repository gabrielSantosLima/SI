#include <stdio.h>
#include <stdbool.h>

// Aluno: Gabriel dos Santos Lima
// Matrícula: 2115310010

#define SIZE 6

int completaPermutacao(int *lista){
  int counter = 0, numeroDaSequenciaIdeal = lista[0]; 
  for(numeroDaSequenciaIdeal = lista[0]; numeroDaSequenciaIdeal <= SIZE; numeroDaSequenciaIdeal++){
    bool estaNaSequencia = false;
    for(counter = 0; counter < SIZE - 1; counter++){
      if(numeroDaSequenciaIdeal == lista[counter]){
        estaNaSequencia = true;
      }
    }
    if(!estaNaSequencia){
      return numeroDaSequenciaIdeal;
    }
  }
  return -1;
}

int main(){
  int lista[SIZE-1], counter = 0;
  bool ePermutacao = true;
  printf("Digite a sequencia de numeros:\n");
  for(counter = 0; counter < SIZE - 1; counter++){
    scanf("%d", &lista[counter]);
  }
  printf("Hmmm. Ainda nao eh permutacao.\n");
  int numeroQueFalta = completaPermutacao(lista);
  printf("O numero que estava faltando era: %d. Agora a sequencia eh uma permutacao.", numeroQueFalta);
  return 0;
}