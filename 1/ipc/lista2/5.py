ano_atual = int(input())
ano_nascimento = int(input())

idade = ano_atual - ano_nascimento

if idade >= 16: print('Você pode votar.')
else: print('Você ainda não pode votar.')