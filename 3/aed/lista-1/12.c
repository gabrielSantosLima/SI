#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct ITEM
{
  int valor;
} ITEM;

typedef struct LISTA
{
  int quantidade;
  ITEM *itens[MAX];
} LISTA;

LISTA *criarLista()
{
  LISTA *lista = (LISTA *)malloc(sizeof(LISTA));
  lista->quantidade = 0;
  int index;
  for (index = 0; index < MAX; index++)
  {
    lista->itens[index] = NULL;
  }
  return lista;
}

ITEM *criarItem(int valor)
{
  ITEM *item = (ITEM *)malloc(sizeof(ITEM));
  item->valor = valor;
  return item;
}

void inserir(LISTA *lista, ITEM *valor)
{
  if (lista->quantidade == MAX)
  {
    printf("Lista cheia.");
    return;
  }
  int index;
  for (index = 0; index < MAX; index++)
  {
    if (lista->itens[index] == NULL)
    {
      lista->itens[index] = valor;
      lista->quantidade++;
      return;
    }
  }
}

void remover(LISTA *lista, int index)
{
  if (index > (MAX - 1) || index < 0)
  {
    printf("Posição inválida.");
    return;
  }
  if (lista->quantidade == 0)
  {
    printf("Lista vazia.");
    return;
  }
  ITEM *aux = lista->itens[index];
  if (aux != NULL)
  {
    free(aux);
    lista->quantidade--;
    lista->itens[index] = NULL;
  }
}

void imprimeLista(LISTA *lista)
{
  int index;
  for (index = 0; index < MAX; index++)
  {
    if (lista->itens[index] != NULL)
    {
      printf("%d: %d\n", index, lista->itens[index]->valor);
    }
  }
}

int main()
{
  LISTA *lista = criarLista();
  inserir(lista, criarItem(2));
  inserir(lista, criarItem(3));
  inserir(lista, criarItem(4));
  inserir(lista, criarItem(5));
  printf("=== LISTA COMPLETA ===\n");
  imprimeLista(lista);
  printf("=== LISTA COMPLETA (Após remoção)===\n");
  remover(lista, 1);
  imprimeLista(lista);
  return 0;
}