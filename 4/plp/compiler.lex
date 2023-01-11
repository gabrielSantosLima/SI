%{
    /* Exemplo de uso do Flex */
%}

DIGITO              [0-9]
NUMERO              [0-9]+(\.[0-9])
PALAVRA             [a-zA-Z]+
IDENTIFICADOR       [a-zA-Z][a-zA-Z0-9]+
BRANCO              [\n\t]

%%
{DIGITO}            printf("Voce escreveu um digito: \"%s\"\n", yytext);
{PALAVRA}           printf("Voce escreveu uma palavra: \"%s\"\n", yytext);
{IDENTIFICADOR}     printf("Voce escreceu um identificador: \"%s\"\n", yytext);
{BRANCO}            printf("Voce escreceu um espaço em branco: \"%s\"\n", yytext);
{NUMERO}            printf("Voce escreceu um numero: \"%s\"\n", yytext);
;                   printf("Voce escreceu um ponto e virgula: \"%s\"\n", yytext);
.                   printf("Não reconhecido: \"%s\"\n", yytext);
%%

int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        printf("Missing input file\n"); exit(-1);
    }
    yyin = fopen(argv[1], "r");
    yylex();
}