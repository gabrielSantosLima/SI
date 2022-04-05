# Nome: Gabriel Dos Santos Lima
n1 = int(input())
n2 = int(input())

if n2 > n1:
  for X in range(n1 + 1, n2):
    if (X % 5 == 2) or (X % 5 == 3): print(X)
elif n1 > n2: 
  for X in range(n2 + 1, n1):
    if (X % 5 == 2) or (X % 5 == 3): print(X)
else:
  if (n1 % 5 == 2) or (n1 % 5 == 3): print(n1)