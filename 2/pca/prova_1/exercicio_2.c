// Aluno: Gabriel Dos Santos Lima
// Martícula: 2115310010
// Sistemas de Informação - PCA
#include <stdio.h>

#define START_NUMBER 502
#define END_NUMBER 999

int main(){
  int counter = 0;

  for(counter = START_NUMBER; counter <= END_NUMBER; counter++){
    int firstDigit = counter / 100;
    int secondDigit = (counter - firstDigit * 100) / 10;
    int thirdDigit = (counter - firstDigit * 100 - secondDigit * 10);

    double firstTerm = firstDigit * firstDigit * firstDigit;
    double secondTerm = secondDigit * secondDigit * secondDigit;
    double thirdTerm = thirdDigit * thirdDigit * thirdDigit;

    if((firstTerm + secondTerm + thirdTerm) == counter){
      printf("%d ", counter);
    }
  }

  return 0;
} 