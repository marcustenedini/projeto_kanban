#ifndef BUILDERS_H_INCLUDED
#define BUILDERS_H_INCLUDED

#include "interfaces.h"
#include "controladoras.h"
#include "stubs.h"

// Código: 222005386
// Revisão: 222005395

class BuilderSistema {
    private:
        CntrAInterfaceUsuario *cntrAInterfaceUsuario;
        IAAutenticacao *cntrAAutenticacao;
        IAConta *cntrAConta;
        IAProjeto *cntrAProjeto;
        ISAutenticacao *cntrSAutenticacao;
        ISConta *cntrSConta;
        ISProjeto *cntrSProjeto;
    public:
        CntrAInterfaceUsuario* construir();
        ~BuilderSistema();
};

#endif // BUILDERS_H_INCLUDED
