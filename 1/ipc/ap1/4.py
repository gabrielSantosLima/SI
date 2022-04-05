# Nome: Gabriel Dos Santos Lima
# Nota 1 de peso 2
# Nota 2 de peso 3
# Nota 3 de peso 4
# Nota 4 de peso 1

PESO_1 = 2
PESO_2 = 3
PESO_3 = 4
PESO_4 = 1

notas = input()
n1, n2, n3, n4 = notas.split(' ')
n1,n2,n3,n4 = float(n1), float(n2), float(n3), float(n4)

media = (n1 * PESO_1 + n2 * PESO_2 + n3 * PESO_3 + n4 * PESO_4) / (PESO_1 + PESO_2 + PESO_3 + PESO_4)

if 5.0 <= media <= 6.9:
  nota_exame = float(input())
  media_final = (nota_exame + media) / 2
  foiAprovado = "aprovado" if media_final >= 5.0 else "reprovado"

  print(f"Media: {media:.1f}")
  print(f"Aluno em exame.")
  print(f"Nota do exame: {nota_exame}")
  print(f"Aluno {foiAprovado}.")
  print(f"Media final: {media_final:.1f}")
else:
  foiAprovado = "aprovado" if media >= 7.0 else "reprovado"
  print(f"Media: {media:.1f}")
  print(f"Aluno {foiAprovado}.")