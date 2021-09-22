# Ler salário
# Se salario > 1250, aumento de salário em 10% 
# Se 1 <= salario <= 1250, aumento de salário em 15%

salario = float(input('Digite seu salário (em R$): '))

if salario > 1250.0:
    aumento_salarial = salario * 0.1
    print(f'Você recebeu um aumento de 10%. Seu aumento foi de R${aumento_salarial:.2f}')
elif 1 <= salario <= 1250.0 :
    aumento_salarial = salario * 0.15
    print(f'Você recebeu um aumento de 15%. Seu aumento foi de R${aumento_salarial:.2f}')
