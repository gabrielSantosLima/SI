# Nome: Gabriel Dos Santos Lima
def calcula_frequencia(frequencias):
  presencas = 0
  faltas = 0
  for frequencia in frequencias:
    if frequencia == "P": presencas += 1
    elif frequencia == "A": faltas += 1

  pode_fazer_exame = (presencas / (presencas + faltas)) >= 0.75
  return pode_fazer_exame 

def calcula_alunos_sem_requisitos_frequencia(lista_alunos, lista_frequencias, quantidade_alunos):
  alunos = lista_alunos.split(' ')
  frequencias = lista_frequencias.split(' ')
  alunos_sem_requisitos_frequencia = []

  if not (1 <= quantidade_alunos <= 100):
    exit()

  if len(alunos) != quantidade_alunos:
    exit()
  
  for i in range(quantidade_alunos):
    if not calcula_frequencia(frequencias[i]):
      alunos_sem_requisitos_frequencia.append(alunos[i])

  return " ".join(alunos_sem_requisitos_frequencia)

N = int(input())
resultados = []

for Nx in range(N):
  quantidade_alunos = int(input())
  nomes_alunos = input()
  frequencias = input()
  resultados.append(calcula_alunos_sem_requisitos_frequencia(nomes_alunos, frequencias, quantidade_alunos))

for resultado in resultados:
  print(resultado)
