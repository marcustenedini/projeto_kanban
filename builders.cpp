#include "builders.h"

// Código: 222005386
// Revisão: 222005395


CntrAInterfaceUsuario* BuilderSistema::construir(){

 // Instanciar controladoras da camada de apresenta��o.

    cntrAInterfaceUsuario = new CntrAInterfaceUsuario();
    cntrAAutenticacao = new CntrAAutenticacao();
    cntrAConta = new CntrIAConta();
    cntrAProjeto = new CntrIAProjeto();

    // Instanciar controladoras da camada de servi�o.

    cntrSProjeto = new CntrISProjeto();
    cntrSConta = new CntrISC();
    cntrSAutenticacao = new CntrISAutenticacao();



    // --------------------------------------------------------------------------------------------
    // Substituir instancia de stub por inst�ncia da controladora.
    // --------------------------------------------------------------------------------------------

    //cntrSAutenticacao = new StubSAutenticacao();
    //cntrSProjeto = new StubSProjeto();
    //cntrSConta = new StubSConta();

    // Interligar as controladoras.

    cntrAInterfaceUsuario->setCntrAAutenticacao(cntrAAutenticacao);
    cntrAInterfaceUsuario->setCntrIAConta(cntrAConta);
    cntrAInterfaceUsuario->setCntrIAProjeto(cntrAProjeto);
    cntrAAutenticacao->setCntrSAutenticacao(cntrSAutenticacao); // modificar de acordo com código de autenticacao
    cntrAConta->setCntrSConta(cntrSConta);
    cntrAProjeto->setCntrISProjeto(cntrSProjeto);

    // Retornar refer�ncia para inst�ncia de CntrApresentacaoControle.

    return cntrAInterfaceUsuario;
}

BuilderSistema::~BuilderSistema(){
        delete cntrAInterfaceUsuario;
        delete cntrAAutenticacao;
        delete cntrAConta;
        delete cntrAProjeto;
        delete cntrSAutenticacao;
        delete cntrSConta;
        delete cntrSProjeto;
}
