# Nome: Gabriel Dos Santos Lima
N = int(input())

for A in range(N):
  intervalo = input()
  X, Y = intervalo.split(' ')
  X, Y = int(X), int(Y)

  if Y == 0: 
    print('divisao impossivel') 
    continue

  print(f"{(X/Y):.1f}")