# Aluno: Gabriel dos Santos Lima
# Projeto final - 1º Período de Sistemas de Informação - Projeto Prático: Rotas

# Objetivo: Descobrir qual irá ser o gasto nas rotas das cidades.
# Restrições:
# 1. Custo depende do:
# 1.1 Valor do diesel
# 1.2 Distância entre as cidades
# 2. Caminhão precisa retornar a cidade de origem
# 3. Caminhões: 1 litro de diesel / 3km rodados 

# Resolução
# 1. Ler total de cidades atendidas
# 2. Ler a distância entre as cidades
# 3. Ler a quantidade de cidades que ele passou
# 4. Ler o percurso do caminhão (cidades que ele passou)
# 5. Ler o valor do diesel (Ler Restrição Item 3)
# 6. Retornar valor do custo da viagem sendo o custo:
# Custo = Litros gastos * Custo do diesel
# Litros Gastos = Percurso Total (km) / 3

distancias = {}
KM_POR_LITRO = 3

def adicionar_distancia(cidade_1, cidade_2, distancia):
  distancias[f"{cidade_1}-{cidade_2}"] = distancia
  distancias[f"{cidade_2}-{cidade_1}"] = distancia 

def retornar_distancia(cidade_1, cidade_2):
  return distancias[f"{cidade_1}-{cidade_2}"] 

def calcula_percurso_total(rotas):
  percurso_total = 0
  for indice in range(len(rotas) - 1):
    percurso_total += retornar_distancia(rotas[indice], rotas[indice + 1])
  rota_volta = retornar_distancia(rotas[0], rotas[len(rotas) - 1])
  percurso_total += rota_volta
  return percurso_total

def principal():
  # Passo 1
  quantidade_de_cidades = int(input())
  
  # Passo 2
  for linha in range(quantidade_de_cidades):
    adicionar_distancia(linha, linha, 0)
    for coluna in range(linha + 1, quantidade_de_cidades):
      distancia = float(input())
      adicionar_distancia(linha + 1, coluna + 1, distancia)
  
  # Passo 3
  quantidade_de_rotas = int(input())
  
  # Passo 4
  rotas = []
  for indice in range(1, quantidade_de_rotas + 1):
    rotas.append(int(input()))
  
  # Passo 5
  valor_diesel = float(input())

  #Passo 6
  percurso_total = calcula_percurso_total(rotas)
  litros_gastos = percurso_total / KM_POR_LITRO
  custo = litros_gastos * valor_diesel

  # Resposta - Custo da viagem
  print(f"R$ {custo:.2f}")


principal()