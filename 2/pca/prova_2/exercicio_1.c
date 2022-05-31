#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WORD_MAX_LENGTH 100

// 1) Faça um programa em C que leia três strings do teclado e ao final as escreva em 
// linhas diferentes em um arquivo do tipo texto. Ao final, conte e imprima a 
// quantidade de linhas que o arquivo tem.

int main(){
  FILE *file;
  
  char *string1;
  char *string2;
  char *string3;

  int stringSize = WORD_MAX_LENGTH * sizeof(char);

  string1 = (char*) malloc(stringSize);
  string2 = (char*) malloc(stringSize);
  string3 = (char*) malloc(stringSize);

  printf("First string: ");
  scanf("%s", string1);
  printf("Second string: ");
  scanf("%s", string2);
  printf("Third string: ");
  scanf("%s", string3);

  file = fopen("output.txt", "w");

  if(file == NULL){
    printf("Error on open file");
    return 0;
  }

  while(*string1 != '\0'){
    fprintf(file, "%c", *string1);
    string1++;
  }
  fprintf(file, "\n");
  while(*string2 != '\0'){
    fprintf(file, "%c", *string2);
    string2++;
  }
  fprintf(file, "\n");
  while(*string3 != '\0'){
    fprintf(file, "%c", *string3);
    string3++;
  }
  fprintf(file, "\n");
  fclose(file);

  file = fopen("output.txt", "r");
  if(file == NULL){
    printf("Error on open file");
    return 0;
  }
  char character;
  int lines = 0;
  while(character != EOF){
    character = fgetc(file);
    if(character == '\n'){
      lines++;
    }
  }
  printf("File contains %d lines.", lines);
  fclose(file);
  return 0;
}