# Círculo = PI * c**2
# Triângulo = (a * c) / 2
# Trapézio = ((a + b) * c) / 2

from math import pi

a = float(input())
b = float(input())
c = float(input())

def area_triangulo(a, c):
    return (a * c) / 2

def area_circulo(c):
    return pi * c**2

def area_trapezio(a,b,c):
    return ((a + b) * c) / 2

print(f'{area_triangulo(a,c):.2f}')
print(f'{area_circulo(c):.2f}')
print(f'{area_trapezio(a,b,c):.2f}')