# Nome: Gabriel Dos Santos Lima
alfabeto = list("abcdefghijklmnopqrstuvwxyz")

def ordena_letras(letras):
  quantidade_letras = len(letras)

  for i in range(0, quantidade_letras - 1):
    trocou = False
    for j in range(0, quantidade_letras - 1 - i):
      if alfabeto.index(letras[j]) > alfabeto.index(letras[j + 1]):
        trocou = True
        letras[j + 1], letras[j] = letras[j], letras[j + 1]
    if not trocou:
      break

def retorna_letras_mais_repetidas(dicionario_letras):
  letras_mais_repetidas = []
  
  for letra, quantidade in dicionario_letras.items():
    if len(letras_mais_repetidas) == 0:
      letras_mais_repetidas.append(letra)
    elif dicionario_letras[letras_mais_repetidas[0]] < quantidade:
      letras_mais_repetidas = []
      letras_mais_repetidas.append(letra)
    elif dicionario_letras[letras_mais_repetidas[0]] == quantidade:
      letras_mais_repetidas.append(letra)
  ordena_letras(letras_mais_repetidas)
  return "".join(letras_mais_repetidas)

def conta_letras_em_palavra(palavra):
  palavra_limpa = palavra.replace(" ", "").lower()
  letras = list(palavra_limpa)
  dicionario_letras = {}
  for letra in letras:
    if not (letra in dicionario_letras.keys()):
      dicionario_letras[letra] = 1
    else:
      dicionario_letras[letra] = dicionario_letras[letra] + 1

  letras_mais_repetidas = retorna_letras_mais_repetidas(dicionario_letras)
  return letras_mais_repetidas

N = int(input())
resultados = []

for Nx in range(N):
  palavra = input()
  if len(palavra) > 200:
    exit()
  resultados.append(conta_letras_em_palavra(palavra))

for resultado in resultados:
  print(resultado)