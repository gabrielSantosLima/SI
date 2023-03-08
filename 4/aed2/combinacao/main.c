#include <stdio.h>
#include "combinacao.h"
#include "arranjo.h"
#include "permutacao.h"
#include "string.h"

int main()
{
    // char palavra[] = "VVVVAAAaaV";
    // permutacao_string(palavra);
    int numeros[] = {1, 2, 3, 4, 5};
    int n = sizeof(numeros) / sizeof(numeros[0]);
    // int p = 3;
    // combinacao_int(numeros, n, p);
    printf("%d", fat(3) * fat(2) + (fat(1) + fat(2) + fat(3) + fat(4) + fat(5)));

    // printf("%d", 12 * 5 * fat(5));
    return 0;
}