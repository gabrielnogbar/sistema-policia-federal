#ifndef ViATURA_LOGIN
#define ViATURA_LOGIN
#include "../COPOM/registro-chamado.h"
    #define MAX 100

    struct chamadoPolicial
    {
        int quantViaturas;
        char descricao[301];
        char local[51];
        struct chamadoPolicial *prox;
        struct chamadoPolicial *anterior;
    };

    struct Policial{
        char nome[MAX+1];
        int CPF;
        char nomeGuerra[MAX+1];
        char cidade[MAX+1];
        int idade;
        char cargo[MAX+1];
        char senha[MAX+1];
        Policial *prox;
    };
    struct Pessoa
    {  char nome[50],cidade[20];
       char CPF[11]; 
       int idade;
       int numeropassagens;
       char passagens[3][30];
       int numeroinadimplencias;
       char inadimpencias[3][30];
       Pessoa *prox;
    };
    
    struct Viatura{
        int Codigo;
        char policiais[4][30];
        char Tipo[15];
        int disponivel; // 0 Disponivel 1 indisponivel(com chamado atribuido ou prisão em andamento)
        int tipo; // 0 Regular 1 Especializada
        int Logado;// 0 deslogado 1 logado
        int qtdChamado;
        chamadoPolicial *chamadoAtual;
        Viatura *prox;
    };




    
    void LoginViaturas(int op2, Policial *ptr, Viatura *ptrV, chamadoPolicial *ptrR, chamadoPolicial *ptrE, int &DisponiveisR,int &DisponiveisE,Pessoa *ptrP);
    //void LoginViaturas(int op2, Policial *ptr, Viatura *ptrV,chamadoPolicial *&ptrR, chamadoPolicial *&ptrE,int &DisponiveisR, int &DisponiveisE,Pessoa *ptrP)
    void IdentificaPMs(int quantidadePM, Policial *ptr, Viatura *ptrV);

    void PesquisarCPF(Pessoa *ptrP);

    void funcoesChamada(Pessoa *ptrP);

    void Caso(Viatura *ptrV,Pessoa *ptrP,chamadoPolicial *&ptrC);
    
    char* decodificadorSenha(char* senha);

    bool validarUsuario(char* usuario, char* senha, Policial *ptrPoI);



#endif //
