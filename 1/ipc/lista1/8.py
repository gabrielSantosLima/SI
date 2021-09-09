def retorna_produto(peca_string):
    codigo, quantidade, valor = peca_string.split(',')
    quantidade = int(quantidade)
    valor_total = float(quantidade * float(valor))
    return f"{codigo}, {quantidade}, R${valor_total:.2f}"

peca_a = input()
peca_b = input()

print(retorna_produto(peca_a))
print(retorna_produto(peca_b))