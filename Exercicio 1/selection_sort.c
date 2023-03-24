//Ordenar uma lista de nomes de alunos usando dois algoritmos de busca


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct no{
    char nome[50];
    struct no *proximo;
}No;


No* insere_inicio(No *l){
    No *novo = (No*)malloc(sizeof(No));
    fflush(stdin);
    printf("Digite um nome: ");
    gets(novo->nome);
    if(!l){
        novo->proximo = NULL;
        l = novo;
    }
    else{
        novo->proximo = l;
        l = novo;
    }
    return l;
}


No* insere_fim(No *l){
    if(!l){
        l = insere_inicio(l);
    }
    else{
        No *novo = (No*)malloc(sizeof(No));
        fflush(stdin);
        printf("Digite um nome: ");
        gets(novo->nome);
        novo->proximo = NULL;
        No *aux = l;
        while(1){
            if(aux->proximo == NULL){
                aux->proximo = novo;
                break;
            }
            else{
                aux = aux->proximo;
            }
        }
    }
    return l;
}


void imprimir(No *l){
    if(!l){
        return;
    }
    else{
        No *aux = (No*)malloc(sizeof(No));
        aux = l;
        while(1){
            if(aux->proximo){
                printf("%s, ", aux->nome);
                aux = aux->proximo;
            }
            else{
                printf("%s\n", aux->nome);
                break;
            }
        }
    }
}


void selection_sort(No *l){
    if(!l){
        return;
    }
    else{
        char aux[50];
        for(No* i = l; i->proximo != NULL; i = i->proximo){
            No* menor = i;
            for(No* j = i->proximo; j != NULL; j = j->proximo){
                if(strcmp(menor->nome, j->nome) > 0){
                    menor = j;
                }
            }
            strcpy(aux, i->nome);
            strcpy(i->nome, menor->nome);
            strcpy(menor->nome, aux);
        }
    }
}


int main(void){
    No *l = NULL;
    int escolha;
    for(;;){
        printf("Escolha uma opcao:\n1-inserir inicio\n2-inserir no fim\n3-imprimir\n4-ordernar\n5-sair\n");
        scanf("%d", &escolha);
        if(escolha == 5){
            break;
        }
        switch(escolha){
        case 1:
            l = insere_inicio(l);
            break;
        case 2:
            l = insere_fim(l);
            break;
        case 3:
            imprimir(l);
            break;
        case 4:
            selection_sort(l);
            break;
        }
    }
}