const TOTAL_SIZE = 240

function validateReason(reason){
  return reason === 'NaN' ? 'Indefinido' : reason
}

function countNumbers(totalSize){
  function randomOneOrTwo(){ // 1: Deve ficar, 2: Deve sair
    const number = Math.floor(Math.random() * (3 - 1) + 1);
    return number
  }
  let count = 0
  for(let step = 1; step <= totalSize; step ++){
    if(randomOneOrTwo() == 1){
      count++
    }
  }
  return count 
}

console.log(`Rodada (i),Restantes (Qi),Razão (Qi / (Q(i - 1)))`)
console.log(`0,${TOTAL_SIZE},`)
pastTotalSize = TOTAL_SIZE

for(let count = 1; count <= 7; count++){
  const newTotalSize = countNumbers(pastTotalSize)
  if(newTotalSize === 0) return
  const reason = validateReason((newTotalSize / pastTotalSize).toFixed(2))
  console.log(`${count},${newTotalSize},${reason}`)
  pastTotalSize = newTotalSize
}
