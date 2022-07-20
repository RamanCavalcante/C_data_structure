
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

void add(Nodo *newNodo, int value){
  if(value < newNodo->value){
    if(newNodo->left == NULL){
      newNodo->left = create(value);
    }else{
      add(newNodo->left, value);
    }
  }else{
    if(newNodo->right == NULL){
      newNodo->right =  create(value);
    }else{
      add(newNodo->right, value); 
    }
  }
}

void removeTree(Nodo *nodeRemoved, int valueRemoved){
  Nodo *son = nodeRemoved;
  Nodo *dad;

  do{
    dad = son;
    if(valueRemoved < nodeRemoved->value){
      son = son->left;
    }else if(valueRemoved > nodeRemoved->value){
      son = son->right;
    }
  }while(son != NULL && son->value == valueRemoved);

  if(son!= NULL){
    if(son->left == NULL && son->right ==NULL){//caso não tenha tenha sons
      if(dad->left  == son) dad->left  = NULL;
      if(dad->right == son) dad->right = NULL;
    }

    if(son->left != NULL && son->right == NULL){//caso tenha um son a esquerda
      if(dad->left  == son) dad->left  = NULL;
      if(dad->right == son) dad->right = NULL;
    }

    if(son->left == NULL && son->right != NULL){//caso tenha um son a direita
      if(dad->left == son) dad->left   = NULL;
      if(dad->right == son) dad->right = NULL;
    }

    if(son->left != NULL && son->right != NULL){//caso tenha dois sons
      if(son->left->right == NULL){
        son->value = son->left->value;
      }else{
        Nodo *p = son->left;
        Nodo *aux =p;
        while (p->right != NULL){
          aux = p;
          p = p->right;
        }
        aux->right = NULL;
        son->value = p->value;
        
      }
    }
  }
}


int main(void){
  Nodo *root = create(70);
  
  add(root, 10);
  add(root, 5);
  add(root, 11);
  printed(root);

  removeTree(root, 5);
  printf("\n");
  printed(root);
  return 0;
}