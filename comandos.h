#ifndef COMANDOS_H_INCLUDED
#define COMANDOS_H_INCLUDED

#include "interfaces.h"
#include "Dominios e Entidades/dominios.h"
#include "Dominios e Entidades/entidades.h"

#include <stdexcept>
#include <iostream>
#include <cstdlib>
#include <cstring>

#define CLR_SCR system("clear");


//----------------------------------------------------------------------------
// Declaracoes de comandos projeto
// Codigo:222025960
// Revisao: 222005395


class ComandoIAProjeto {
public:
    virtual void executar(ISProjeto*) = 0;             // Metodo por meio do qual e solicitada a execucao do comando.
    virtual ~ComandoIAProjeto(){}                       // Metodo destrutor virtual.
};


class ComandoIAProjetoCriar_Cartao:public ComandoIAProjeto {
public:
    void executar(ISProjeto*);
};

class ComandoIAProjetoVizualizar_Cartao:public ComandoIAProjeto {
public:
    void executar(ISProjeto*);
};

class ComandoIAProjetoMover_Cartao:public ComandoIAProjeto {
public:
    void executar(ISProjeto*);
};

class ComandoIAProjetoEliminar_Cartao:public ComandoIAProjeto {
public:
    void executar(ISProjeto*);
};

class ComandoIAProjetoCriar_Quadro:public ComandoIAProjeto {
public:
    void executar(ISProjeto*);
};

class ComandoIAProjetoVizualizar_Quadro:public ComandoIAProjeto {
public:
    void executar(ISProjeto*);
};

class ComandoIAProjetoEliminar_Quadro:public ComandoIAProjeto {
public:
    void executar(ISProjeto*);
};
#endif // COMANDOS_H_INCLUDED

