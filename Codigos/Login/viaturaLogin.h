#define MAX 100


struct Policial{
    char nome[MAX+1];
    int CPF;
    char nomeGuerra[MAX+1];
    int Codigo;
    char cargo[MAX+1];
    char senha[MAX+1];
};

struct Viatura{
    int Codigo;
    Policial policiais[4];
    char Tipo[15];
    Viatura *prox;
};

Viatura * RegistrarViatura(int op2);
