#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
char alfa[] =  {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h','i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's' ,'t' , 'u' , 'v', 'w', 'x' , 'y' ,'z'};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if(score1>score2){
        printf("Player 1 wins!");
    }
    else if(score2>score1){
        printf("Player 2 wins!");
    }
    else{
        printf("Tie");
    }
}

int compute_score(string word)
{
    // TODO: Compute and return score for string
    int soma = 0;
    for(int cont =0;cont < strlen(word); cont++){
        char aux = word[cont];
        word[cont] = tolower(word[cont]);
    }
    for(int cont =0;cont < strlen(word); cont++){
        for(int cont1=0;cont1<26;cont1++){
            if(word[cont]==alfa[cont1]){
                soma +=POINTS[cont1];
            }
        }
    }
    return soma;

}
