# Nome: Gabriel Dos Santos Lima
n1 = int(input())
n2 = int(input())

soma = 0

if n2 > n1:
  for X in range(n1, n2 + 1):
    if not (X % 13 == 0): soma+= X
elif n1 > n2: 
  for X in range(n2, n1 + 1):
    if not (X % 13 == 0): soma+= X
else:
  soma = n1
print(soma)