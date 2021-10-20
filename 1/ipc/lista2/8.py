from math import sqrt

def bascara(a,b,delta):
  x1 = (-b + sqrt(delta)) / (2 * a)
  x2 = (-b - sqrt(delta)) / (2 * a)
  return x1,x2

a = int(input('A: '))
b = int(input('B: '))
c = int(input('C: '))

delta = (b**2) - (4 * a * c)

if delta >= 0:
  print(f'Raizes: {bascara(a,b,delta)}')
else:
  print('Não é possível divisão por zero e raíz quadrada de número negativo')


