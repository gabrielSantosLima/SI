# 'r' when the file will only be read, will be assumed if it’s omitted.
# 'w' for only writing (an existing file with the same name will be erased), 
# 'a' opens the file for appending; any data written to the file is automatically added to the end. 
# 'r+' opens the file for both reading and writing. The mode argument is optional; 
# 'b' appended to the mode opens the file in binary mode: now the data is read and written in 
# the form of bytes objects. This mode should be used for all files that don’t contain text.

from datetime import date as d
from os import system

limpar_terminal = lambda: system('cls')

NOME_ARQUIVO = "bd.txt"

def salvar_mensagem_arquivo(mensagem_completa):
  bd_arquivo = open(NOME_ARQUIVO, 'a')
  bd_arquivo.write(mensagem_completa)
  bd_arquivo.close()

def ler_arquivo():
  bd_arquivo = open(NOME_ARQUIVO)
  mensagens = bd_arquivo.read()
  bd_arquivo.close()
  return mensagens
  
def apagar_mensagens():
  limpar_terminal()
  bd_arquivo = open(NOME_ARQUIVO, 'w')
  bd_arquivo.write("")
  bd_arquivo.close()

def principal():
  limpar_terminal()
  print('1.Mandar mensagem')
  print('2.Ler mensagens')
  print('3.Apagar todas as mensagens')
  print('0.Sair')
  opcao = int(input('Escolha uma opção [0..3]:'))
  
  if opcao == 1: mandar_mensagem()
  elif opcao == 2: ler_mensagens()
  elif opcao == 3: apagar_mensagens()
  elif opcao == 0: exit()
  principal()

def mandar_mensagem():
  limpar_terminal()
  nome = input('Digite seu nome: ')
  mensagem = input('Digite sua mensagem: ')
  data = d.today().strftime("%d/%m/%y")
  mensagem_completa = f"{nome} disse: '{mensagem}' no dia {data}\n"
  salvar_mensagem_arquivo(mensagem_completa)
  principal()

def ler_mensagens():
  limpar_terminal()
  print(ler_arquivo())
  input('\nPressione qualquer tecla para prosseguir...')

  
principal()