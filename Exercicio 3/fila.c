//Construa um algoritmo para fila com suas quatro operações: inserir,  remover, tamanho e próximo a sair da fila

#include <stdlib.h>
#include <stdio.h>


typedef struct no{
    int valor;
    struct no *proximo;
}No;


typedef struct Fila{
    No *inicio;
    No *fim;
}Fila;


Fila *inserir(Fila *f,int x){
    No *novo = (No*)malloc(sizeof(No));
    novo->proximo = NULL;
    novo->valor = x;
    if(!f->inicio){
        f->inicio = novo;
        f->fim = novo;
    }
    else{
        f->fim->proximo = novo;
        f->fim = novo;
    }
    return f;
}


int retirar(Fila *f){
    if(!f->inicio){
        printf("A fila esta vazia\n");
        return 0;
    }
    else{
        int valor = f->inicio->valor;
        No *aux = f->inicio;
        f->inicio = f->inicio->proximo;
        if(!f->inicio){
            f->fim = NULL;
        }
        free(aux);
        return valor;
    }
}


int quantidade_de_elementos(Fila *f){
    if(!f->inicio){
        return 0;
    }
    else{
        int contador = 0;
        No *aux = f->inicio;
        while(1){
            if(aux != f->fim){
                contador += 1;
                aux = aux->proximo;
            }
            else{
                contador += 1;
                break;
            }
        }
        return contador;
    }
}


void proximo_a_sair(Fila *f){
    if(!f->inicio){
        printf("A fila esta vazia\n");
    }
    else{
        printf("O proximo valor a sair e: %d\n", f->inicio->valor);
    }
}


int main(void){
    Fila *f = (Fila*)malloc(sizeof(Fila));
    f->fim = NULL;
    f->inicio = NULL;
    int escolha, num, valor;
    for(;;){
        printf("Escolha uma opcao:\n1-inserir\n2-retirar\n3-tamanho\n4-proximo a sair\n5-sair\n");
        scanf("%d", &escolha);
        if(escolha == 5){
            break;
        }
        switch(escolha){
        case 1:
            printf("Digite um numero: ");
            scanf("%d", &num);
            f = inserir(f, num);
            break;
        case 2:
            valor = retirar(f);
            break;
        case 3:
            printf("A fila tem %d elementos\n", quantidade_de_elementos(f));
            break;
        case 4:
            proximo_a_sair(f);
            break;
        }
    }
}