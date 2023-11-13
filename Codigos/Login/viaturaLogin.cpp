#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "viaturaLogin.h"
#include "../COPOM/registro-chamado.h"

void LoginViaturas(int op2, Policial *ptr, Viatura* &ptrV,chamadoPolicial *&ptrR, chamadoPolicial *&ptrE,int &DisponiveisR, int &DisponiveisE,Pessoa *ptrP, chamadoPolicial* &pilhaChamadosResolvidos)
// ptrR ponteiro de chamado Regular
// ptrE Ponteiro de chamado especializada
{ // Aqui terei que passar o ponteiro inicial da lista de policiais, de viaturas.

    
    int codigoViatura;
    //Viatura *prtVI= ptrV; //Criando um ponteiro reserva pra percorrer em caso de chamado
    
    printf("Código da Viatura: \n");
    scanf(" %d", &codigoViatura);
    while(ptrV != NULL && codigoViatura != ptrV->Codigo){
        ptrV=ptrV->prox;
    }
    if(ptrV !=NULL){
        ptrV->Logado=1;
    if(ptrV->Logado==1){
        ViaturaAtendimento(op2,ptr, ptrV,ptrR,ptrE,DisponiveisR, DisponiveisE,ptrP,pilhaChamadosResolvidos);
        }
    }
    else{
        printf("Codigo errado");
    }
}
void ViaturaAtendimento(int op2, Policial *ptr, Viatura *&ptrV,chamadoPolicial *&ptrR, chamadoPolicial *&ptrE,int &DisponiveisR, int &DisponiveisE,Pessoa *ptrP,chamadoPolicial* &pilhaChamadosResolvidos){
    printf("Quantidade de Pms: ");
    int quantidadePM;
    int op=0;
    scanf(" %d", &quantidadePM);
    if ((op2==1 && quantidadePM>=2 && quantidadePM<=4)|| (op2==2 && quantidadePM==4 )){
        IdentificaPMs(quantidadePM, ptr, ptrV);// Aqui passar o ponteiro inicial dos policiais e o ponteiro da viatura usada.

            printf("1- Apto para atender ocorrência\n");
            printf("2- Cancelar Embarcação\n");
            ptrV->disponivel=0;
            scanf(" %d", &op);
            if(op==1){
                
                if ((ptrR!=NULL) && (op2==1)){
                    chamadoPolicial *chamadoParaViatura = desenfilerar(ptrR);
                    chamadoParaViatura->viaturaDoChamada=ptrV;
                    ptrV->qtdChamado++;
                    ptrV->chamadoAtual=chamadoParaViatura;
                    Caso(ptrV,ptrP,pilhaChamadosResolvidos);
                    DisponiveisR++;
                    ptrV->disponivel=0;
                }
                else if((op2==1 && ptrR==NULL)){
                    printf(" Sem chamados no momento, VIatura colocada para ronda, Voltando para o menu principal\n");
                    op=2;
                    ptrV->disponivel=0;
                    DisponiveisR ++;
                }
                else if(( op2==2 && ptrE==NULL)){
                    printf(" Sem chamados no momento, VIatura colocada para ronda, Voltando para o menu principal\n");
                    DisponiveisE ++;
                    op=2;
                    ptrV->disponivel=0;
                }
                else if(op2==2 && ptrE!=NULL){
                    chamadoPolicial *chamadoParaViatura = desenfilerar(ptrE);
                    chamadoParaViatura->viaturaDoChamada=ptrV;
                    ptrV->qtdChamado++;
                    ptrV->chamadoAtual=chamadoParaViatura;
                    Caso(ptrV,ptrP,pilhaChamadosResolvidos);
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
    


void IdentificaPMs(int quantidadePM, Policial *ptr, Viatura *&ptrV){  
    printf("\nIdentificação dos PM");
    printf(" \n Nome de Guerra dos policiais:");
    for(int i=1; i<=quantidadePM;i++){
        char nome[30];
        scanf(" %s",nome);
        strcpy(ptrV->policiais[i], nome);
    }
    printf("\n");

}
void Caso(Viatura* &ptrV,Pessoa *ptrP,chamadoPolicial* &pilhaChamadosResolvidos){
    printf("\nInformações do chamado: \n");
    printf("Descrição: %s \n",ptrV->chamadoAtual->descricao);
    printf("Localização: %s \n", ptrV->chamadoAtual->local);
    printf(" 1- Confirmar ação policial       2- Ação Dispensada\n");
    int op;
    scanf(" %d",&op);
    if(op==1){
        funcoesChamada(ptrP);
}
    ptrV->chamadoAtual->resolvido=1;
    empilharChamadoResolvido(ptrV->chamadoAtual,pilhaChamadosResolvidos);
    ptrV->chamadoAtual=NULL;
    ptrV->disponivel = 0;
    ptrV->Logado = 1;
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
    else if(op==2){
        printf("log: Ainda não disponivel!\n");
    }
    else if(op==3){
        printf("log: Ainda não disponivel!\n");
    }
    else if(op==4){
        printf("\nChamado encerrado!\n");
    }


    

}while(op!=4);
}

void PesquisarCPF(Pessoa *ptrP){
    char cpf[15];
    printf("CPF: ");
    scanf(" %s", cpf);
    for(Pessoa *p=ptrP; p!=NULL; p=p->prox){
        if(strcmp(p->CPF, cpf)==0){
            printf("\n Nome: %s",p->nome);
            printf("\n Cidade: %s",p->cidade);
            printf("\n Idade: %d",p->idade);
            printf("\n Numero de passagens:  %d",p->numeropassagens);
            printf("\n Numero de Inandimplencias: %d \n",p->numeroinadimplencias);
            break;
        }
    }  
}
void TemChamado(Viatura *ptr,Pessoa *ptrP,chamadoPolicial* &pilhaChamadosResolvidos){
    if(ptr->chamadoAtual !=NULL){
        ptr->qtdChamado++;
        Caso(ptr,ptrP,pilhaChamadosResolvidos);
        ptr->disponivel=0;
    }
    else{
        printf("Sem chamado ou pedido de reforço, retornando ao menu \n");
    }
}

void VerificaUso(int Codigo, Viatura *&ptr,Pessoa *ptrP,chamadoPolicial* &pilhaChamadosResolvidos){
    /*    for(ptr; ptr != NULL ; ptr = ptr->prox){
        if(ptr->Codigo==Codigo && ptr->Logado==1){
            TemChamado(ptr,ptrP,pilhaChamadosResolvidos);
            break;
        }
    }
    */

    while (ptr != NULL){
        if(ptr->Codigo==Codigo && ptr->Logado==1){
            TemChamado(ptr,ptrP,pilhaChamadosResolvidos);
            break;
        }
        ptr = ptr->prox;
   }

    if(ptr==NULL){
        printf("Codigo errado ou viatura não logada\n");
    }
}

char* codificadorSenha(char* senha){

    char auxiliar[30];
    int iFinal =0;
    char* senhaDescrip = (char *)calloc(30, sizeof(char));

    for (int i=0; senha[i] != '\0'; i++){

        if (65 <= senha[i] && senha[i] <= 90){

            if (senha[i] + 3 > 90){
                auxiliar[i] = (senha[i] + 3)- 26;
            }
            else{
                auxiliar[i] = senha[i] + 3;
            }

        }
        else if (97 <= senha[i] && senha[i] <= 122){

            if (senha[i] + 3 > 122){
                auxiliar[i] = senha[i] + 3 - 26;
            }
            else{
                auxiliar[i] = senha[i] + 3;
            }

        }

        else if (48 <= senha[i] && senha[i] <= 57){
            auxiliar[i]= senha[i];
        }

       
        
        
    }    
while (auxiliar[iFinal] != '\0'){
            iFinal++;
            }

            for (int i = 0; i <iFinal; i++) { 
        senhaDescrip[iFinal-1 - i] = auxiliar[i];
}
    //strcpy(senha, senhaDescrip);
    return senhaDescrip;
}

/*
int main(){
    char senha[30];
    scanf(" %s", senha);

    char* senhaDecodificada = codificadorSenha(senha);
    printf("%s\n",senhaDecodificada);

    free(senhaDecodificada);
    return 0;
}
*/

/*
    Função de verificação usuário/senha;
    Entrada: Ponteiro para a fila de infomações dos policias / nome / 
    Saida: true se as credenciais estarem corretas e falso caso contrario;
*/

bool validarUsuario(char* usuario, char* senha, Policial *ptrPoI){
    printf("%s\n",senha);
    char* senhacodificada = codificadorSenha(senha);
    printf("%s\n",senhacodificada);

    while(ptrPoI != NULL){

        if (strcmp(ptrPoI->nomeGuerra, usuario)==0){
            printf("%s\n", ptrPoI->senha);
            printf("%s\n", ptrPoI->nomeGuerra);
            if (strcmp(ptrPoI->senha, senhacodificada)==0){
                return true;
            }
        }
        ptrPoI=ptrPoI->prox;
    }
    return false;
}

void LoginPM(Policial *ptrP, char *senha,char *nome,chamadoPolicial *pilhaResolvidos){
    bool login= validarUsuario(nome, senha, ptrP);
    if(login==true){
        if(pilhaResolvidos->anterior==NULL){
            printf("Pilha Nula");
        }
        while (pilhaResolvidos->anterior != NULL) {
            pilhaResolvidos = pilhaResolvidos->anterior;
        }
        while (pilhaResolvidos != NULL) {
            for (int i = 0; i < 4; i++) {
                if (strcmp(pilhaResolvidos->viaturaDoChamada->policiais[i], nome) == 0 ){
                    printf("Descrição: %s \n",pilhaResolvidos->descricao);
                    printf("Local: %s\n", pilhaResolvidos->local);
                    printf("Quer fazer boletim desse chamado? \n");
                    printf("1- Se sim  2-Se não: \n");
                    int op;
                    scanf(" %d", &op);
                    if(op==1){
                        printf("Digite o Boletim \n");
                        scanf(" %[^\n]",pilhaResolvidos->boletim[i]);
                    }
                };
            }
            pilhaResolvidos = pilhaResolvidos->prox;
        }
    }
    else{
        printf("senha não correta \n");
    }
    }
void Comandante(Policial *ptrP,char *senha, char *nome, chamadoPolicial *pilhaResolvidos){
     char* senhacodificada = codificadorSenha(senha);
     while(ptrP != NULL){

        if (strcmp(ptrP->nomeGuerra, nome)==0){
            printf("%s\n", ptrP->senha);
            printf("%s\n", ptrP->nomeGuerra);
            if (strcmp(ptrP->senha, senhacodificada)==0 && (strcmp(ptrP->cargo,"Comandante Geral")==0)){
                printf("Deseja Fazer O Relatorio do Dia? Digite 1 se sim 2 se não \n");
                int op;
                scanf(" %d",&op);
                if(op==1){
                    if (pilhaResolvidos == NULL) {
                printf("A lista de ocorrências resolvidas está vazia.\n");
                        return; }
                     while (pilhaResolvidos->anterior != NULL) {
                    pilhaResolvidos = pilhaResolvidos->anterior;
                    }
                        char nomearquivo[100];
                        FILE *pt;
                        sprintf(nomearquivo, "ocorrencia %s do policial %s.txt", pilhaResolvidos->descricao, nome);
                        pt=fopen(nomearquivo,"w+");
                        while(pilhaResolvidos!=NULL){
                        fprintf(pt,"Tipo de Policia: %s \n",pilhaResolvidos->viaturaDoChamada->Tipo);
                        fprintf(pt,"Descrição da ocorrencia: %s \n",pilhaResolvidos->descricao);
                        fprintf(pt,"Local do ocorrido: %s \n",pilhaResolvidos->local);
                        fprintf(pt,"Viatura que atendeu o chamado: %d \n",pilhaResolvidos->viaturaDoChamada->Codigo);
                        fprintf(pt,"Policiais: ");
                        for(int i=0;i<4;i++){
                            if(pilhaResolvidos->viaturaDoChamada->policiais[i]!=NULL){
                                fprintf(pt,"%s ",pilhaResolvidos->viaturaDoChamada->policiais[i]);
                        }}
                        fprintf(pt,"\n");
                        fprintf(pt,"Presos: Nenhum \n");
                        pilhaResolvidos=pilhaResolvidos->prox;
                        }
                        fclose(pt);
                        break;
                    }
                
                else{
                        printf("Voltando ao menu");
                        break;
                    }
                }

        }
        ptrP=ptrP->prox;
    }
    if(ptrP==NULL){
        printf("Policial Não achado");
    }
}

               /*  else{
                        printf("Senha ou nome do comandante errado");
                        break;
            }*/

void selectionSortViaturas(Viatura*& inicio) {
    Viatura* i, * j, * prevI = NULL, * prevJ = NULL;
    
    for (i = inicio; i != NULL; i = i->prox) {
        Viatura* min = i;
        Viatura* prevMin = NULL;
        Viatura* tempPrev = NULL;
        
        for (j = i->prox; j != NULL; j = j->prox) {
            if (j->qtdChamado < min->qtdChamado) {
                min = j;
                prevMin = prevJ;
            }
            prevJ = j;
        }

        if (min != i) {
            if (i != inicio) {
                tempPrev->prox = min;
            } else {
                inicio = min;
            }

            if (prevMin != i) {
                prevMin->prox = i;
            } else {
                inicio = i;
            }

            Viatura* temp = min->prox;
            min->prox = i->prox;
            i->prox = temp;
            tempPrev = i;
        }
    }
}