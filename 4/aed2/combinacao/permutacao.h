#ifndef PERMUTACAO_FILE
#define PERMUTACAO_FILE
#include "fatorial.h"
#include "string.h"

void permutacao_string(string text);
int permutacao_simples(int n);
int permutacao_com_repeticao(int n, int *elementos, int k);
int permutacao_circular(int n);

#endif