# Nome: Gabriel Dos Santos Lima
# 1 regra: Ordenar por tamanho decrescente.
# 2 regra: Quando palavras de tamanho igual, manter a ordem que estava no input.

def ordenar_texto(texto):
  texto_ordenado = " "
  palavras = texto.split(' ')
  quantidade_palavras = len(palavras)

  if not (1 <= quantidade_palavras <= 50):
    exit()

  for i in range(0, quantidade_palavras - 1):
    trocou = False
    for j in range(0, quantidade_palavras - 1 - i):
      if (len(palavras[j]) > 50) or (len(palavras[j + 1]) > 50):
        exit()
      if len(palavras[j]) < len(palavras[j + 1]):
        trocou = True
        palavras[j + 1], palavras[j] = palavras[j], palavras[j + 1]
    if not trocou:
      break

  texto_ordenado = texto_ordenado.join(palavras)
  return texto_ordenado

N = int(input())
resultados = []

for Nx in range(N):
  texto = input()
  resultados.append(ordenar_texto(texto))

for resultado in resultados:
  print(resultado)