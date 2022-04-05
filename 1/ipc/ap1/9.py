# Nome: Gabriel Dos Santos Lima
qtd_positivos = 0
for N in range(6):
  numero = float(input())
  if(numero > 0): qtd_positivos += 1
print(f'{qtd_positivos} valores positivos')