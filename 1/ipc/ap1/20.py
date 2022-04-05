# Nome: Gabriel Dos Santos Lima
N = int(input())
if not(1 <= N <= 100): exit()
for Nx in range(N):
  x = int(input())
  if not(1 <= x <= 10**8): exit()

  soma = 0
  for y in range(1, x):
    if x % y == 0: soma += y
  
  ePerfeito = f"{x} eh perfeito" if soma == x else f"{x} nao eh perfeito"
  print(ePerfeito)