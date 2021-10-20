# Nome: Gabriel Dos Santos Lima
numeros = []
for X in range(100):
  numeros.append(int(input()))
maior = max(numeros)
print(maior)
print(numeros.index(maior) + 1)