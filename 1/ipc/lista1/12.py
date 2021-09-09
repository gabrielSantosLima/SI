# Ex: 2 anos 11 meses e 25 dias = 730 + 365 + 25 = 

dias_totais = int(input())

anos = (dias_totais / 30.41) // 12
dias_totais -= anos * 30.41 * 12

meses = dias_totais // 30.41
dias_totais -= meses * 30.41

dias = dias_totais

print(f'{anos}')
print(f'{meses}')
print(f'{dias}')