#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image o grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float cinza = 0;
    float div = 3;
    for(int linha = 0;linha<height;linha++){
        for(int coluna = 0;coluna<width;coluna++){
            cinza = round(((image[linha][coluna].rgbtBlue)+(image[linha][coluna].rgbtGreen)+(image[linha][coluna].rgbtRed))/div);
            image[linha][coluna].rgbtBlue = cinza;
            image[linha][coluna].rgbtRed = cinza;
            image[linha][coluna].rgbtGreen = cinza;
        }
    }
    return;
}

//Limite
int limite(int RGB)
{
    if (RGB > 255)
    {
        RGB = 255;
    }
    return RGB;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width]){
    int sepiaRed = 0;
    int sepiaGreen = 0;
    int sepiaBlue = 0;
    for(int linha = 0;linha<height;linha++){
        for(int coluna = 0;coluna<width;coluna++){
            sepiaRed = limite(round(((0.393*image[linha][coluna].rgbtRed)+(0.769*image[linha][coluna].rgbtGreen)+(0.189*image[linha][coluna].rgbtBlue))));
            sepiaGreen = limite(round((0.349*image[linha][coluna].rgbtRed+0.686*image[linha][coluna].rgbtGreen+0.168*image[linha][coluna].rgbtBlue)));
            sepiaBlue = limite(round(((0.272*image[linha][coluna].rgbtRed)+(0.534*image[linha][coluna].rgbtGreen)+(0.131*image[linha][coluna].rgbtBlue))));
            image[linha][coluna].rgbtRed = sepiaRed;
            image[linha][coluna].rgbtGreen = sepiaGreen;
            image[linha][coluna].rgbtBlue = sepiaBlue;

        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width]){

    for(int linha = 0;linha<height;linha++){
        for(int coluna = 0;coluna<width/2;coluna++){
            int tempRed = 0;
            int tempBlue = 0;
            int tempGreen = 0;
            int limite = height/2;
                tempRed = image[linha][coluna].rgbtRed;
                tempBlue = image[linha][coluna].rgbtBlue;
                tempGreen = image[linha][coluna].rgbtGreen;
                image[linha][coluna].rgbtRed = image[linha][width-coluna-1].rgbtRed;
                image[linha][coluna].rgbtBlue = image[linha][width-coluna-1].rgbtBlue;
                image[linha][coluna].rgbtGreen = image[linha][width-coluna-1].rgbtGreen;
                image[linha][width-coluna-1].rgbtRed = tempRed;
                image[linha][width-coluna-1].rgbtBlue = tempBlue;
                image[linha][width-coluna-1].rgbtGreen = tempGreen;

                    }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE image1[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image1[i][j] = image[i][j];
        }
    }

    for(int linha = 0;linha<height;linha++){
        for(int coluna = 0;coluna<width;coluna++){
            int auxRed = 0;
            int auxBlue = 0;
            int auxGreen = 0;
            if((linha==0)&&(coluna==0)){
                auxRed = round((image1[linha][coluna].rgbtRed+image1[linha][coluna+1].rgbtRed+image1[linha+1][coluna].rgbtRed+image1[linha+1][coluna+1].rgbtRed)/4.00);
                auxBlue = round((image1[linha][coluna].rgbtBlue+image1[linha][coluna+1].rgbtBlue+image1[linha+1][coluna].rgbtBlue+image1[linha+1][coluna+1].rgbtBlue)/4.00);
                auxGreen = round((image1[linha][coluna].rgbtGreen+image1[linha][coluna+1].rgbtGreen+image1[linha+1][coluna].rgbtGreen+image1[linha+1][coluna+1].rgbtGreen)/4.00);
                image[linha][coluna].rgbtRed = auxRed;
                image[linha][coluna].rgbtBlue = auxBlue;
                image[linha][coluna].rgbtGreen = auxGreen;
            }
            else if((linha==0)&&(coluna==(width-1))){
                auxRed = round((image1[linha][coluna].rgbtRed+image1[linha][coluna-1].rgbtRed+image1[linha+1][coluna].rgbtRed+image1[linha+1][coluna-1].rgbtRed)/4.00);
                auxBlue = round((image1[linha][coluna].rgbtBlue+image1[linha][coluna-1].rgbtBlue+image1[linha+1][coluna].rgbtBlue+image1[linha+1][coluna-1].rgbtBlue)/4.00);
                auxGreen = round((image1[linha][coluna].rgbtGreen+image1[linha][coluna-1].rgbtGreen+image1[linha+1][coluna].rgbtGreen+image1[linha+1][coluna-1].rgbtGreen)/4.00);
                image[linha][coluna].rgbtRed = auxRed;
                image[linha][coluna].rgbtBlue = auxBlue;
                image[linha][coluna].rgbtGreen = auxGreen;
            }
            else if((linha==(height-1))&&(coluna==0)){
                auxRed = round((image1[linha][coluna].rgbtRed+image1[linha][coluna+1].rgbtRed+image1[linha-1][coluna].rgbtRed+image1[linha-1][coluna+1].rgbtRed)/4.00);
                auxBlue = round((image1[linha][coluna].rgbtBlue+image1[linha][coluna+1].rgbtBlue+image1[linha-1][coluna].rgbtBlue+image1[linha-1][coluna+1].rgbtBlue)/4.00);
                auxGreen = round((image1[linha][coluna].rgbtGreen+image1[linha][coluna+1].rgbtGreen+image1[linha-1][coluna].rgbtGreen+image1[linha-1][coluna+1].rgbtGreen)/4.00);
                image[linha][coluna].rgbtRed = auxRed;
                image[linha][coluna].rgbtBlue = auxBlue;
                image[linha][coluna].rgbtGreen = auxGreen;
            }
            else if((linha==(height-1))&&(coluna==(width-1))){
                //printf("%d + %d\n",linha,coluna);
                auxRed = round((image1[linha][coluna].rgbtRed+image1[linha][coluna-1].rgbtRed+image1[linha-1][coluna].rgbtRed+image1[linha-1][coluna-1].rgbtRed)/4.00);
                auxBlue = round((image1[linha][coluna].rgbtBlue+image1[linha][coluna-1].rgbtBlue+image1[linha-1][coluna].rgbtBlue+image1[linha-1][coluna-1].rgbtBlue)/4.00);
                auxGreen = round((image1[linha][coluna].rgbtGreen+image1[linha][coluna-1].rgbtGreen+image1[linha-1][coluna].rgbtGreen+image1[linha-1][coluna-1].rgbtGreen)/4.00);
                image[linha][coluna].rgbtRed = auxRed;
                image[linha][coluna].rgbtBlue = auxBlue;
                image[linha][coluna].rgbtGreen = auxGreen;
            }
            else if((linha==0)&&((coluna>0)||(coluna<(width-1)))){
                auxRed = round((image1[linha][coluna].rgbtRed+image1[linha][coluna-1].rgbtRed+image1[linha+1][coluna-1].rgbtRed+image1[linha+1][coluna].rgbtRed+image1[linha+1][coluna+1].rgbtRed+image1[linha][coluna+1].rgbtRed)/6.00);
                auxBlue = round((image1[linha][coluna].rgbtBlue+image1[linha][coluna-1].rgbtBlue+image1[linha+1][coluna-1].rgbtBlue+image1[linha+1][coluna].rgbtBlue+image1[linha+1][coluna+1].rgbtBlue+image1[linha][coluna+1].rgbtBlue)/6.00);
                auxGreen = round((image1[linha][coluna].rgbtGreen+image1[linha][coluna-1].rgbtGreen+image1[linha+1][coluna-1].rgbtGreen+image1[linha+1][coluna].rgbtGreen+image1[linha+1][coluna+1].rgbtGreen+image1[linha][coluna+1].rgbtGreen)/6.00);
                image[linha][coluna].rgbtRed = auxRed;
                image[linha][coluna].rgbtBlue = auxBlue;
                image[linha][coluna].rgbtGreen = auxGreen;
            }
            else if(linha==(height-1)){
                auxRed = round((image1[linha][coluna].rgbtRed+image1[linha][coluna-1].rgbtRed+image1[linha-1][coluna-1].rgbtRed+image1[linha-1][coluna].rgbtRed+image1[linha-1][coluna+1].rgbtRed+image1[linha][coluna+1].rgbtRed)/6.00);
                auxBlue = round((image1[linha][coluna].rgbtBlue+image1[linha][coluna-1].rgbtBlue+image1[linha-1][coluna-1].rgbtBlue+image1[linha-1][coluna].rgbtBlue+image1[linha-1][coluna+1].rgbtBlue+image1[linha][coluna+1].rgbtBlue)/6.00);
                auxGreen = round((image1[linha][coluna].rgbtGreen+image1[linha][coluna-1].rgbtGreen+image1[linha-1][coluna-1].rgbtGreen+image1[linha-1][coluna].rgbtGreen+image1[linha-1][coluna+1].rgbtGreen+image1[linha][coluna+1].rgbtGreen)/6.00);
                image[linha][coluna].rgbtRed = auxRed;
                image[linha][coluna].rgbtBlue = auxBlue;
                image[linha][coluna].rgbtGreen = auxGreen;
            }
            else if(coluna==0){
                auxRed = round((image1[linha][coluna].rgbtRed+image1[linha-1][coluna].rgbtRed+image1[linha-1][coluna+1].rgbtRed+image1[linha][coluna+1].rgbtRed+image1[linha+1][coluna+1].rgbtRed+image1[linha+1][coluna].rgbtRed)/6.00);
                auxBlue = round((image1[linha][coluna].rgbtBlue+image1[linha-1][coluna].rgbtBlue+image1[linha-1][coluna+1].rgbtBlue+image1[linha][coluna+1].rgbtBlue+image1[linha+1][coluna+1].rgbtBlue+image1[linha+1][coluna].rgbtBlue)/6.00);
                auxGreen = round((image1[linha][coluna].rgbtGreen+image1[linha-1][coluna].rgbtGreen+image1[linha-1][coluna+1].rgbtGreen+image1[linha][coluna+1].rgbtGreen+image1[linha+1][coluna+1].rgbtGreen+image1[linha+1][coluna].rgbtGreen)/6.00);
                image[linha][coluna].rgbtRed = auxRed;
                image[linha][coluna].rgbtBlue = auxBlue;
                image[linha][coluna].rgbtGreen = auxGreen;
            }
            else if(coluna==(width-1)){
                auxRed = round((image1[linha][coluna].rgbtRed+image1[linha-1][coluna].rgbtRed+image1[linha-1][coluna-1].rgbtRed+image1[linha][coluna-1].rgbtRed+image1[linha+1][coluna-1].rgbtRed+image1[linha+1][coluna].rgbtRed)/6.00);
                auxBlue = round((image1[linha][coluna].rgbtBlue+image1[linha-1][coluna].rgbtBlue+image1[linha-1][coluna-1].rgbtBlue+image1[linha][coluna-1].rgbtBlue+image1[linha+1][coluna-1].rgbtBlue+image1[linha+1][coluna].rgbtBlue)/6.00);
                auxGreen = round((image1[linha][coluna].rgbtGreen+image1[linha-1][coluna].rgbtGreen+image1[linha-1][coluna-1].rgbtGreen+image1[linha][coluna-1].rgbtGreen+image1[linha+1][coluna-1].rgbtGreen+image1[linha+1][coluna].rgbtGreen)/6.00);
                image[linha][coluna].rgbtRed = auxRed;
                image[linha][coluna].rgbtBlue = auxBlue;
                image[linha][coluna].rgbtGreen = auxGreen;
            }
            else{
                auxRed = round((image1[linha][coluna].rgbtRed+image1[linha-1][coluna-1].rgbtRed+image1[linha-1][coluna].rgbtRed+image1[linha-1][coluna+1].rgbtRed+image1[linha][coluna-1].rgbtRed+image1[linha][coluna+1].rgbtRed+image1[linha+1][coluna-1].rgbtRed+image1[linha+1][coluna].rgbtRed+image1[linha+1][coluna+1].rgbtRed)/9.00);
                auxBlue = round((image1[linha][coluna].rgbtBlue+image1[linha-1][coluna-1].rgbtBlue+image1[linha-1][coluna].rgbtBlue+image1[linha-1][coluna+1].rgbtBlue+image1[linha][coluna-1].rgbtBlue+image1[linha][coluna+1].rgbtBlue+image1[linha+1][coluna-1].rgbtBlue+image1[linha+1][coluna].rgbtBlue+image1[linha+1][coluna+1].rgbtBlue)/9.0);
                auxGreen = round((image1[linha][coluna].rgbtGreen+image1[linha-1][coluna-1].rgbtGreen+image1[linha-1][coluna].rgbtGreen+image1[linha-1][coluna+1].rgbtGreen+image1[linha][coluna-1].rgbtGreen+image1[linha][coluna+1].rgbtGreen+image1[linha+1][coluna-1].rgbtGreen+image1[linha+1][coluna].rgbtGreen+image1[linha+1][coluna+1].rgbtGreen)/9.00);
                image[linha][coluna].rgbtRed = auxRed;
                image[linha][coluna].rgbtBlue = auxBlue;
                image[linha][coluna].rgbtGreen = auxGreen;
            }


        }
    }
    return;
}
