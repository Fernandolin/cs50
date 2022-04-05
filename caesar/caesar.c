#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main(int argc, string argv[])
{

    if(argc != 2){
        printf("Usage: ./caesar key\n");
        return 1;
    }
    for(int conta = 1; conta< strlen(argv[1]);conta++){
        if(isdigit(argv[1][conta])){
            continue;
        }
        else{
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    int key = atoi(argv[1]);
        if(key>26){
            key = key%26;
        }
        string frase = get_string("plaintext: ");
        printf("ciphertext: ");

        for(int cont =0;cont < strlen(frase);cont++){

            if(isalpha(frase[cont])){
                //printf("%c",frase[cont]);
                if(frase[cont]>=65 && frase[cont]<=90){
                    if(frase[cont]+key>90){
                        int aux =0;
                        aux = 90-(int)frase[cont];
                        int resp = 65+key-aux-1;
                        printf("%c",resp);
                        }
                        else{
                            frase[cont] = frase[cont]+key;
                            printf("%c",frase[cont]);
                        }
                    }
                    else if(frase[cont]>=97 && frase[cont]<=122){
                        if(frase[cont]+key>122){
                            int aux =0;
                            aux = 122-frase[cont];
                            int resp = 97+key-aux-1;
                            printf("%c",resp);
                        }
                        else{
                            frase[cont] = frase[cont]+key;
                            printf("%c",frase[cont]);
                        }
                    }
                }
                else{
                    printf("%c",frase[cont]);
                }
        }
        printf("\n");
    return 0;
}
