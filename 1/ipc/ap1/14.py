# Nome: Gabriel Dos Santos Lima
N = int(input())

somas = []
for A in range(N):
  intervalo = input()
  X, Y = intervalo.split(' ')
  X, Y = int(X), int(Y)

  soma = 0
  eDecrescente = X > Y
  for B in range(X, Y, -1 if eDecrescente else 1):
    if not (B % 2 == 0) and (X != B) and (Y != B): soma += B
  somas.append(soma)

for soma in somas:
  print(soma)