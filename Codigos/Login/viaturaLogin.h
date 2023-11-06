#ifndef ViATURA_LOGIN
#define ViATURA_LOGIN
    #include "../COPOM/resgistro-chamado.h"
    #define MAX 100
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
       int CPF, idade;
       int numeropassagens;
       char **passagens[3];
       int numeroinadimplencias;
       char **inadimpencias[3];
       Pessoa *prox;
    };
    
    struct Viatura{
        int Codigo;
        char **policiais[4];
        char Tipo[15];
        Viatura *prox;
        int Disponivel; // 0 ocupado 1 desocupado
        int Logado;// 0 deslogado 1 logado
    };
    
    void LoginViaturas(int op2, Policial *ptr, Viatura *ptrV, chamadoPolicial *ptrR, chamadoPolicial *ptrP);

#endif //
