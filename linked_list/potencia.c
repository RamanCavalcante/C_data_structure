#include <stdio.h>

int potencia (int expoente, int base){
    
    if(expoente ==1){
        return base;
    }
    return base * potencia(expoente -1, base);
}

int main(){

    int result = potencia(2,5);
    printf("%d",result);
}