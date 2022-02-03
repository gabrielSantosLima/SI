# 3) Faça um script em Python que leia três valores do teclado: preço,
# quantidade, valor total. Considere os seguintes valores lidos do teclado:
# preco = 100
# quantidade = 20
# valor_total = 1000
#
# Saída: Eu vou comprar 20 unidades do produto que custa 100 reais.
# Isso dá um valor de 1000 no total.
#
# Aluno: Gabriel Dos Santos Lima.
preco = float(input("Digite o preço da unidade do produto: "))
quantidade = int(input("Digite a quantidade de produtos: "))
valor_total = float(input("Digite o valor total da compra: "))

print(
    f"Eu vou comprar {quantidade} {'unidade' if quantidade == 1 else 'unidades'}"
    + f" do produto que custa {preco:.2f} {'real' if preco == 1.0 else 'reais'}."
    + f" Isso dá um valor de {valor_total:.2f} no total."
)
