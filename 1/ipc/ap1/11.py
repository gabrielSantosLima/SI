# Nome: Gabriel Dos Santos Lima
N = int(input())
if N >= 10**4: exit()
for X in range(1,10001):
  if X % N == 2: print(X)