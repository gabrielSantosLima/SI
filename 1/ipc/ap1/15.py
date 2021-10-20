# Nome: Gabriel Dos Santos Lima

while (True):
  intervalo = input()
  X, Y = intervalo.split(' ')
  X, Y = int(X), int(Y)

  if X == Y: exit()

  print("Decrescente" if X > Y else "Crescente")