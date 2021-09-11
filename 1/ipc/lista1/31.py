from math import sqrt

cateto1 = float(input())
cateto2 = float(input())

hipotenusa = sqrt(cateto1 ** 2 + cateto2 ** 2)

print(f'{hipotenusa:.2f}')