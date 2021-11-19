# Nome: Gabriel Dos Santos Lima
TAMANHO = 15

pares = []
impares = []

def print_array(array, tipo):
  for i in range(len(array)):
    print(f'{tipo}[{i}] = {array[i]}')

for x in range(15):
  n = int(input())
  if (n % 2) == 0: pares.append(n)
  else: impares.append(n)

  if len(pares) == 5:
    print_array(pares, "par")
    pares = []
  if len(impares) == 5:
    print_array(impares, "impar")
    impares = []

print_array(impares, "impar")
print_array(pares, "par")