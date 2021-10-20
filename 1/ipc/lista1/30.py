from math import sqrt

comprimento = float(input())
largura = float(input())
altura = float(input())

volume = comprimento * largura * altura
diagonal = sqrt(altura ** 2 + comprimento ** 2 + largura ** 2)
area = 2 * (comprimento * largura + comprimento * altura + altura * largura )
perimetro = 5 * comprimento + 6 * largura + 8 * altura

print(f'Volume: {volume:.2f}')
print(f'Área: {area:.2f}')
print(f'Diagonal: {diagonal:.2f}')
print(f'Perímetro: {perimetro:.2f}')