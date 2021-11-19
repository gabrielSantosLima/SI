m = [[1,2,3], [3,4,5], [5,6,7]]
resultado = ","

for a in m:
  print(resultado.join(map(str, a)))
