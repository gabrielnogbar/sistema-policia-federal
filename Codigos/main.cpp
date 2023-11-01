#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Login/viaturaLogin.h"
#include "COPOM/resgistro-chamado.h"

int main(){

    Viatura *ptrVI=NULL, *ptrVA=NULL; //Ponteiro para viaturas inicial e atual
    FILE * arquivoviaturas; //abrindo arquivo viaturas
    arquivoviaturas= fopen(".\\documentos\\viaturas.txt","r");
    for(int i=0;i<10;i++){
        struct Viatura *newViatura = (struct Viatura *)malloc(sizeof(struct Viatura)); //Criando Viatura
        fscanf(arquivoviaturas, " %d", &newViatura->Codigo);
        fscanf(arquivoviaturas, " %[^\n]",newViatura->Tipo);
        newViatura->prox=NULL;
        if(ptrVA== NULL){
            ptrVA= newViatura;
            ptrVI= newViatura;
        }
        else{
            ptrVI->prox = newViatura;
            ptrVI=newViatura;
        }
        
    }
    fclose(arquivoviaturas);
    // Criação das filas de chamados:
    // chamadoPolicial *iRegular = NULL, *fRegular = NULL; // Criacao da fila regular nao prioritaria

    // chamadoPolicial *iRegularPrioritaria = NULL, *fRegularPrioritaria = NULL; // Criacao da fila regular prioritaria

    // chamadoPolicial *iEspecializada = NULL, *fEspecializada = NULL; // Criacao da fila especializada
    
    int op=10;
    do{
        printf("\n1 - Viatura Login\n");
        printf("2 - Viatura em uso\n");
        printf("3 - COPOM\n");
        printf("4 - Policial Militar\n");
        printf("5 - Oficial\n");
        printf("6 - Comandante Geral\n");
        printf("0 - Encerrar Programa\n");
        scanf(" %d", &op);

        if (op==1){
            int op2=0;
            printf("1 - Policia Regular\n");
            printf("2 - Policia Especializada\n");
            scanf(" %d", &op2);
            //RegistrarViatura(op2);
        }
        else if(op==2){
            printf("Ainda não disponivel");
        }
        else if(op==3){
           // printf("Resgistrar chamado: ");
            //copomRegistroChamado(iRegular, fRegular, iRegularPrioritaria, fRegularPrioritaria, iEspecializada, fEspecializada);
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