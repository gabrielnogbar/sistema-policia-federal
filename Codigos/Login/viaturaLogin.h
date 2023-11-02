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
   Texto passagens[3];
   int numeroinadimplencias;
   Texto inadimpencias[3];
   Pessoa *prox;
};

struct Texto
{
    char ocorrencia[30];
};
struct Viatura{
    int Codigo;
    char **policiais[4];
    char Tipo[15];
    Viatura *prox;
    int Disponivel; // 0 ocupado 1 desocupado
};

void LoginViatura(int op2, Policial *ptr, Viatura *ptrV);
