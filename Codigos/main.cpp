#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "viaturaLogin.h"
#include "COPOM/resgistro-chamado.h"

int main(){
    int op=10;
    do{
        printf("1 - Viatura Login\n");
        printf("2 - Viatura em uso\n");
        printf("3 - COPOM\n");
        printf("4 - Policial Militar\n");
        printf("5 - Oficial\n");
        printf("6 - Comandante Geral\n");
        printf("0 - Encerrar Programa");
        scanf(" %d", &op);

        if (op==1){
            int op2=0;
            printf("1 - Policia Regular\n");
            printf("2 - Policia Especializada\n");
            scanf(" %d", &op2);
            RegistrarViatura(op2);
        }
        else if(op==2){
            printf("Ainda não disponivel");
        }
        else if(op==3){
            printf("Ainda não disponivel");
        }
        else if(op==4){
            printf("Ainda não disponivel");
        }
        else if(op==5){
            printf("Ainda não disponivel");
        }
        else if(op==6){
            printf("Ainda não disponivel");
        }


    }while(op!=0);
}