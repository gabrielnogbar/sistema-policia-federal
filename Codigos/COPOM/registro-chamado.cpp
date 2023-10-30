#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "resgistro-chamado.h"

void copiarChamado( chamadoPolicial *destino, chamadoPolicial *origem)
{
    destino->quantViaturas = origem->quantViaturas;
    strcpy(destino->descricao, origem->descricao);
    strcpy(destino->local, origem->local);
    destino->prox = origem->prox;
}

// Funcao para enfilerar os chamados, elas ja recebem os chamados preenchidos
void enfilerar(chamadoPolicial *nova, chamadoPolicial *&I, chamadoPolicial *&F){

    chamadoPolicial *celula = (chamadoPolicial *)calloc(1, sizeof(chamadoPolicial));
    copiarChamado(celula, nova);
    if (I == NULL){
        I = F = celula;
    }
    else{
        F->prox = celula;
        F = celula;
    }
}

// Funcao para desenfilenar os chamados, retorna um ponteiro de chamado
chamadoPolicial *desenfilerar(chamadoPolicial *&I, chamadoPolicial *&F){
    
    struct chamadoPolicial *aux;

    if (I == NULL){
        return NULL;
    }
    else{
        aux = I;
        I = aux->prox;

        if ( I == NULL){
            F = NULL;
        }

        return aux;
    }
}


void imprimirLista(chamadoPolicial *I, const char *nomeFila)
{
    printf("Chamados na %s:\n", nomeFila);

    while (I != NULL) {
        printf("\nQuantidade de Viaturas: %d\n", I->quantViaturas);
        printf("Descrição: %s\n", I->descricao);
        printf("Local: %s\n\n", I->local);
        I = I->prox;
    }
}



void copomRegistroChamado(chamadoPolicial *&iRegular, chamadoPolicial *&fRegular, chamadoPolicial *&iRegularPrioritaria, chamadoPolicial *&fRegularPrioritaria, chamadoPolicial *&iEspecializada , chamadoPolicial *&fEspecializada){

    int tipo;
    struct chamadoPolicial *novo = (struct chamadoPolicial *)calloc(1, sizeof(chamadoPolicial));
    printf("          SPM - COPOM\n\n");

    printf("Policia Normal - 1   Especializada - 2: \n");
    do{
    scanf("%d", &tipo);
    }while (tipo != 1 && tipo != 2);
    
    
    printf("Viaturas Necessárias: \n");
    scanf("%d", &novo->quantViaturas);
    getchar();

    printf("Descrição: ");
    scanf(" %[^\n]", novo->descricao);
   
    printf("Local: ");
    scanf(" %[^\n]", novo->local);

    if (tipo == 1){
        int opcao;
        printf("\nO chamado se enquadra como:\n Prioritário - 1   Não Prioritário - 2: ");
        do{
        scanf("%d", &opcao); // reuso da variavel tipo

        if (opcao == 1){
            enfilerar(novo, iRegularPrioritaria, fRegularPrioritaria);
            printf("Chamado registrado!\n");
        }

        else if (opcao == 2){
            enfilerar(novo, iRegular, fRegular);
            printf("Chamado registrado!\n");
        }

        }while(opcao != 1 && opcao != 2);
        
    }
    else if(tipo == 2){
        enfilerar(novo, iEspecializada, fEspecializada);
        printf("Chamado registrado\n!");
    }
    
    printf("\nfila regular:\n");
    imprimirLista(iRegular, "fila regular");

    printf("\nfila regular prioritaria:\n");
    imprimirLista(iRegularPrioritaria, "fila regular prioritaria");

    printf("\nfila especializada:\n");
    imprimirLista(iEspecializada, "fila especializada");
    printf("apagar essas impressoes após os testes ^\n");


    free(novo);
}   


