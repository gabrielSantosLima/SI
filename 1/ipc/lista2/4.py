a = int(input())
b = int(input())
c = int(input())

if a < b and a < c: print(f'O menor é {a}')
elif b < a and b < c: print(f'O menor é {b}')
elif c < a and c < b: print(f'O menor é {c}')
else: print(f'O menor é {a}')

# print(f'O menor é {min(a,b,c)}')