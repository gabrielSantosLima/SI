matriz = []
ORDEM = 7

for i in range(ORDEM):
  for j in range(ORDEM):
    valor = int(input(f"Digite o valor (i = {i} e j = {j}):"))
    if len(matriz) < i + 1:
      matriz.append([valor])
    else:
      matriz[i] += [ valor ]

linha = int(input("Digite a linha desejada:"))
print(f"Linha: {','.join(matriz[linha - 1])}")