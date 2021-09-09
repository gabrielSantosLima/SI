# Ler três números
# Imprime o maior e o menos número

numero1 = int(input('Digite o primeiro número: '))
numero2 = int(input('Digite o segundo número: '))
numero3 = int(input('Digite o terceiro número: '))

maior_numero = max(numero1, numero2, numero3)
menor_numero = min(numero1, numero2, numero3)

print(f'O maior número é {maior_numero} e o menor número é {menor_numero}')