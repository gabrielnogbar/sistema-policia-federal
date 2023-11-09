#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "viaturaLogin.h"
#include "../COPOM/resgistro-chamado.h"
void LoginViaturas(int op2, Policial *ptr, Viatura *ptrV,chamadoPolicial *&ptrR, chamadoPolicial *&ptrE,int &DisponiveisR, int &DisponiveisE,Pessoa *ptrP){ // Aqui terei que passar o ponteiro inicial da lista de policiais, de viaturas.
    int codigoViatura,quantidadePM;
    int op;
    Viatura *prtVI= ptrV; //Criando um ponteiro reserva pra percorrer em caso de chamado
    
    printf("Código da Viatura:\n");
    scanf(" %d", &codigoViatura);
    while(codigoViatura != ptrV->Codigo || ptrV!=NULL){
        ptrV=ptrV->prox;
    }
    ptrV->Logado=1;
    printf("Quantidade de Pms: ");
    scanf(" %d", &quantidadePM);
    if ((op2==1 && quantidadePM>=2 && quantidadePM<=4)|| (op2==2 && quantidadePM==4 )){
        IdentificaPMs(quantidadePM, ptr, ptrV);// Aqui passar o ponteiro inicial dos policiais e o ponteiro da viatura usada.
        while(op!=2){
        printf("1- Apto para atender ocorrência\n");
        printf("2- Cancelar Embarcação\n");
        scanf(" %d", &op);
        if(op==1){
        if ((ptrR!=NULL) && (op2==1)){
            DisponiveisR ++;
            if(ptrR->quantViaturas<=DisponiveisR){
                int temp=0;
                for(Viatura *p=prtVI;p!=NULL && temp!=ptrR->quantViaturas;p=p->prox){
                    if(p->Logado==1 && p->tipo==0){
                        p->qtdChamado++;
                        temp++;
                    }
                }
                ptrR=ptrR->prox;
                Caso(ptrV,ptrP,ptrR);
            }
            else{
                    printf("Numero de Viaturas Insuficientes para atender o Chamado\n");
                }
            }
        else if((op2==1 && ptrR==NULL)){
            printf(" Sem chamados no momento, VIatura colocada para ronda, Voltando para o menu principal\n");
            op=2;
            DisponiveisR ++;
        }
        else if(( op2==2 && ptrE==NULL)){
            printf(" Sem chamados no momento, VIatura colocada para ronda, Voltando para o menu principal\n");
            DisponiveisE ++;
            op=2;
        }
        else if(op2==2 && ptrE!=NULL){
            DisponiveisE ++;
            if(ptrE->quantViaturas<=DisponiveisE){
                int temp=0;
                for(Viatura *p=prtVI;p!=NULL && temp!=ptrE->quantViaturas;p=p->prox){
                    if(p->Logado==1 && p->tipo==1){
                        p->qtdChamado++;
                        temp++;
                    }
                DisponiveisE= DisponiveisE - ptrR->quantViaturas;
                }
                ptrE=ptrE->prox;
                Caso(ptrV,ptrP,ptrE);
        }
            else{
                printf("Numero de Viaturas Insuficientes para atender o Chamado\n");
            }

    }
        }
    }
}
    else{
        printf("\nQuantidade de Policias errada\n");
    }

    }
    


void IdentificaPMs(int quantidadePM, Policial *ptr, Viatura *ptrV){  
    printf("\nIdentificação dos PM");
    printf(" \n Nome de Guerra dos policiais:");
    for(int i=1; i<=quantidadePM;i++){
        char nome[30];
        scanf(" %s",nome);
        strcpy(ptrV->policiais[i], nome);
    }
    printf("\n");

}
void Caso(Viatura *ptrV,Pessoa *ptrP,chamadoPolicial *&ptrC){
    printf("Descrição: %s \n",ptrC->descricao);
    printf("Localização: %s \n", ptrC->local);
    printf(" 1- Confirmar ação policial       2- Ação Dispensada");
    int op;
    scanf(" %d",&op);
    if(op=1){
        FunçõesChamada(ptrP);
    }


}

void FunçõesChamada(Pessoa *ptrP){
    int op=0;
    do{
    printf("1 - Pesquisar por CPF\n");
    printf("2 - Solicitar Reforço\n");
    printf("3 - Prisão em Andamento \n");
    printf("4 - Encerrar Ocorrencia\n");
    scanf(" %d",&op);

    if(op==1){
        PesquisarCPF(ptrP);
    }
    

}while(op!=4);
}

void PesquisarCPF(Pessoa *ptrP){
    char CPF[11];
    printf("CPF: ");
    scanf(" %[^\n]", CPF);
    for(Pessoa *p=ptrP; p!=NULL; p=p->prox){
        if(strcmp(p->CPF, CPF)==0){
            printf("\n Nome: %s",p->nome);
            printf("\n Cidade: %s",p->cidade);
            printf("\n Idade: %d",p->idade);
            printf("\n Numero de passagens:  %d",p->numeropassagens);
            printf("\n Numero de Inandimplencias: %d \n",p->numeroinadimplencias);
        }
}}
