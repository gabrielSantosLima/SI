# Nome: Gabriel Dos Santos Lima
LINHA = 12
COLUNA = 12

def ler_matriz():
  matriz = []
  for i in range(LINHA):
    matriz.append([])
    for j in range(COLUNA):
      matriz[i].append(float(input()))
  return matriz

def pegar_valores_acima_da_diagonal_principal(matriz):
  valores = []
  for i in range(LINHA):
    for j in range(COLUNA):
      if j + i <= 10: valores.append(matriz[i][j])
  return valores


def somar_array():
  matriz = ler_matriz()
  array = pegar_valores_acima_da_diagonal_principal(matriz)
  soma = sum(array)
  return soma

def media_array():
  matriz = ler_matriz()
  array = pegar_valores_acima_da_diagonal_principal(matriz)
  soma = sum(array)
  return float(soma / len(array))

o = input() # S (somar) ou M (tirar a média)

if o == 'S': print(f"{somar_array():.1f}")
elif o == 'M': print(f"{media_array():.1f}")