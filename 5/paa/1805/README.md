# PAA

## Análise Assintótica

Montar a fórmula de custo baseado em:

- Atribuições (1)
- Leitura de valores (1)
- Operações matemáticas (1)
- Comandos de repetição (n)
- Comando de decisão (n)
- Chamada de função (n)

### Regras para análise de custo

- Laços aninhados: realizar a análise de dentro pra fora
- Laços que fazem instruções consecutivas: o custo será sempre o que tiver o maior valor

```c
for(int i = 0; i < 10; i++){
    ...
}
for(int i = 0; i < 10; i++){
    for(int i = 0; i < 10; i++){
        ...
    }
}
```

`O(n) + O(n^2) = O(n^2)`

- Instruções **se,senão**: Vai ter custo de `n`
- Chamadas de funções: Segue mesma regras de laços aninhados. Análise de dentro para fora fazendo
  o cálculo do custo. Considera-se a função que possui maior peso. Para a montagem da fórmula, considera-se a soma dos pesos.
- Funções recursivas: considera a chamada de recursão como uma chamada de função.

> Fazer exercícios de análise assintótica
