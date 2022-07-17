#include <stdio.h>
#include <stdlib.h>
typedef struct point Point;
Point *head;

struct point{
    int data;
    struct point *next;
};

void addLast(int element){
  Point *point = (Point*) malloc(sizeof(Point));
  point->data = element;
  point->next = NULL;
  if(head==NULL){
    head = point;
  }else{
    Point *current = head;
    while(current->next!=NULL){
      current = current->next;
    }
    current->next = point;
  }
}



void printed(Point *current){
  if(current!=NULL){
    printf("[%d]",current->data);
    imprimi(current->next);
  }
}

int main(){
  add(10);
  add(11);

  printed(head);
}