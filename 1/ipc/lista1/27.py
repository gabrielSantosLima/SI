from math import sqrt

base = float(input())
altura = float(input())

area = base * altura
perimetro = 2 * base + 2 * altura
diagonal = sqrt(base ** 2 + altura ** 2)

print(f'Área: {area:.1f}')
print(f'Perímetro: {perimetro:.1f}')
print(f'Diagonal: {diagonal:.1f}')