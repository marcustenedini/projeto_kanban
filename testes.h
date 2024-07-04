#ifndef TESTES_H_INCLUDED
#define TESTES_H_INCLUDED

#include "interfaces.h"
#include "builders.h"

class teste_cartao{
private:

    const static string STRING_VALIDO;
    const static string STRING_INVALIDO;

    Cartao* cartao;
    CntrISProjeto *cntrISProjeto;
    ContainerQuadro *container;


    int estado;
    void setUp();
    void tearDown();
    void testarCenarioSucesso();

public:
    const static int SUCESSO = 0;
    const static int FALHA = -1;
    int run();

};


#endif // TESTES_H_INCLUDED