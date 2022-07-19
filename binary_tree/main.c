
#include <stdio.h>
#include <stdlib.h>

typedef struct nodo Nodo;

struct nodo
{
  int value;
  struct nodo *left;
  struct nodo *right;
};

Nodo* create(int value){
  Nodo *no = (Nodo*) malloc(sizeof(Nodo));
  no->value = value;
  no->right = NULL;
  no->left = NULL;
  return no;
}

void printed(Nodo *no){
  if(no != NULL){
    printf("[ %d ]", no->value);
    printed(no->left);
    printed(no->right);
  }
}

int main(){

  Nodo *no1 = create(10);
  Nodo *no2 = create(20);
  Nodo *no3 = create(30);
  Nodo *no4 = create(40);
  Nodo *no5 = create(50);
  Nodo *no6 = create(60);

  no5->left   = no1;
  no5->right  = no2;
  no6->left   = no3;
  no6->right  = no4;

  printed(no6);
  return 0;
}