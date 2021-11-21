# Nome: Gabriel Dos Santos Lima
from re import split

def retornar_mensagem(texto):
  palavras = split("[· ]", texto)
  palavras_descobertas = []
  for palavra in palavras:
    if (palavra != "·"):
      if len(palavra) > 50:
        exit()
      palavras_descobertas.append(palavra[0] if len(palavra) > 1 and palavra != " " else palavra) 

  return "".join(palavras_descobertas)

N = int(input())
resultados = []

for Nx in range(N):
  palavra = input()
  resultados.append(retornar_mensagem(palavra))

for resultado in resultados:
  print(resultado)
