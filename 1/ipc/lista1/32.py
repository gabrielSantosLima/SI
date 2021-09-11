# an = a1 + (n-1) * r

def calcula_an(a1, r, n):
    return a1 + (n-1) * r

a1 = float(input())
r = float(input())

print(calcula_an(a1, r, 20))