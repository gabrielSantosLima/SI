# Nome: Gabriel Dos Santos Lima

def converte_lista_de_inteiros(lista):
  nova_lista = []
  for n in range(len(lista)):
    nova_lista.append(int(lista[n]))
  return nova_lista

def retorna_ganhador(resultados):
  jogador_vencedor = 0
  pontuacao_maxima = 0
  for i in range(len(resultados)):
    if resultados[i] >= pontuacao_maxima:
      jogador_vencedor = i + 1
      pontuacao_maxima = resultados[i]
  return jogador_vencedor

def verifica_quem_ganhou(quantidades_jogadores_e_rodadas, todas_jogadas):
  quantidades_jogadores, rodadas = quantidades_jogadores_e_rodadas.split(' ')
  quantidades_jogadores, rodadas = int(quantidades_jogadores), int(rodadas)

  if not ((1 <= quantidades_jogadores <= 500) or (1 <= rodadas <= 500)):
    exit()

  jogadas_realizadas = converte_lista_de_inteiros(todas_jogadas.split(' '))

  resultados = []

  for i in range(len(jogadas_realizadas)):
    if len(resultados) < quantidades_jogadores:
      resultados.append(jogadas_realizadas[i])
    else:
      resultados[i % quantidades_jogadores] += jogadas_realizadas[i]
  
  return retorna_ganhador(resultados)

quantidades_jogadores_e_rodadas = input()
todas_jogadas = input()
print(verifica_quem_ganhou(quantidades_jogadores_e_rodadas, todas_jogadas))