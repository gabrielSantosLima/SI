nome = input()
salario = float(input())
total_vendas = float(input())

comissao = total_vendas * 0.15
salario_final = comissao + salario

print(f'{salario_final:.2f}')