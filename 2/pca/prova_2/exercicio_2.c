#include <stdio.h>
#include<stdbool.h>  

#define SIZE 10

int main(){
  int array[SIZE];
  int counter, counter2;

  for(counter = 0; counter < SIZE; counter++){
    scanf("%d", &array[counter]);
  } 

  int repeat = 0;

  for(counter = 0; counter < SIZE; counter++){
    bool repeated = false;
    for(counter2 = 0; counter2 < SIZE; counter2++){
      if(array[counter] == array[counter2] && counter != counter2 && array[counter] <= 10 && array[counter2] <= 10){
        repeat++;
        repeated = true;
        array[counter2] = 11;
      }
    }
    if(repeated){
      repeat++;
    }
  }

  int array2[repeat];

  printf("Repete: %d\n", repeat);
  for(counter = 0; counter < SIZE; counter++){
    printf("%d ", array[counter]);
  } 

  return 0;
}