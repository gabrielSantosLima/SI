// Nome: Gabriel Dos Santos Lima
// Matrícula: 2115310010
#include <stdio.h>
#include <stdbool.h>

#define PEDRA 1
#define PAPEL 2
#define TESOURA 3

int main(){
  bool estaJogando = true;

  printf("\n==== Pedra, Papel e Tesoura ====\n");
  while(estaJogando){
    int jogador1 = -1, jogador2 = -1;
    
    printf("=== VEZ DO JOGADOR 1 ===\n");
    printf("1. Pedra\n");
    printf("2. Papel\n");
    printf("3. Tesoura\n");
    printf("0. Sair do jogo\n");
    printf("Escolha uma das opções [0..3]: ");
    scanf("%d", &jogador1);
    
    if(jogador1 == 0){
      estaJogando = false;
      continue;
    }

    printf("=== VEZ DO JOGADOR 2 ===\n");
    printf("1. Pedra\n");
    printf("2. Papel\n");
    printf("3. Tesoura\n");
    printf("0. Sair do jogo\n");
    printf("Escolha uma das opções [0..3]: ");
    scanf("%d", &jogador2);
    
    if(jogador2 == 0){
      estaJogando = false;
      continue;
    }

    if((jogador1 == PEDRA) && (jogador2 == TESOURA)){
      printf("\n*** RESULTADO: JOGADOR 1 VENCEU!! ***\n");
    }else if((jogador1 == TESOURA) && (jogador2 == PAPEL)){
      printf("\n*** RESULTADO: JOGADOR 1 VENCEU!! ***\n");
    }else if((jogador1 == PAPEL) && (jogador2 == PEDRA)){
      printf("\n*** RESULTADO: JOGADOR 1 VENCEU!! ***\n");
    }else if((jogador2 == PEDRA) && (jogador1 == TESOURA)){
      printf("\n*** RESULTADO: JOGADOR 2 VENCEU!! ***\n");
    }else if((jogador2 == TESOURA) && (jogador1 == PAPEL)){
      printf("\n*** RESULTADO: JOGADOR 2 VENCEU!! ***\n");
    }else if((jogador2 == PAPEL) && (jogador1 == PEDRA)){
      printf("\n*** RESULTADO: JOGADOR 2 VENCEU!! ***\n");
    }else{
      printf("\n*** RESULTADO: EMPATE ***\n");
    }
  }
  return 0;
}