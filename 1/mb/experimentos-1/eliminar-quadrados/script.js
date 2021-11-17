const QUANTIDADE_TOTAL = 240

function validateReason(reason){
  return reason === 'NaN' ? 'Indefinido' : reason
}

function countNumbers(totalSize){
  function randomOneOrZero(){ // 1: Deve sair, 2: Deve ficar
    const number = Math.floor(Math.random() * (3 - 1) + 1);
    return number
  }
  let count = 0
  for(let valor = 1; valor <= totalSize; valor ++){
    if(randomOneOrZero() == 1){
      count++
    }
  }
  return count 
}

console.log(`Rodada (i),Restantes (Qi),Razão (Qi / (Q(i - 1)))`)
console.log(`0,${QUANTIDADE_TOTAL},`)
pastTotalSize = QUANTIDADE_TOTAL
for(let count = 1; count <= 7; count++){
  const newTotalSize = countNumbers(pastTotalSize)
  if(newTotalSize === 0) return
  const reason = validateReason((newTotalSize / pastTotalSize).toFixed(2))
  console.log(`${count},${newTotalSize},${reason}`)
  pastTotalSize = newTotalSize
}
