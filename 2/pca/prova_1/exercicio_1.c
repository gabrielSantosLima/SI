// Aluno: Gabriel Dos Santos Lima
// Martícula: 2115310010
// Sistemas de Informação - PCA
#include <stdio.h>
#include <stdbool.h>

int main(){
  int count = 0;
  int a1 = 0;
  int n = 0;
  int r = 0;

  printf("Digite o primeiro termo: ");
  scanf("%d", &a1);
  printf("Digite o numero de termos: ");
  scanf("%d", &n);
  printf("Digite a razao: ");
  scanf("%d", &r);

  int an = a1 + r * n - r;

  printf("O enesimo termo da P.A. eh: %d\n", an);

  bool ePrimo = true;

  for(count = 1; count < an; count++){
    if((count != 1) && (an % count == 0)){
      ePrimo = false;
    }
  }

  if(ePrimo){
    printf("%d eh primo\n", an);
  }else{
    printf("%d não eh primo\n", an);
  }

  return 0;
}