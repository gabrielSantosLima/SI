def somar_lista(lista, indice_atual):
  if indice_atual == len(lista):
    return 0
  return lista[indice_atual] + somar_lista(lista, indice_atual + 1) 

lista = [1,2,3] # Exemplo de lista
print(somar_lista(lista, 0)) # Saída esperada: 6