ID = int(input('Digite seu número de identificação: '))
nota_1 = float(input('Nota 1: '))
nota_2 = float(input('Nota 2: '))
nota_3 = float(input('Nota 3: '))
media_exercicios = float(input('Digite a média dos exercícios: '))

media_aproveitamento =  (nota_1 + nota_2 * 2 + nota_3 * 3 + media_exercicios)/7

resultado = ""
conceito = ""

if media_aproveitamento >= 90: 
  conceito = "A"
  resultado = "Aprovado"
elif 75.0 <= media_aproveitamento < 90:
  conceito = "B"
  resultado = "Aprovado"
elif 60.0 <= media_aproveitamento < 75:
  conceito = "C"
  resultado = "Aprovado"
elif 40.0 <= media_aproveitamento < 60:
  conceito = "D"
  resultado = "Repovado"
else:
  conceito = "E"
  resultado = "Reprovado"

print(ID)
print(f"Nota 1: {nota_1}")
print(f"Nota 2: {nota_2}")
print(f"Nota 3: {nota_3}")
print(f"Média dos exercícios: {media_exercicios}")
print(f"Média de aproveitamento: {media_aproveitamento}")
print(f"Resultado: {resultado}")
print(f"Conceito: {conceito}")