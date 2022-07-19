#include <stdio.h>
#include <stdlib.h>

typedef struct no No;
int length = 0;
No *head;

struct no
{
  int data;
  struct no *next;
}

add(int value){
  No *element = (No *)malloc(sizeof(No));
  element->data = value;
  element->next = NULL;
  if (head == NULL){
    head = element;
  }
  else
  {
    No *current = head;
    while (current->next != NULL){
      current = current->next;
    }
    current->next = element;
  }
}

void printed(No *head){
  if (head != NULL){
    printf("[ %d ]", head->data);
    printed(head->next);
  }
}

void pop(){
  if(head == NULL){
    printf("Lista vazia");
  }else{
    head = head->next;
  }
}

int main(){

  add(10);
  add(5);
  add(30);
  
  No *aux = head;
  printed(aux);

  printf("\n");
  return 0;
}