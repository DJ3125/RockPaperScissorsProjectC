#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum Options {
  ROCK,
  PAPER,
  SCISSORS,
  END_OF_ENUM,
};

enum Options selectRandomOption();

int main(){
  enum Options selected = selectRandomOption();
  switch(selected){
    case ROCK: printf("Rock"); break;
    case PAPER: printf("Paper"); break;
    case SCISSORS: printf("Scissors"); break;
    default: printf("something went wrong");
  }
  return 0;
}


enum Options selectRandomOption(){
  enum Options length = END_OF_ENUM;
  srand(time(NULL));
  int random = rand();
  return (enum Options) (random) % length;
}