#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "./COPOM/registro-chamado.h"

int main(){
    int LogadasR=0, LogadasE=0;
    Viatura *ptrVI=NULL, *ptrVA=NULL; //Ponteiro para viaturas inicial e atual
    FILE * arquivoviaturas; //abrindo arquivo viaturas
    arquivoviaturas= fopen("../documentos/viaturas.txt","r");
    for(int i=0;i<10;i++){
        char tipo[50];
        struct Viatura *newViatura = (struct Viatura *)malloc(sizeof(struct Viatura)); //Criando Viatura
        newViatura->chamadoAtual=NULL;
        newViatura->Logado=0;
        fscanf(arquivoviaturas," %d", &newViatura->Codigo);
        fscanf(arquivoviaturas," %[^\n]",tipo);
        strcpy(newViatura->Tipo, tipo);
        printf(" %d %s", newViatura->Codigo, newViatura->Tipo);
        newViatura->prox=NULL;
        if(strcmp(newViatura->Tipo, "regular")==0){
            newViatura->tipo=0;
        }
        else{
            newViatura->tipo=1;
        }
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
            ptrPoA->prox= policia;
            ptrPoA= policia;
        }
    }
    fclose(arquivopolicia);
    
    Pessoa *ptrPeI=NULL, *ptrPeA=NULL;
    FILE * arquivopessoas;
    arquivopessoas= fopen("../documentos/pessoas.txt","r");
    while(!feof(arquivopessoas)){
        struct Pessoa *novapessoa= (struct Pessoa *)malloc(sizeof(struct Pessoa));
        fscanf(arquivopessoas,"  %[^\n]",novapessoa->nome);
        fscanf(arquivopessoas," %11s",novapessoa->CPF);
        //printf("%s\n",novapessoa->CPF);
        fscanf(arquivopessoas,"  %[^\n]",novapessoa->cidade);
        fscanf(arquivopessoas,"  %d",&novapessoa->idade);
        fscanf(arquivopessoas,"  %d",&novapessoa->numeropassagens);
        for (int i=0;i<novapessoa->numeropassagens;i++){
            fscanf(arquivopessoas," %[^\n]",novapessoa->passagens[i]);
            //printf("%s \n ", novapessoa->passagens[i]);
        }
        fscanf(arquivopessoas, " %d",&novapessoa->numeroinadimplencias);
        for( int i=0; i<novapessoa->numeroinadimplencias;i++){
            fscanf(arquivopessoas," %[^\n]",novapessoa->inadimpencias[i]);
        }
        if(ptrPeI==NULL){
            ptrPeA= novapessoa;
            ptrPeI= novapessoa;
        }
        else{
            ptrPeA->prox=novapessoa;
            ptrPeA=novapessoa;
        }
    }
    fclose(arquivopessoas);
    // Criação das filas de chamados:
    /*
        O ponteiro "I" representara o primeiro chamado a ser atendido;
        O ponteiro "F" representara o ultimo chamado da fila;
        O ponteiro "Prioridade" representa o ultimo chamado prioritario;
    */
    chamadoPolicial *iRegular = NULL, *fRegular = NULL; // Criacao da fila regular nao prioritaria

    chamadoPolicial *iEspecializada = NULL, *fEspecializada = NULL; // Criacao da fila especializada

    chamadoPolicial *prioridade = NULL; // Ponteito que aponta para o final da fila de prioridade

    chamadoPolicial *pilhaChamadosResolvidos = NULL; // pilha com todos os chamados resolvido
   
    int op=10;
    do{
        distribuidorChamado(ptrVI,iRegular,iEspecializada);
        printf("\n1 - Viatura Login\n");
        printf("2 - Viatura em uso\n");
        printf("3 - COPOM\n");
        printf("4 - Policial Militar\n");
        printf("5 - Oficial\n");
        printf("6 - Comandante Geral\n");
        printf("0 - Encerrar Programa\n");
        scanf("%d", &op);

        if (op==1){
            int op2=0;
            printf("1 - Policia Regular\n");
            printf("2 - Policia Especializada\n");
            scanf(" %d", &op2);
            Policial *ptrReservaP;
            Viatura  *ptrReservaV;
            ptrReservaP= ptrPoI;
            ptrReservaV= ptrVI;
            LoginViaturas(op2, ptrReservaP, ptrReservaV,iRegular,iEspecializada,LogadasR,LogadasE, ptrPeI);
        }
        else if(op==2){
            printf("Informe o codigo da Viatura:\n ");
            int codigoV;
            scanf(" %d",&codigoV);
            VerificaUso(codigoV,ptrVI,ptrPeI);

        }
        else if(op==3){
            printf("Resgistrar chamado: \n");
            copomRegistroChamado(iRegular, fRegular, prioridade, iEspecializada, fEspecializada);
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

        // Opçõe para teste
        else if (op==17)
        {
            chamadoPolicial* teste = desenfilerar(iRegular);
            empilharChamadoResolvido(teste, pilhaChamadosResolvidos);
         
        }
        else if (op==18)
        {
            chamadoPolicial* teste = desenfilerar(iEspecializada);
            empilharChamadoResolvido(teste, pilhaChamadosResolvidos);
        }
        


    }while(op!=0);

    return 0;
}