#include <stdio.h>
#include <stdlib.h>

typedef struct nodo Nodo;
Nodo *head, *last;

struct nodo
{
  int element;
  struct nodo *next;
  struct nodo *previous;
};

void addFirstNodo(int value){
  Nodo *no = (Nodo*) malloc(sizeof(Nodo));

  if(head == NULL){
    no->element = value;
    no->next = head;
    no->previous = NULL;
    head = no;
    last = no;
  }else{
    no->element = value;
    no->next = head;
    head->previous = no;
    no->previous = NULL;
    head = no;
  }  

}

void addLastNodo(int value){
  Nodo *no = (Nodo*) malloc(sizeof(Nodo));

  if (last == NULL){
    no->element =  value;
    no->next = NULL;
    no->previous = last;
    last = no;
    head = no;   
  }else{
    no->element =  value;
    no->next = NULL;
    last->next = no;
    no->previous = last;
    last = no;
  }
  
  
}

void printed(){
  Nodo *current = last;
  printf(" NULL <-->");
  while (current != NULL){
    printf("%d <--> ", current->element);
    current = current->previous;
  }
  printf(" NULL ");
  
}


int main(){

  addLastNodo(100);
  addLastNodo(200);
  addLastNodo(300);

  printed();
  return 0;
}