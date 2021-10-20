# 1 ano = 360 dias
# 1 mês = 30 dias
# 1 dia = 1 dia

anos = int(input())
meses = int(input())
dias = int(input())

quantidade_dias = (anos * 360) + (meses * 30) + dias

print(f'Você tem {quantidade_dias} dias de vida')