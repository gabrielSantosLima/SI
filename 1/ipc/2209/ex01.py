# Ler a velocidade do carro do usuário (em km/h)
# Caso velocidade >= 80, usuário foi multado em R$ 5,00 por cada km excedido

velocidade = float(input('Digite a velocidade do veículo (em km/h): '))

if velocidade > 80.0:
    multa = (velocidade - 80.0) * 5.0
    print(f'Você foi multado. Sua velocidade era {velocidade} km/h.')
    print(f'O valor da multa é R${multa:.2f}')
else: 
    print(f'Você não foi multado. Sua velocidade foi {velocidade} km/h')