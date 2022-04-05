# Nome: Gabriel Dos Santos Lima
# Nota a de peso 3.5
# Nota b de peso 7.5
PESO_A = 3.5
PESO_B = 7.5

notaA = float(input())
notaB = float(input())

media = (notaA * PESO_A + notaB * PESO_B) / (PESO_A + PESO_B)

print(f'MEDIA = {media:.5f}')