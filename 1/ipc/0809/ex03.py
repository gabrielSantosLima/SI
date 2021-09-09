# O aluno, além das notas, deve ter 75% de frequência do total de aulas para ser aprovado 
# Total de aulas: 60hrs
media = 0
for N in range(3):
    nota = float(input(f' Digite sua {N + 1} nota: '))
    if not 1.0 <= nota <= 10.0:
        print('Formato de nota inválido.') 
        exit()
    media += nota

media = media / 3

total_aulas_usuario = int(input('Qual foi o seu total de aulas (de 60hrs): '))
frequencia = total_aulas_usuario/60

if media >= 7.0 and frequencia >= 0.75: 
    print(f'Você foi aprovado. Sua média: {media} e frequência de {frequencia*100:.2f}%')
else: 
    print(f'Você foi reprovado. Sua média foi {media:.2f} e frequência de {frequencia*100:.2f}%')