#ifndef REGISTRO_CHAMADO_H_INCLUDED
#define REGISTRO_CHAMADO_H_INCLUDED

/*
    Struct dos chamados policiais em geral.
    Os chamados serao distintos no momento 
    de alocacao nas determinadas filas.
*/
struct chamadoPolicial
{
    int quantViaturas;
    char descricao[301];
    char local[51];
    struct chamadoPolicial *prox;
};



void copiarChamado( chamadoPolicial *destino, chamadoPolicial *origem);

// Funcao para enfilerar os chamados, elas ja recebem os chamados preenchidos
void enfilerar(chamadoPolicial *nova, chamadoPolicial *&I, chamadoPolicial *&F);

// Funcao para desenfilenar os chamados, retorna um ponteiro de chamado
chamadoPolicial *desenfilerar(chamadoPolicial *&I, chamadoPolicial *&F);

void imprimirLista(chamadoPolicial *I, const char *nomeFila);

//Inicia o processo de registro
void copomRegistroChamado();

#endif // 