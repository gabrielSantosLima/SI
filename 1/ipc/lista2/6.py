a = int(input())
b = int(input())
c = int(input())

# print(sorted([a,b,c]))

numeros = []

if a < b and a < c: numeros.append(a)
elif b < a and b < c: numeros.append(b)
elif c < a and c < b: numeros.append(c)

if b < a < c or c < a < b: numeros.append(a)
elif a < b < c or c < b < a: numeros.append(b)
elif b < c < a or a < c < b: numeros.append(c)

if a > b and a > c: numeros.append(a)
elif b > a and b > c: numeros.append(b)
elif c > a and c > b: numeros.append(c)

print(numeros)