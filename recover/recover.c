#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[]){
    if(argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
}