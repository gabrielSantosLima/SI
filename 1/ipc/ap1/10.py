# Nome: Gabriel Dos Santos Lima
qtd_numeros_dentro_intervalo = 0
qtd_numeros_fora_intervalo = 0

N = int(input())

for Nx in range(N):
  X = int(input())
  if 10 <= X <= 20: qtd_numeros_dentro_intervalo += 1
  else: qtd_numeros_fora_intervalo += 1

print(f"{qtd_numeros_dentro_intervalo} in")
print(f"{qtd_numeros_fora_intervalo} out")