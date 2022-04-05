#include <cs50.h>
#include <stdio.h>

int main(void){
    int alt = get_int("Height: ");
    int a = alt;
    int b = 0;

    for(int linha= 1 ;linha<=alt;linha++){//linha
        for(int esp = 1;esp<a;esp++){
            printf(" ");
        }
        b = linha;
        for(int c = 0;c<b;c++){
            printf("#");
        }
        printf(" ");
        for(int c = 0;c<b;c++){
            printf("#");
        }
        printf("\n");
        a--;

    }
}
