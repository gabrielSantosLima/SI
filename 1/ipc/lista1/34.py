from re import search

def valida_hora(hora):
    e_valido = search('[0-9]+:[0-9]+:[0-9]+', hora)
    if e_valido: return hora
    exit()

hora, minuto, segundo = str(valida_hora(input())).split(':')

minuto_atual = int(hora) * 60 + int(minuto) + int(segundo) // 60
segundo_atual = int(segundo) % 60

print(f'{minuto_atual} minutos e {segundo_atual} segundos')