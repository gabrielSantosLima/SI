# Nome: Gabriel Dos Santos Lima
N = int(input())
if not (2 < N < 1000): exit()
for X in range(1, 11):
  print(f"{X} x {N} = {X * N}")