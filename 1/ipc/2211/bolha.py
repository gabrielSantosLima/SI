ORDEM = 3

def bubble_sort(array):
  tamanho_total = len(array)

  for i in range(tamanho_total - 1):
    trocou = False
    for j in range(tamanho_total - 1 - i):
      if array[j] > array[j + 1]:
        trocou = True
        array[j], array[j + 1] = array[j + 1], array[j]
    if not trocou:
      break

def ordena_linhas_de_uma_matriz(matriz):
  matriz_ordenada = matriz.copy()
  for linha in matriz_ordenada:
    bubble_sort(linha)
  return matriz_ordenada

matriz = []

for i in range(ORDEM):
  for j in range(ORDEM):
    valor = int(input(f"Digite o valor (i = {i} e j = {j}):"))
    if len(matriz) < i + 1:
      matriz.append([valor])
    else:
      matriz[i] += [ valor ]

print(f"\n=========================")
print(f"Matriz original: {matriz}")
print(f"Matriz ordenada: {ordena_linhas_de_uma_matriz(matriz)}")
print(f"=========================")