#include <stdio.h>
#include <stdbool.h>

#define SIZE 5

// Aluno: Gabriel dos Santos Lima
// Matrícula: 2115310010

int menorInteiroPositivoDe(int *lista){
  int counter = 0;
  int menorInteiro = 0;
  for(counter = 0; counter < SIZE; counter++){
    if(lista[counter] < menorInteiro){
      menorInteiro = lista[counter];
    }
  }
  int menorInteiroPositivo = menorInteiro + 1;
  bool valorFoiEncontrado = true;
  while(valorFoiEncontrado){
    bool existe = false;
    for(counter = 0; counter < SIZE; counter++){
      if(menorInteiroPositivo == lista[counter] || menorInteiroPositivo <= 0){
        existe = true;
      }
    }
    if(existe){
      menorInteiroPositivo++;
      valorFoiEncontrado = true;
    }else{
      valorFoiEncontrado = false;
    }
  }
  return menorInteiroPositivo;
}

int main(){
  int lista[SIZE], counter = 0;
  printf("Digite a sequencia de numeros:\n");
  for(counter = 0; counter < SIZE; counter++){
    scanf("%d", &lista[counter]);
  }
  int menorInteiroPositivo = menorInteiroPositivoDe(lista);
  printf("O menor inteiro positivo desta sequencia eh: %d\n", menorInteiroPositivo);
  return 0;
}