# Soma do custo de um carro novo = custo_fabrica + 45% + 28%
custo_frabrica = float(input())
custo_total = custo_frabrica * (1 + 0.45 + 0.28)
print(f'R${custo_total:.2f}')