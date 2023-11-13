#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../COPOM/registro-chamado.h"
#include "../Login/viaturaLogin.h"
void LoginPM(Policial *ptrP, char *senha,char *nome,chamadoPolicial *pilhaResolvidos){
    bool login= validarUsuario(nome, senha, ptrP);
    if(login){
        for(;pilhaResolvidos->anterior!=NULL;pilhaResolvidos=pilhaResolvidos->anterior){
        }
        for(;pilhaResolvidos->prox!=NULL;pilhaResolvidos=pilhaResolvidos->prox){
            for(int i=0; i<4;i++){
                if(strcmp(pilhaResolvidos->viaturaDoChamada->policiais[i],nome)==0 && (pilhaResolvidos->boletim==0)){
                    printf("Descrição: %s \n",pilhaResolvidos->descricao);
                    printf("Local: %s\n", pilhaResolvidos->local);
                    printf("Quer fazer boletim desse chamado? \n");
                    printf("1- Se sim  2-Se não: \n");
                    int op;
                    scanf(" %d", &op);
                    if(op==1){
                        pilhaResolvidos->boletim=1;
                        char nomearquivo[100];
                        FILE *pt;
                        sprintf(nomearquivo, "ocorrencia %s do policial %s.txt", pilhaResolvidos->descricao, nome);
                        pt=fopen(nomearquivo,"a+");
                        fprintf(pt,"Descrição da ocorrencia: %s \n",pilhaResolvidos->descricao);
                        fprintf(pt,"Local do ocorrido: %s",pilhaResolvidos->local);
                        fprintf(pt,"Viatura que atendeu o chamado: %d",pilhaResolvidos->viaturaDoChamada->Codigo);
                        fclose(pt);
                    }
                };
            }
        }
    }
    }
