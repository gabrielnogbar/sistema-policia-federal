#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../Login/viaturaLogin.h"
#include "viaturaUso.h"
#include "../COPOM/resgistro-chamado.h"

void ViaturaEmUso(Viatura p){
    int op=0;
    printf("Descrição: %s \n",p->chamado);
    printf("Localização: %s \n", ptrC->local);
    printf(" 1- Confirmar ação policial       2- Ação Dispensada");
    scanf(" %d",&op);
    if(op=1){
        FunçõesChamada(ptrP);
    }


    }