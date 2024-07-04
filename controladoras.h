#ifndef CONTROLADORAS_H_INCLUDED
#define CONTROLADORAS_H_INCLUDED

#include "interfaces.h"
#include "Dominios e Entidades/dominios.h"
#include "containers.h"

#include <stdexcept>
#include <iostream>
#include <cstdlib>

#define CLR_SCR system("clear");

using namespace std;

// ---------- Controladoras da camada de apresentacao --------------

// Controladora inicializante - Controladora

// Controladora Apresentação Interface Usuario
// Código: 222005386
// Revisao: 222005395

class CntrAInterfaceUsuario {
private:
    IAAutenticacao *cntrAAutenticacao;
    IAConta *cntrIAConta;
    IAProjeto *cntrIAProjeto;

public:
    void interagirComUsuario();

    void setCntrAAutenticacao(IAAutenticacao*);

    void setCntrIAConta(IAConta*);

    void setCntrIAProjeto(IAProjeto*);
};

// Controladora Apresentação Autenticação.
// Código: 222005395
// Revisao:22225960

class CntrAAutenticacao:public IAAutenticacao {
private:
    ISAutenticacao *cntrSAutenticacao;

public:
    bool autenticar(Email*);
    void setCntrSAutenticacao(ISAutenticacao *);
};

void inline CntrAAutenticacao::setCntrSAutenticacao(ISAutenticacao *cntr){
        this->cntrSAutenticacao = cntr;
}

//  Controladora Servico Projeto
// Código:222025960
// Revisão: 222005395

class CntrIAProjeto:public IAProjeto {
private:

    // Códigos dos serviços.

    const static int CRIAR_CARTAO   = 1;
    const static int VIZUALIZAR_CARTAO   = 2;
    const static int MOVER_CARTAO   = 3;
    const static int ELIMINAR_CARTAO   = 4;
    const static int CRIAR_QUADRO = 5;
    const static int VIZUALIZAR_QUADRO    = 6;
    const static int ELIMINAR_QUADRO  = 7;
    const static int RETORNAR  = 8;

    ISProjeto *cntrISProjeto;                  // Referência para servidor.

public:
    void executar();
    void executarCartoes();
    void executarQuadros();
    void setCntrISProjeto(ISProjeto *);
};

inline void CntrIAProjeto::setCntrISProjeto(ISProjeto *cntrISProjeto){
    this->cntrISProjeto = cntrISProjeto;
}

// Controladora Apresentacao Conta.
// Código: 222005395
// Revisão:

class CntrIAConta:public IAConta{
private:
    ISConta *cntrSConta;      // ligacao com o modulo de servico

public:
    void criar();
    void executar(Email);
    void setCntrSConta(ISConta*);
};

inline void CntrIAConta::setCntrSConta(ISConta *cntrSC){
    this -> cntrSConta = cntrSC;
}

// ---------- Controladoras da camada de servico --------------

// Controladora Servico Autenticacao
// Código: 211026548
// Revisão:222025960

class CntrISAutenticacao:public ISAutenticacao{
    public:
        bool autenticar(Email, Senha);
};

// Controladora Servico Conta
// Código: 222005395
// Revisão:

class CntrISC:public ISConta{
public:
    bool criar(Conta);
    bool visualizar(Conta*);
    bool editar(Conta);
    bool eliminar(Email);
};

class CntrISProjeto:public ISProjeto{
public:
     bool criar_quadro(Quadro);
     Quadro vizualizar_quadro(Quadro);
     bool atualizar_quadro(Quadro);
     bool eliminar_quadro(Codigo);
     bool criar_cartao(Cartao);
     Cartao vizualizar_cartao(Cartao);
     Cartao mover_cartao(Cartao);
     bool atualizar_cartao(Cartao);
     bool eliminar_cartao(Codigo);

};

#endif // CONTROLADORAS_H_INCLUDED
