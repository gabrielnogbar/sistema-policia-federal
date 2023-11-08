#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "viaturaLogin.h"
#include "../COPOM/resgistro-chamado.h"
void LoginViaturas(int op2, Policial *ptr, Viatura *ptrV,chamadoPolicial *ptrR, chamadoPolicial *ptrE){ // Aqui terei que passar o ponteiro inicial da lista de policiais, de viaturas.
    int codigoViatura,quantidadePM;
    int op;
    
    printf("Código da Viatura:\n");
    scanf(" %d", &codigoViatura);
    while(codigoViatura != ptrV->Codigo || ptrV->prox!=NULL){
        ptrV=ptrV->prox;
    }
    printf("Quantidade de Pms:");
    scanf(" %d", &quantidadePM);
    if ((op2==1 && quantidadePM>=2 && quantidadePM<=4)|| (op2==2 && quantidadePM==4 )){
        IdentificaPMs(quantidadePM, ptr, ptrV);// Aqui passar o ponteiro inicial dos policiais e o ponteiro da viatura usada.
        printf("1- Apto para atender ocorrência\n");
        printf("2- Cancelar Embarcação\n");
        scanf(" %d", &op);
        if (op==1){
            ptrV->Disponivel=1;
            //ViaturasDispoveis ++;

        }

    }
    else{
        printf("Quantidade de Policias errada\n");
    }

}
void IdentificaPMs(int quantidadePM, Policial *ptr, Viatura *ptrV){// 
    printf("Identificação dos PM");

    for(int i=1; i<=quantidadePM;i++){
        char *nome= (char *)malloc(sizeof(char));
        scanf(" %s",nome);
        ptrV->policiais[i]= &nome;
    }


}


