LINHAS = 3
COLUNAS = 2

def calcula_transposta(matriz):
  matriz_transposta  = []
  for i in range(COLUNAS):
    for j in range(LINHAS):
      if len(matriz_transposta) < i + 1:
        matriz_transposta.append([matriz[j][i]])
      else:
        matriz_transposta[i] += [matriz[j][i]]
  return matriz_transposta

matriz = []

for i in range(LINHAS):
  for j in range(COLUNAS):
    valor = int(input(f"Digite o valor (i = {i} e j = {j}):"))
    if len(matriz) < i + 1:
      matriz.append([valor])
    else:
      matriz[i] += [ valor ]

print(f"\n=========================")
print(f"Matriz original: {matriz}")
print(f"Matriz transposta: {calcula_transposta(matriz)}")
print(f"=========================")