#include <stdio.h>
#include <stdlib.h>

typedef struct nodo Nodo;
Nodo *head;

struct nodo{
  int element;
  struct nodo *next;
};

void addNodo(int value){
  int bolean = 0;
  Nodo *no = (Nodo*)malloc(sizeof(Nodo));
  no->element = value;

  if(head == NULL){
    no->next = NULL;
    head = no;
  }else{
    Nodo *current = head;
    if(current->element< value){
      no->next = head;
      head = no;
    }else{
      while (current->next->element > value){
        current = current->next;
      }
      Nodo *current_assistant = current->next;
      current->next = no;
      no->next = current_assistant;
      
    }
  }
}

void printed(){
  Nodo *current = head;

  while (current!=NULL){
    printf("%d -> ", current->element);
    current = current->next;
  }
  
}

int main(){

  addNodo(10);
  addNodo(20);
  addNodo(30);
  addNodo(15);
  addNodo(21);

  printed();

return 0;
}