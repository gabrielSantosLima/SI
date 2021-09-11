MESES_ATRASADOS = 6
JUROS = 0.05

emprestimo = float(input())

for N in range(MESES_ATRASADOS):
    emprestimo += emprestimo * JUROS

print(f'Valor a ser pago: R${emprestimo:.2f}')