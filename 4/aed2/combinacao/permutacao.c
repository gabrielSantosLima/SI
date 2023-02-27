#include "permutacao.h"

int permutacao_simples(int n)
{
    return fat(n);
}

int permutacao_com_repeticao(int n, int *elementos, int k)
{
    int permutacoes = 1;
    for (int index = 0; index < k; index++)
        permutacoes *= fat(elementos[index]);
    return fat(n) / permutacoes;
}

int permutacao_circular(int n)
{
    return fat(n) / n;
}

void troca_char(string str, int p1, int p2)
{
    char tmp;
    tmp = str[p1];
    str[p1] = str[p2];
    str[p2] = tmp;
}

void permutacao_recursiva(string str, int k)
{
    int i, len;
    len = strlen(str);

    if (k == len)
        printf("%s\n", str);
    else
    {
        for (i = k; i < len; i++)
        {
            troca_char(str, k, i);
            permutacao_recursiva(str, k + 1);
            troca_char(str, i, k);
        }
    }
}

void permutacao_string(string str)
{
    permutacao_recursiva(str, 0);
}