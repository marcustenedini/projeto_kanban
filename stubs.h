#ifndef STUBS_H_INCLUDED
#define STUBS_H_INCLUDED

#include "interfaces.h"

#include <stdexcept>
#include <iostream>

using namespace std;


// Declarações de classes stub.

// Classe StubISProjeto implementa a interface ISProjeto.
class StubISProjeto:public ISProjeto{
public:

    // Definições de valores a serem usados como gatilhos para notificações de erros.

    const static int TRIGGER_FALHA        = 67890;
    const static int TRIGGER_ERRO_SISTEMA = 78901;

    // Declarações de métodos relacionados na interface.

     bool criar_quadro(const Quadro&);
     bool vizualizar_quadro(const Quadro&);
     bool eliminar_quadro(const Quadro&);
     bool criar_cartao(const Cartao&);
     bool vizualizar_cartao(const Cartao&);
     bool mover_cartao(const Cartao&);
     bool eliminar_cartao(const Cartao&);
};

//--------------------------------------------------------------------------------------------

// Classe StubISConta implementa a interface ISConta.

class StubISConta:public ISConta {
    private:

    // Definições de valores a serem usados como gatilhos para notificações de erros.

    const static int TRIGGER_FALHA        = 67890;
    const static int TRIGGER_ERRO_SISTEMA = 78901;

    public:

    // Declaração de método previsto em interface.

    virtual bool criar(Conta) = 0;
    virtual bool visualizar(Conta*) = 0;
    virtual bool editar(Conta) = 0;
    virtual bool eliminar(Email) = 0;

};

//--------------------------------------------------------------------------------------------

// stub para servicos de autenticacao - 222005395

class StubSAutenticacao: public ISAutenticacao {

// Definições de valores a serem usados como gatilhos para notificações de erros.

private:
    const static string TRIGGER_SUCESSO;
    const static string TRIGGER_FALHA;

public:

    // Declaração de método previsto em interface.

    bool autenticar(Email, Senha);
};

#endif // STUBS_H_INCLUDED
