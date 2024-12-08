#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

enum Options {
  PAPER,
  ROCK,
  SCISSORS,
  END_OF_ENUM,
  NA,
};

enum Options selectRandomOption();
enum Options askUser();
void formatString(char arr[], int size);

int main(){
  enum Options selected = askUser();
  switch(selected){
    case ROCK: printf("Rock"); break;
    case PAPER: printf("Paper"); break;
    case SCISSORS: printf("Scissors"); break;
    default: fprintf(stderr, "something went wrong");
  }
  return 0;
}

enum Options selectRandomOption(){
  enum Options length = END_OF_ENUM;
  srand(time(NULL));
  int random = rand();
  return (enum Options) (random) % length;
}

enum Options askUser(){
  const int SIZE = 10;
  char buffer[SIZE];
  printf("Which do you pick?\n");
  fgets(buffer, SIZE, stdin);
  formatString(buffer, SIZE);

  if(strcmp("rock", buffer) == 0){return ROCK;}
  if(strcmp("scissors", buffer) == 0){return SCISSORS;}
  if(strcmp("paper", buffer) == 0){return PAPER;}
  return NA;
}

void formatString(char arr[], int size){
  for(int i = 0; i < size; i++){
    char character = arr[i];
    if(character == '\n'){arr[i] = '\0'; continue;}
    if((int)character < 65 || (int)character > 90){continue;}
    arr[i] += -65 + 97;
  }
}