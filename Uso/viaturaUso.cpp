#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../Login/viaturaLogin.h"

void VerificaUso(int Codigo, Viatura *ptr,Pessoa *ptrP){
    for(ptr;ptr->Codigo!=Codigo || ptr==NULL;ptr=ptr->prox){
        if(ptr->Codigo==Codigo){
            TemChamado(ptr,ptrP);
        }
    }
}

void TemChamado(Viatura *ptr,Pessoa *ptrP){
    if(ptr->chamadoAtual !=NULL){
        ptr->qtdChamado++;
        Caso(ptr,ptrP);
    }
    else{
        printf("Sem chamado ou pedido de reforço, retornando ao menu \n");
    }
}