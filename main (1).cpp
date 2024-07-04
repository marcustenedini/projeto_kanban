#include <stdexcept>
#include <iostream>
#include <string>

#include "Dominios e Entidades/dominios.h"   //não é necessário esse include
#include "Dominios e Entidades/entidades.h"  //não é necessário esse include
#include "interfaces.h"                      //não é necessário esse include

#include "controladoras.h"
#include "builders.h"

using namespace std;

// Módulo de apresentação de interface com o usuário (MAI)
// Código: 222005386
// Revisão: 211026548

int main()
{
    // Instanciar Builder.

    BuilderSistema *builder;
    builder = new BuilderSistema();

    // Construir (build) sistema.

    CntrAInterfaceUsuario * cntrAInterfaceUsuario;
    cntrAInterfaceUsuario = builder->construir();

    // Solicitar servi�o de apresentacao.

    cntrAInterfaceUsuario->interagirComUsuario();

    // Destruir builder.

    delete builder;

    return 0;

}
