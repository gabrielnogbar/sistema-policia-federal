#ifndef REGISTRO_CHAMADO_H_INCLUDED
#define REGISTRO_CHAMADO_H_INCLUDED



#include "../Login/viaturaLogin.h"

    /*
        Struct dos chamados policiais em geral.
        Os chamados serao distintos no momento 
        de alocacao nas determinadas filas.
    */
    


    void copiarChamado( chamadoPolicial* &destino, chamadoPolicial *origem);

    // Funcao para enfilerar os chamados, elas ja recebem os chamados preenchidos
    void enfilerar(chamadoPolicial *nova, chamadoPolicial *&I, chamadoPolicial *&F);

    // Funcao para enfilerar como prioridade
    void enfilerarPrioridade(chamadoPolicial* nova, chamadoPolicial* &I, chamadoPolicial* &F, chamadoPolicial* &PrioridadeF);

    // Funcao para desenfilenar os chamados, retorna um ponteiro de chamado
    chamadoPolicial *desenfilerar(chamadoPolicial *&I);

    void imprimirLista(chamadoPolicial *I, const char *nomeFila);

    //Inicia o processo de registro
    void copomRegistroChamado(chamadoPolicial *&iRegular, chamadoPolicial *&fRegular, chamadoPolicial* &prioritario,chamadoPolicial *&iEspecializada , chamadoPolicial *&fEspecializada);

    void distribuidorChamado(Viatura* &listaViaturas, chamadoPolicial* &chamadosRegular, chamadoPolicial* &chamadosEspecial );

#endif // 