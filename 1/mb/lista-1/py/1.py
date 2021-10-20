A = [-2,-1,0,1,2]
B = [-6,-5,-4,-3,-2,-1,0,1,2,3,4,5,6]
print(11)
resultado = []

for x in A: # Pega cada valor do conjunto A
    for y in B: # Pega cada valor do conjunto B
        if x == (y + y ** 2): # Verifica a condição - x = y + y^2
            resultado.append((x,y)) # Imprime os pares ordenados que obedecem a condição

print(f'R = {resultado}')

# Resultado: R = [(0,-1),(0,0),(2,-2),(2,1)] 