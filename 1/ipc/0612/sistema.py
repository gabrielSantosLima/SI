from os import system
import time
clear = lambda: system("cls")

estoque = {}

def principal():
  clear()
  print("=====================\n")
  print("1.Cadastrar mercadoria\n")
  print("2.Alterar mercadoria\n")
  print("3.Vender mercadoria\n")
  print("4.Listar mercadorias\n")
  print("0.Sair\n")
  print("=====================")
  opcao = int(input("Digite uma opção [0..4]: "))

  if opcao == 1: cadastrar_mercadoria()
  elif opcao == 2: alterar_mercadoria()
  elif opcao == 3: vender_mercadoria()
  elif opcao == 4: listar_mercadorias()
  elif opcao == 0: exit()
  else: principal()

def mercadoria_existe(nome_mercadoria):
  return nome_mercadoria in estoque.keys()

def espera(segundos):
  time.sleep(segundos)
  return

def vender(nome_mercadoria, unidades):
  if estoque[nome_mercadoria] - unidades < 0:
    print("Não há produtos suficientes para venda!")
    espera(2)
    return False
  estoque[nome_mercadoria] -= unidades
  return True

def comprar(nome_mercadoria, unidades):
  estoque[nome_mercadoria] += unidades

def cadastrar_mercadoria():
  clear()
  nome_mercadoria = input("Digite o nome da mercadoria: ")
  quantidade = int(input("Digite a quantidade: "))
  estoque[nome_mercadoria] = quantidade
  print(f"{quantidade} unidades de '{nome_mercadoria}' adicionados!")
  espera(2)
  principal()

def alterar_mercadoria():
  clear()
  nome_mercadoria = input("Digite o nome da mercadoria: ")
  
  if not mercadoria_existe(nome_mercadoria):
    print("Mercadoria não existe. Tente cadastrar primeiro!")
    espera(2)
    principal()
    return

  unidades = int(input("Digite quantos produtos serão acrescentados: "))
  comprar(nome_mercadoria, unidades)

  print(f"{unidades} unidades de '{nome_mercadoria}' adicionados!")
  espera(2)
  principal()

def vender_mercadoria():
  clear()
  nome_mercadoria = input("Digite o nome da mercadoria: ")

  if not mercadoria_existe(nome_mercadoria):
    print("Mercadoria não existe. Tente cadastrar primeiro!")
    espera(2)
    principal()
    return

  unidades = int(input("Digite quantos produtos serão vendidos: "))
  vendeu = vender(nome_mercadoria, unidades)

  if not vendeu:
    principal()

  print(f"{unidades} unidades de '{nome_mercadoria}' vendidos!")
  espera(2)
  principal()

def listar_mercadorias():
  clear()
  for nome_mercadoria, quantidade in estoque.items():
    print(f"{nome_mercadoria}: {quantidade} cadastrados\n")
  
  input("\n\nAperte qualquer tecla para voltar.")
  principal()

principal()