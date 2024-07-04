#ifndef CONTAINERS_H_INCLUDED
#define CONTAINERS_H_INCLUDED

#include "Dominios e Entidades/dominios.h"
#include "Dominios e Entidades/entidades.h"

#include <iostream>
#include <stack>
#include <map>

using namespace std;

// ----------------------------------------------------------------------
// Declaração de classe container.
// Codigo:222025960
// Revisao: 222005395

class ContainerQuadro{
private:
    map<string, Quadro> container;
    static ContainerQuadro *instancia;

    // guardar quadros do usuario onde a FK e o email do usuario
    map<string, stack<Codigo>> quadrosUsuario;

    ContainerQuadro(){};

public:
    static  ContainerQuadro* getInstancia();
    bool incluir(Quadro);
    bool remover(Codigo);
    Quadro pesquisar(Quadro*);

    // metodo para recuperar os quadros do usuario
    stack<Codigo> pesquisarQuadrosUsuario(string);

    bool existe(Quadro*);
    bool atualizar(Quadro);
};

class ContainerConta{
private:
    map<string, Conta> container;
    static ContainerConta *instancia;
    ContainerConta(){};
public:
    static  ContainerConta* getInstancia();
    bool incluir(Conta);
    bool remover(Email);
    Conta pesquisar(Conta*);
    bool existe(Conta*);
    bool atualizar(Conta);
};

class ContainerCartao{
private:
    map<string, Cartao> container;
    static ContainerCartao *instancia;
    ContainerCartao(){};

public:
    static  ContainerCartao* getInstancia();
    bool incluir(Cartao);
    bool remover(Codigo);

    // pesquisa os cartoes associados a um quadro
    stack<Cartao> pesquisarCartoesQuadro(Codigo);
    Cartao pesquisar(Cartao*);
    bool existe(Cartao*);
    bool atualizar(Cartao);
};
#endif // CONTROLADORAS_H_INCLUDED
