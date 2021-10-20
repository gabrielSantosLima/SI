# Automóvel = 12km - 1L
# Velocidade = percurso / tempo
KM_POR_LITRO = 12.0

velocidade = float(input())
tempo = float(input())

distancia = velocidade * tempo

litros_gastos = distancia / KM_POR_LITRO

print(f'{litros_gastos:.2f}')