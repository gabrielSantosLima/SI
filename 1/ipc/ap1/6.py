# Nome: Gabriel Dos Santos Lima
DDDS = { 
  61:"Brasilia",
  71: "Salvador",  
  11: "Sao Paulo",  
  21: "Rio de Janeiro",  
  32: "Juiz de Fora",  
  19: "Campinas",  
  27: "Vitoria",  
  31: "Belo Horizonte",  
}

DDD = int(input())
print(DDDS[DDD] if DDDS.get(DDD) != None else "DDD nao cadastrado")