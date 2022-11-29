# Aula do dia 12/09/2022

## Árvore

- Um conjunto finito de elementos.
- Cada elemento da árvore é chamado de **nó** e o nó principal é chamado de **raiz**.
- Associção de um **pai** para com seus **filhos**
- Grau: é um **número de sub-árvores** de um nó.
- Folha: nó que possui grau 0.
- Nível: número de nós existentes entre a raiz e este nó, incluíndo o próprio nó.
- Altura: distância do nó com maior nível até a raiz.

---

## Árvore Binária

- Árvore de **grau 2**.
- Cada nó possui 0, 1 ou 2 filhos (filho esquerdo e filho direito).

### Árvore estritamente binária

- Árvore binária que possui nós **apenas com 0 ou 2 filhos**.

### Árvore binária cheia

- Árvore binária que possui nós com **0 filhos somente no último nível**.

### Árvore binária completa

- Árvore binária que possui nós com **0 filhos somente no último ou penúltimo nível**.

---

## Árvore Binária de Busca (ou pesquisa)

- Árvore binária em que todos os elementos **menores ficarão a esquerda** e todos os elementos
  **maiores ficarão a direita**.
- Percursos principais:
  - Pré-fixado ou pré-ordem: **Raiz** -> Esquerda -> Direita
  - Central ou in-fixado ou in-ordem: Esquerda -> **Raiz** -> Direita
  - Pós-fixado ou pós-ordem: Esquerda -> Direita -> **Raiz**

---

## Resumo

| Percurso      | Direção | Direção | Direção |
| ------------- | ------- | ------- | ------- |
| **Pré-ordem** | **R**   | E       | D       |
| **In-ordem**  | E       | **R**   | D       |
| **Pós-ordem** | E       | D       | **R**   |

# Aula do dia 21/09/2022

## Árvore AVL

- Possui um fator de balanceamento
- Fator de balancemento: **Altura da sub-árvore da direita** - **Altura da sub-árvore da esquerda**
- Para que uma árvore esteja balanceada, **|fator de balanceamento| < 2**

### Lidando com o desbalanceamento

- Quando uma árvore ficar desbalanceada precisamos:
  - Buscar o primeiro ancestral com fator de desbalanceamento != 0 (A)
  - Encontra seu filho na direção da inserção (B)
  - B vira pai de A

| Tipo de Rotação                       | A   | B   |
| ------------------------------------- | --- | --- |
| RSE (Rotação simples para a esquerda) | +   | +   |
| RSD (Rotação simples para a direita)  | -   | -   |
| RDE (Rotação dupla para a esquerda)   | +   | -   |
| RDD (Rotação dupla para a direita)    | -   | +   |

> RDE = RSD + RSE
>
> RDD = RSE + RSD

## Árvore Rubro-negras

- É uma árvore binária de busca
- As regras são:
  - Cada nó tem duas cores: **vermelho** e **preto**
  - A raiz é **preta**
  - Cada folha é **preta**
  - Nós vermelhos possuem apenas **nós pretos**
  - Nós pretos possuem **nós pretos** e **nós vermelhos**
  - A partir de cada nó x, temos **a mesma quantidade de nós pretos por todos os caminhos até as suas folhas (contando com NULL)**

### Balanceamento

- 1-5 garantem que a árvore esteja **aproximadamente balanceada**

```c
struct NODE{
  char color;
  int value;
  struct NODE* left;
  struct NODE* right;
  struct NODE* parent;
};
```

## Desafio - 28/09/2022

- Escolher 12 número e inserir
- Escolher uma árvore pronta e remover 4 elementos
