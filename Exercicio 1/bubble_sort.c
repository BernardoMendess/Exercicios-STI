//Ordenar uma lista de nomes de alunos usando dois algoritmos de busca


#include <stdio.h>
#include <string.h>

#define TAM 10


void bubble_sort(char nomes[TAM][50]){
    char aux[50];
    for(int i = 0; i < TAM; i++){
        for(int j = 0; j < TAM-1-i; j++){
            if(strcmp(nomes[j], nomes[j + 1]) > 0){
                strcpy(aux, nomes[j]);
                strcpy(nomes[j], nomes[j + 1]);
                strcpy(nomes[j + 1], aux);
            }
        }   
    }
}


int main(){
    char nomes[TAM][50];
    char x;
    printf("Digite os nomes: \n");
    for(int i = 0; i < TAM; i++){
        gets(nomes[i]);
    }
    bubble_sort(nomes);
    printf("Nomes ordenados: ");
    for(int i = 0; i < TAM; i++){
        if (i != TAM - 1){
            printf("%s, ", nomes[i]);
        }
        else{
            printf("%s", nomes[i]);
        }
    }
    printf("\nPressione qualquer tecla para encerrar");
    scanf("%c", &x);
    return 0;
}