#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../Login/viaturaLogin.h"

void LoginPM(Policial *ptrP, char *senha,char *nome,chamadoPolicial *pilhaResolvidos){
    bool login= validarUsuario(nome, senha, ptrP);
    if(login){
        for(pilhaResolvidos;pilhaResolvidos->anterior!=NULL;pilhaResolvidos=pilhaResolvidos->anterior){
        }
        for(pilhaResolvidos;pilhaResolvidos->prox!=NULL;pilhaResolvidos=pilhaResolvidos->prox){
            for(int i=0; i<4;i++){
                if(strcmp(pilhaResolvidos->viaturaDoChamada->policiais[i],nome)==0 && (pilhaResolvidos->boletim==0)){
                    printf("Descrição: %s \n",pilhaResolvidos->descricao);
                    printf("Local: %s\n", pilhaResolvidos->local);
                    printf("Quer fazer boletim desse chamado? \n");
                    printf("1- Se sim 2-Se não  ")
                }
            }
        }
    }
    }
}
