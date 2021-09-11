VALOR_UNITARIO = 1.3
VALOR_DUPLO = 2.6
VALOR_10_VIAGENS = 12.0

precos = {
    'unitario' : VALOR_UNITARIO, 
    'duplo' : VALOR_DUPLO,
    '10 viagens' : VALOR_10_VIAGENS
}

def valida_tipo_bilhete(tipo):
    if tipo == 'unitario' or tipo == 'duplo' or tipo == '10 viagens':
        return tipo
    exit()  

tipo_bilhete = valida_tipo_bilhete(input())
valor_pago = float(input())

quantidade_bilhetes = int(valor_pago // precos[tipo_bilhete])
troco = valor_pago % precos[tipo_bilhete]

print(f'Você pode comprar {quantidade_bilhetes} bilhetes do tipo "{tipo_bilhete}".')
print(f'Seu troco é R${troco:.2f}.')

