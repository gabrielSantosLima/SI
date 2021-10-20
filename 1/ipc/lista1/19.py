# Ler valor total
# Desconto: total_pagar * (1 - 0.1)
# Valor da parcela: 3x sem juros
# Comissão do vendedor (a vista): 5% com desconto do valor 
# Comissão do vendedor (parcelada): 5% do valor
COMISSAO_VENDEDOR = 0.05
DESCONTO_VENDA = 0.1

valor = float(input())

valor_com_desconto = valor * (1 - DESCONTO_VENDA)
valor_parcelas = valor / 3
comissao_vendedor_vista = valor_com_desconto * COMISSAO_VENDEDOR
comissao_vendedor_parcela = valor * COMISSAO_VENDEDOR

print(f'Valor com desconto: R${valor_com_desconto:.2f}')
print(f'Valor de cada parcela: R${valor_parcelas:.2f}')
print(f'Comissão do vendedor (a vista): R${comissao_vendedor_vista:.2f}')
print(f'Comissão do vendedor (parcelado): R${comissao_vendedor_parcela:.2f}')