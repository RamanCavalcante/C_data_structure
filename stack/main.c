#include <stdio.h>
#include <stdlib.h>

typedef struct no No;

struct no
{
    int value;
    struct no *nex;
};

No *head;

void add(int data){
  No *no = (No *)malloc(sizeof(No));
  no->value = data;
  no->nex = head;
  head = no;
}

void printed(No *head){
  if(head!=NULL){
      printf("[ %d ]",head->value);
      printed(head->nex);
  }
}

void removeStack(){
  if(head==NULL){
    printf("Lista vazia");
  }else{
    head = head->nex;
  }
}

int main(){

  add(10);
  add(20);
  add(30);
  add(40);
  add(50);
  
  No *headAux = head;

  printed(headAux);
  
  printf("\n");

  removeStack();
  
  No *headAux2 = head;

  printed(headAux2);

  return 0;
}