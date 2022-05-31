#include <stdio.h>
#include <stdbool.h>

// Aluno: Gabriel dos Santos Lima
// Matrícula: 2115310010

#define SIZE 5

bool verificaSeEPermutacao(int *lista){
  int counter = 0, counter2 = 0;
  for(counter = 0; counter < SIZE; counter++){
    for(counter2 = 0; counter2 < SIZE; counter2++){
      if(counter != counter2 && lista[counter] == lista[counter2]){
        return false;
      }    
    }
    if(lista[counter] > SIZE || lista[counter] < 1){
      return false;
    }   
  }
  return true;
}

int main(){
  int lista[SIZE], counter = 0;
  bool ePermutacao = true;
  printf("Digite a sequencia de numeros:\n");
  for(counter = 0; counter < SIZE; counter++){
    scanf("%d", &lista[counter]);
  }
  ePermutacao = verificaSeEPermutacao(lista);
  if(ePermutacao){
    printf("Eh permutacao.");
  }else{
    printf("Nao eh permutacao.");
  }
  return 0;
}