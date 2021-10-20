id_funcionario = input()
horas_trabalhadas = int(input())
valor_hora = float(input())

salario = horas_trabalhadas * valor_hora

print(id_funcionario)
print(f'R${salario:.2f}')