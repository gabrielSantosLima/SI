from math import sqrt

lado = float(input())

area = lado * lado
perimetro = 4 * lado
diagonal = lado * sqrt(2)

print(f'Área: {area:.1f}')
print(f'Perímetro: {perimetro:.1f}')
print(f'Diagonal: {diagonal:.1f}')