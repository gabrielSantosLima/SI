# Ex: 02:10:21 - 01:10:20 = 01:00:01

from re import search

def valida_hora(hora):
    e_valido = search('[0-9]+:[0-9]+:[0-9]+', hora)
    if e_valido: return hora
    print('Formato inválido.')
    exit()

hora1, minutos1, segundos1 = str(valida_hora(input())).split(':')
hora2, minutos2, segundos2 = str(valida_hora(input())).split(':')

resultado_hora = str(int(hora1) - int(hora2)).zfill(2)
resultado_minutos = str(int(minutos1) - int(minutos2)).zfill(2)
resultado_segundos = str(int(segundos1) - int(segundos2)).zfill(2)

print(f'{resultado_hora}:{resultado_minutos}:{resultado_segundos}')