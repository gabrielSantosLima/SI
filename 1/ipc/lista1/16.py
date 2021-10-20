# Salário mensal = salario_fixo + preco_por_venda * quantidade_carro_vendidos + 5% do total de vendas
PORCENTAGEM_POR_CARRO_VENDIDO = 0.05

quantidade_carros_vendidos = int(input())
preco_venda = float(input())
valor_total_vendas = float(input())
salario_fixo = float(input())

salario_mensal = salario_fixo + quantidade_carros_vendidos * preco_venda + valor_total_vendas * PORCENTAGEM_POR_CARRO_VENDIDO

print(f'R${salario_mensal:.2f}')
