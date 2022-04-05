# 1) O IMC – Índice de Massa Corporal é um critério da Organização Mundial de Saúde para dar
# uma indicação sobre a condição de peso de uma pessoa adulta. A fórmula é IMC = peso / ( altura )² 
# Elabore um algoritmo que leia o peso e a altura de um adulto e mostre sua condição de acordo
# com a tabela abaixo. 

# Abaixo de 18,5 - Abaixo do peso 
# Entre 18,5 e 25 - Peso normal 
# Entre 25 e 30 - Acima do peso 
# Acima de 30 - obeso
peso = float(input('Digite seu peso: '))
altura = float(input('Digite sua altura: '))

IMC = peso / (altura * altura)

if IMC < 18.5: print('Abaixo do peso')
elif 18.5 <= IMC < 25.0: print('Peso normal')
elif 25 <= IMC <= 30.0: print('Acima do peso')
else: print('Obeso')