//Construir algoritmo de geração de número fatorial (N!) recursivo e não-recursivo

#include<stdio.h>


int fatorial_nao_recursivo(int num){
    int fatorial = 1;
    for(int i = num; i > 0; i--){
        fatorial *= i;
    }
    return fatorial;
}


int fatorial_recursivo(int num){
    int fatorial;
    if (num == 1){
        return num;
    }
    else{
        fatorial = num * fatorial_recursivo(num - 1);
        return fatorial;
    }
}   


int main(){
    int num, escolha;
    for(;;){
        printf("Qual metodo deseja utilizar? \n1- Recursiva \n2- Nao recursiva \n3- Sair \n");
        scanf("%d", &escolha);
        if (escolha == 1){
            printf("Digite um numero: ");
            scanf("%d", &num);
            printf("%d\n", fatorial_recursivo(num));
        }
        else if (escolha == 2){
            printf("Digite um numero: ");
            scanf("%d", &num);
            printf("%d\n", fatorial_nao_recursivo(num));
        }
        else if (escolha == 3){
            break;
        }
        else{
            printf("Opcao invalida\n");
        }
    }

    return 0;
}