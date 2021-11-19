# Nome: Gabriel Dos Santos Lima
# X[i] = x

X = []
for i in range(10):
  x = int(input())
  X.append(x if x > 0 else 1)

for i in range(10):
  print(f"X[{i}] = {X[i]}")