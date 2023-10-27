#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "viaturaLogin.h"

Viatura *RegistrarViatura(int op2){ // Aqui terei que passar o ponteiro inicial da lista de policiais, de viaturas.
    int codigoViatura,quantidadePM;
    
    printf("Código da Viatura:");
    scanf(" %d", &codigoViatura);
    printf("Quantidade de Pms:");
    scanf(" %d", &quantidadePM);
    if ((op2==1 && quantidadePM>=2 && quantidadePM<=4)|| (op2==2 && quantidadePM==4 )){
        IdentificaPMs(quantidadePM);// Aqui passar o ponteiro inicial dos policiais e o ponteiro da viatura usada.

    }
    else{
        printf("Quantidade de Policias errada\n");
    }

}
void IdentificaPMs(int quantidadePM){

}
