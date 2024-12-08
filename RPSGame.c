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
char* getResultFromEnum(enum Options option);
void checkWinner(enum Options userPick, enum Options compPick);

int main(){
  enum Options userSelected = askUser();
  enum Options compSelected = selectRandomOption();
  checkWinner(userSelected, compSelected);
  return 0;
}

enum Options selectRandomOption(){
  const enum Options length = END_OF_ENUM;
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

void checkWinner(enum Options userPick, enum Options compPick){
  const enum Options length = END_OF_ENUM;
  if(userPick == NA){fprintf(stderr, "Invalid User Input\n"); return;}
  
  // char user[10]; 
  // strcpy(user, );
  // char comp[10]; 
  // strcpy(comp, getResultFromEnum(compPick));
  
  printf("User Picked %s\n", getResultFromEnum(userPick));
  printf("computer picked %s\n", getResultFromEnum(compPick));
  
  if((userPick + 1)%length == compPick){printf("User wins!\n"); return;}
  if((compPick + 1)%length == userPick){printf("Computer wins!\n"); return;}
  printf("Tie Game!\n");
}

char* getResultFromEnum(enum Options option){
  switch(option){
    case PAPER: return "paper";
    case ROCK: return "rock";
    case SCISSORS: return "scissors";
    default: return NULL;
  }
} 