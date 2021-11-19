# Nome: Gabriel Dos Santos Lima
N = int(input())

def desembaralha_texto(texto):
  tamanho_total = len(texto)
  posicao_meio = int(tamanho_total/2) - 1
  texto_desembaralhado = ""
  for i in range(posicao_meio, -1, -1):
    texto_desembaralhado += texto[i]
  for i in range(tamanho_total - 1, posicao_meio, -1):
    texto_desembaralhado += texto[i]
  return texto_desembaralhado

for Nx in range(N):
  texto = input()
  texto_desembaralhado = desembaralha_texto(texto)
  print(texto_desembaralhado)