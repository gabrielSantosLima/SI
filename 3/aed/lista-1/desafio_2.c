#include <stdio.h>
#include <stdlib.h>
#define TAMANHO_TOTAL 10

typedef struct NODE{
    int conteudo;
    struct NODE* anterior; 
    struct NODE* proximo; 
}NO;

int quantidade = 0;
NO* nos = NULL;

NO* criarNo(int conteudo){
    NO* no = (NO*) malloc(sizeof(NO));
    no->anterior = NULL;
    no->proximo = NULL;
    no->conteudo = conteudo;
    return no;
}

void inserir(int conteudo){
    NO* inicio; 
    NO* novoNo = criarNo(conteudo);
    if(nos == NULL){
        nos = novoNo;
        return;
    }
    inicio = nos;
    while (nos->proximo != NULL){
        nos = nos->proximo;
    }
    novoNo->anterior = nos;
    nos->proximo = novoNo;
    
    quantidade++;
    nos = inicio;
}

void imprimirLista(){
    NO* inicio = nos;
    while (nos != NULL){
        printf("%d ", nos->conteudo);
        nos = nos->proximo;
    }
    nos = inicio;
}

void imprimirListaReversa(){
    NO* inicio = nos;
    while (nos->proximo != NULL){
        nos = nos->proximo;
    }
    while (nos != NULL){
        printf("%d ", nos->conteudo);
        nos = nos->anterior;
    }
    nos = inicio;
}

/*
Problema de Josephus

1. Início com um número n qualquer que corresponde a quantidade de nós que serão pulados.
2. Ao finalizar uma rodada, o último nó deverá ser eliminado e o seu valor será o próximo valor de n da lista.
3. Este processo deverá ser realizado até que reste nenhum nó na lista.
4. O conteúdo do último nó deverá ser apresentado na tela.

## Regras
- Ao chegar no último nó, o algoritmo deve pular para o primeiro nó da lista.
- Loop inicia no nó que é próximo ao nó que foi removido.
*/ 

NO* josephus(int rodadas){
    rodadas--;
    NO* inicio = nos;
    while(rodadas > 0){
        if(nos->proximo == NULL){
            nos = inicio;
        }else{
            nos = nos->proximo;
        }
        rodadas--;
    }

    int proximaRodada;
    printf("%d ", nos->conteudo);

    if(quantidade > 1){
        proximaRodada = nos->conteudo;

        nos->anterior->proximo = nos->proximo;

        if(nos->proximo != NULL){
            nos->proximo->anterior = nos->anterior;
        }

        if(nos->proximo == NULL){
            while(nos->anterior != NULL){
                nos = nos->anterior;
            }
        }else{
            nos = nos->proximo;
        }
        quantidade--;
    }else{
        return nos;
    }
    return josephus(proximaRodada);
}

int main(){
    inserir(5);
    inserir(3);
    inserir(2);
    inserir(4);
    inserir(6);
    inserir(1);
    
    printf("========== LISTA COMPLETA ==========\n");
    imprimirLista();
    printf("\n");
    
    printf("========== PROBLEMA DE JOSEPHUS ==========\n");
    NO* noFinal = josephus(3);
    // printf("%d\n", noFinal->conteudo);

    return 0;
}