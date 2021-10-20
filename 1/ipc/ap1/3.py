# Nome: Gabriel Dos Santos Lima
# Calcular: 
# a) Área Tri. Ret. = (a * c) / 2
# b) Área Circulo = 3.14159 * (c ** 2)
# c) Área Trapéz. = ((a + b) * c) / 2
# d) Área Quadra. = b ** 2
# e) Área Ret. = a * b

numeros = input()

a,b,c = numeros.split(' ')
a,b,c = float(a), float(b), float(c)

area_triangulo = (a * c) / 2
area_circulo = 3.14159 * (c ** 2)
area_trapezio = ((a + b) * c) / 2
area_quadrado = b ** 2
area_retangulo = a * b

print(f"TRIANGULO: {area_triangulo:.3f}")
print(f"CIRCULO: {area_circulo:.3f}")
print(f"TRAPEZIO: {area_trapezio:.3f}")
print(f"QUADRADO: {area_quadrado:.3f}")
print(f"RETANGULO: {area_retangulo:.3f}")