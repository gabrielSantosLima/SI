# Soma de uma P.A. = ((a1 + an) * n) / 2
# an = a1 + (n - 1) * r
# an = a1 + rn - r
# n = (an + r - a1)/r 

a1 = float(input())
an = float(input())
r = float(input())

n = (an + r - a1)/r

soma_pa = ((a1 + an) * n) / 2

print(soma_pa)