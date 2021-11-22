# Nome: Gabriel Dos Santos Lima
quantidade_total = int(input())
quantidade_comprada = int(input())

figurinhas_compradas = []

for Nx in range(quantidade_comprada):
  numero_figurinha = int(input())
  if not (numero_figurinha in figurinhas_compradas):
    figurinhas_compradas.append(numero_figurinha)

print(quantidade_total - len(figurinhas_compradas))