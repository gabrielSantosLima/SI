# Ler quantidade de dias, horas, minutos, segundos
# Imprimir em segundos a quantidade total de horas

dias = int(input('Dias: '))
horas = int(input('Horas: '))
minutos = int(input('Minutos: '))
segundos = int(input('Segundos: '))

total_em_segundos = 0

total_em_segundos += dias * 24 * 60 * 60
total_em_segundos += horas * 60 * 60
total_em_segundos += minutos * 60
total_em_segundos += segundos

print(f'{dias} dias, {horas} horas, {minutos} minutos e {segundos} segundos')
print(f'É equivalente a {total_em_segundos}s')