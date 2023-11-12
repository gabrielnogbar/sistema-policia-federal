#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "viaturaLogin.h"
#include "../COPOM/registro-chamado.h"

void LoginViaturas(int op2, Policial *ptr, Viatura *ptrV,chamadoPolicial *&ptrR, chamadoPolicial *&ptrE,int &DisponiveisR, int &DisponiveisE,Pessoa *ptrP)
// ptrR ponteiro de chamado Regular
// ptrE Ponteiro de chamado especializada
{ // Aqui terei que passar o ponteiro inicial da lista de policiais, de viaturas.
    int codigoViatura,quantidadePM;
    int op=0;
    Viatura *prtVI= ptrV; //Criando um ponteiro reserva pra percorrer em caso de chamado
    
    printf("Código da Viatura:\n");
    scanf(" %d", &codigoViatura);
    while(codigoViatura != ptrV->Codigo || ptrV!=NULL){
        ptrV=ptrV->prox;
    }
    ptrV->Logado=1;
    if(ptrV->Logado==1){
        ViaturaAtendimento(op2,ptr, ptrV,ptrR,ptrE,DisponiveisR, DisponiveisE,ptrP);
    }
}
void ViaturaAtendimento(int op2, Policial *ptr, Viatura *ptrV,chamadoPolicial *&ptrR, chamadoPolicial *&ptrE,int &DisponiveisR, int &DisponiveisE,Pessoa *ptrP){
    printf("Quantidade de Pms: ");
    int quantidadePM;
    int op=0;
    scanf(" %d", &quantidadePM);
    if ((op2==1 && quantidadePM>=2 && quantidadePM<=4)|| (op2==2 && quantidadePM==4 )){
        IdentificaPMs(quantidadePM, ptr, ptrV);// Aqui passar o ponteiro inicial dos policiais e o ponteiro da viatura usada.
            printf("1- Apto para atender ocorrência\n");
            printf("2- Cancelar Embarcação\n");
            scanf(" %d", &op);
            if(op==1){
                if ((ptrR!=NULL) && (op2==1)){
                    ptrR->viaturaDoChamada=ptrV;
                    ptrV->qtdChamado++;
                    ptrV->chamadoAtual=ptrR;
                    ptrR= ptrR->prox;
                    Caso(ptrV,ptrP);
                    DisponiveisR++;
                    ptrV->disponivel=0;
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
                    ptrV->disponivel=0;
                }
                else if(op2==2 && ptrE!=NULL){
                    ptrE->viaturaDoChamada=ptrV;
                    ptrV->qtdChamado++;
                    ptrV->chamadoAtual=ptrE;
                    ptrE= ptrE->prox;
                    Caso(ptrV,ptrP);
                    DisponiveisE++;
                    ptrV->disponivel=0;
                }

            else{
                printf("Cancelando embarcação \n");
                ptrV->Logado=0;
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
void Caso(Viatura *ptrV,Pessoa *ptrP){
    printf("Descrição: %s \n",ptrV->chamadoAtual->descricao);
    printf("Localização: %s \n", ptrV->chamadoAtual->local);
    printf(" 1- Confirmar ação policial       2- Ação Dispensada");
    int op;
    scanf(" %d",&op);
    if(op==1){
        funcoesChamada(ptrP);
}
    ptrV->chamadoAtual->resolvido=1;
    ptrV->chamadoAtual=NULL;
    } 

void funcoesChamada(Pessoa *ptrP){
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
    }  
}
