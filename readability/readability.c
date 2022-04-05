#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_word(string text);
int count_sentence(string text);


int main(void){
    string name = get_string("Text: ");
    double letra = count_letters(name);
    double word = count_word(name);
    double sentence = count_sentence(name);
    /*printf("O numero de letas é: %d\n",letra);
    printf("O numero de word é: %d\n",word);
    printf("O numero de sentence é: %d\n",sentence);*/
    double L = (letra*100)/word;
    double S = (sentence*100)/word;
    double index = 0.0588 * L - 0.296 * S - 15.8;
    // printf("%.2f",index);
    int resp = (int)index;
    double veri = index-resp;
    double final = 0;
    if(veri>0.5)
         final = ceil(index);
    }
    else if(veri<=0.5){
         final = floor(index);
     }

     resp = final;

    // printf("%d", resp);

    if(resp< 1){
        printf("Before Grade 1\n");
    }
    else if(resp >16){
        printf("Grade 16+\n");
    }
    else{
        printf("Grade %d\n", resp);
    }


}

int count_letters(string text){
    int letra=0;
    for(int cont = 0; cont<strlen(text);cont++){
        if(isalpha(text[cont])){
            letra++;
        }
        else{
            continue;
        }
    }
    return letra;
}

int count_word(string text){
    int word=1;;
    char c = ' ';
    for(int cont = 0; cont<strlen(text);cont++){
        if(text[cont]==c){
            word++;
        }
        else{
            continue;
        }
    }
    return word;
}

int count_sentence(string text){
    int sentence=0;;
    char c = '.';
    for(int cont = 0; cont<strlen(text);cont++){
        if(text[cont]==c||text[cont]=='?'||text[cont]=='!'){
            sentence++;
        }
        else{
            continue;
        }
    }
    return sentence;
}

