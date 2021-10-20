# an = a1 * q ** (n - 1)
def calcula_an(a1, q, n):
    return a1 * q ** (n-1)

a1 = float(input())
q = float(input())

print(calcula_an(a1, q, 20))