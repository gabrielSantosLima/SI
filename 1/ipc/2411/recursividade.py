import os
from time import sleep
clear = lambda: os.system('cls')

def conta_numero(n, max):
  print(n)
  if(n == max): return 
  return conta_numero(n + 1, max)

# Exemplo de programa usando recursividade

def inicia_programa_mostra_opcoes():
  opcoes = {
    "a": lambda: print("Tudo certo :D"),
    "b": lambda: print("Puxa que triste! :o")
  }
  clear()
  print("======================")
  print("a.'Ola python, tudo certo?'")
  print("b.'Não gosto de você python. Sinto muito.")
  print("======================")
  opcao = input("\nEscolha o que você quer dizer para o python[a..b]: ")
  
  if not (opcao in opcoes): return inicia_programa_mostra_opcoes()
  opcoes[opcao]()

inicia_programa_mostra_opcoes()