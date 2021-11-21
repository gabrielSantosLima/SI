# Nome: Gabriel Dos Santos Lima
alfabeto = list("ABCDEFGHIJKLMNOPQRSTUVWXYZ")

def muda_letra(letra, n):
  indice_real = alfabeto.index(letra)
  letra_trocada = alfabeto[indice_real - n]
  return letra_trocada

def muda_palavra(palavra, n):
  if not (0 <= n <= 25):
    exit()
  if not (1 <= len(palavra) <= 50):
    exit()
  letras = list(palavra)
  palavra_trocada = ""
  for letra in letras:
    palavra_trocada += muda_letra(letra, n)
  return palavra_trocada

N = int(input())
resultados = []
for Nx in range(N):
  palavra = input().upper()
  n = int(input())
  resultados.append(muda_palavra(palavra, n))
for resultado in resultados:
  print(resultado)