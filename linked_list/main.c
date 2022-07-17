#include <stdio.h>
#include <stdlib.h>

typedef struct point Point;
Point *head;

struct point
{
    int valueElement;
    struct point *next;
};

void add(int element){
    Point *p = (Point*) malloc(sizeof(Point));
    p->valueElement = element;
    p->next = head;
    head = p;
}

void imprimi(){
    Point *current = head;
    while(current!=NULL){
        printf("\n[%d]", current->valueElement);
        current = current->next;
    }
}

int main(){

    
    add(10);
    add(25);
    add(50);
    add(66);
    
    imprimi();
    return 0;
}