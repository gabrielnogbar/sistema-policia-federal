#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Login/viaturaLogin.h"
#include "COPOM/resgistro-chamado.h"

int main(){

    Viatura *ptrVI=NULL, *ptrVA=NULL; //Ponteiro para viaturas inicial e atual
    FILE * arquivoviaturas; //abrindo arquivo viaturas
    arquivoviaturas= fopen("../documentos/viaturas.txt","r");
    for(int i=0;i<10;i++){
        char tipo[50];
        struct Viatura *newViatura = (struct Viatura *)malloc(sizeof(struct Viatura)); //Criando Viatura
        fscanf(arquivoviaturas," %d", &newViatura->Codigo);
        fscanf(arquivoviaturas," %[^\n]",tipo);
        strcpy(newViatura->Tipo, tipo);
        printf(" %d %s", newViatura->Codigo, newViatura->Tipo);
        newViatura->prox=NULL;
        newViatura->Disponivel=1;
        if(ptrVA== NULL){
            ptrVA= newViatura;
            ptrVI= newViatura;
        }
        else{
            ptrVA->prox = newViatura;
            ptrVA=newViatura;
        }       
    }
    fclose(arquivoviaturas);

    Policial *ptrPoI=NULL, *ptrPoA=NULL; // Inicializando ponteiros dos policiais inicial ou atual
    FILE * arquivopolicia;
    arquivopolicia= fopen("../documentos/policiais.txt","r");
    for(int i=0; i<15; i++){
        struct Policial *policia = (struct Policial *)malloc(sizeof(struct Policial));
        fscanf(arquivopolicia," %[^\n]",policia->nome);
        fscanf(arquivopolicia," %d",&policia->CPF);
        fscanf(arquivopolicia," %[^\n]",policia->nomeGuerra);
        fscanf(arquivopolicia," %[^\n]",policia->cidade);
        fscanf(arquivopolicia," %d", &policia->idade);
        fscanf(arquivopolicia," %[^\n]",policia->cargo);
        fscanf(arquivopolicia," %[^\n]",policia->senha);
        policia->prox=NULL;
        if(ptrPoA==NULL){
            ptrPoA=policia;
            ptrPoI= policia;
        }
        else{
            ptrPoI->prox= policia;
            ptrPoI= policia;
        }
    }
    fclose(arquivopolicia);
    
    Pessoa *ptrPeI=NULL, *ptrPeA=NULL;
    FILE * arquivopessoas;
    arquivopessoas= fopen("../documentos/pessoas.txt","r");
    while(feof(arquivopessoas)==0){
        struct Pessoa *novapessoa= (struct Pessoa *)malloc(sizeof(struct Pessoa));
        fscanf(arquivopessoas,"  %[^\n]",novapessoa->nome);
        fscanf(arquivopessoas,"  %d",novapessoa->CPF);
        fscanf(arquivopessoas,"  %[^\n]",novapessoa->cidade);
        fscanf(arquivopessoas,"  %[^\n]",novapessoa->idade);
        fscanf(arquivopessoas,"  %[^\n]",novapessoa->numeropassagens);
        for (int i=0;i<novapessoa->numeropassagens;i++){
            char ocorrencia[19];
            fscanf(arquivopessoas," %[^\n]",novapessoa->passagens[i]);
        }
        fscanf(arquivopessoas, " %d",novapessoa->numeroinadimplencias);
        for( int i=0; i<novapessoa->numeroinadimplencias;i++){
            fscanf(arquivopessoas," %[^\n]",novapessoa->inadimpencias[i]);
        }
        if(ptrPeI==NULL){
            ptrPeA= novapessoa;
            ptrPeI= novapessoa;
        }
        else{
            ptrPeI->prox=novapessoa;
            ptrPeI=novapessoa;
        }
    }
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
            Policial *ptrReservaP;
            Viatura  *ptrReservaV;
            ptrReservaP= ptrPoI;
            ptrReservaV= ptrVI;
            LoginViatura(op2, ptrReservaP, ptrReservaV);
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