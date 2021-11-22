# Nome: Gabriel Dos Santos Lima
L = int(input())
C = int(input())

if not ((1 <= L <= 1000) or (1 <= C <= 1000)):
  exit()

def e_par(valor):
  return valor % 2 == 0

if e_par(C) and not(e_par(L)): print(0)
elif not(e_par(C)) and e_par(L): print(0)
elif e_par(C) and e_par(L): print(1)
elif not(e_par(C)) and not(e_par(L)): print(1)