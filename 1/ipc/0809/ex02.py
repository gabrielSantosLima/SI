# Ler as notas das três avaliações
# Se média >= 7.0, o aluno foi aprovado
#  Caso contrário, aluno reprovado
# x1 + x2 + x3
media = 0
for N in range(3):
    media += float(input(f' Digite sua {N + 1} nota: '))
media = media / 3

if media >= 7.0: print(f'Você foi aprovado. Sua média: {media}')
else: print(f'Você foi reprovado. Sua média: {media:.2f}')