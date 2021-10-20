# Ex: 02:20:30 = 7200 + 1200 + 30 = 8430
# Hora = Minutos / 60
# Minutos = Segundos / 60
segundos_totais = int(input())

horas = int((segundos_totais / 60) // 60)
segundos_totais -= horas * 60 * 60

minutos = int(segundos_totais // 60)
segundos_totais -= minutos * 60

segundos = int(segundos_totais)

print(f'{str(horas).zfill(2)}:{str(minutos).zfill(2)}:{str(segundos).zfill(2)}')