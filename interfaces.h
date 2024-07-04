#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

#include "Dominios e Entidades/dominios.h"
#include "Dominios e Entidades/entidades.h"

#include <stdexcept>

using namespace std;


// Declarações adiantadas (forward declaration).

class ISProjeto;
class ISConta;
class ISAutenticacao;

// ------- Declaração de interfaces da camada de apresentação. ---------

// Interface Apresentacao Projeto

class IAProjeto {
public:
    virtual void executar() = 0;
    virtual void executarQuadros() = 0;
    virtual void executarCartoes() = 0;                   // Método por meio do qual é solicitado o serviço.
    virtual void setCntrISProjeto(ISProjeto*) = 0;                 // Método para estabelecer ligação (link) com a controladora de serviço.
    virtual ~IAProjeto(){}                                          // Método destrutor virtual.
};

// Interface Apresentacao Conta

class IAConta {
public:
    virtual void criar() = 0;                       // Método por meio do qual é solicitado o serviço.
    virtual void executar(Email) = 0;               // Método por meio do qual é solicitado o serviço.
    virtual void setCntrSConta(ISConta*) = 0;      // Método para estabelecer ligação (link) com a controladora na camada de serviço.
    virtual ~IAConta(){}                            // Método destrutor virtual.
};

// Interface Apresentacao Autenticacao

class IAAutenticacao {
public:
    virtual bool autenticar(Email*) = 0;
    virtual void setCntrSAutenticacao(ISAutenticacao *) = 0;

    virtual ~IAAutenticacao(){}
};

// ------- Declaração de interfaces da camada de servico. ---------
//COdigo:222025960
// Interface Servico Projeto
class ISProjeto {
public://editar quadro e cartao
    virtual bool criar_quadro(Quadro) = 0;
    virtual Quadro vizualizar_quadro(Quadro) = 0;
    virtual bool atualizar_quadro(Quadro) = 0;
    virtual bool eliminar_quadro(Codigo) = 0;
    virtual bool criar_cartao(Cartao) = 0;
    virtual Cartao vizualizar_cartao(Cartao) = 0;
    virtual Cartao mover_cartao(Cartao) = 0;
    virtual bool atualizar_cartao(Cartao) = 0;
    virtual bool eliminar_cartao(Codigo) = 0; // Método por meio do qual é solicitado o serviço.

    virtual ~ISProjeto(){}
};

// Interface Servico Autenticacao
class ISAutenticacao {
public:
    virtual bool autenticar(Email, Senha) = 0;
    virtual ~ISAutenticacao(){}
};

// Interface Servico Conta - 211026548
class ISConta{
public:

    // Métodos por meio dos quais são solicitados os serviços.
    virtual bool criar(Conta) = 0;
    virtual bool visualizar(Conta*) = 0;
    virtual bool editar(Conta) = 0;
    virtual bool eliminar(Email) = 0;

    virtual ~ISConta(){}
};

#endif
