#include "Dominios e Entidades/dominios.h"
#include "Dominios e Entidades/entidades.h"
#include "controladoras.h"
#include "containers.h"
#include "comandos.h"

// ------ metodos de controladoras da camada de apresentacao ---------

// Controladora Apresentação Interface com o Usuário (MAI) - 222005386
// Revisao: 222005395
void CntrAInterfaceUsuario::interagirComUsuario() {
    bool resultado;

    while(true){

        CLR_SCR;

        int opcao;
        bool sair = false;

        std::cout << "Olá! Seja bem-vindo ao sistema Kanban!\n";
        std::cout << "1. Autenticar\n";
        std::cout << "2. Criar nova conta\n";
        std::cout << "0. Sair\n";
        std::cout << "Escolha uma opção: ";

        std::cin >> opcao;


        switch (opcao) {
            case 1:
            {                                           // adiciona chaves para eliminar alerta de erros
                CLR_SCR

                std::string EntradaEmail;               // cria campo para entrada de email

                std::cout << "Digite o email: ";
                std::cin >> EntradaEmail;

                Email email;

                // valida o email fornecido
                try{
                    email.setEnderecoEmail(EntradaEmail);
                } catch(invalid_argument& exp){
                    std::cout << "Dados incorretos.\n";
                }

                resultado = cntrAAutenticacao->autenticar(&email);

                if (resultado) {
                    std::cout << "Autenticação bem-sucedida para o email: " << email.getEnderecoEmail() << std::endl;
                    std::cout << "Pressione Enter" << std::endl;


                    std::cin.ignore();
                    std::cin.get();

                    // Fluxo de sucesso na autenticação
                    bool apresentar = true;

                    while (apresentar) {
                        CLR_SCR;
                        std::cout << "E agora, qual é o próximo passo?" << std::endl;
                        std::cout << "Para serviços de conta, digite 1" << std::endl;
                        std::cout << "Para serviços de gerenciamento de quadros, digite 2" << std::endl;
                        std::cout << "Para voltar à tela inicial, digite 3" << std::endl;
                        std::cin >> opcao;

                        switch (opcao) {
                            case 1:
                                try{
                                    cntrIAConta->executar(email);
                                }catch(int& msm){
                                    apresentar = false;
                                }
                                break;
                            case 2:
                                cntrIAProjeto->executar();
                                break;
                            case 3:
                                apresentar = false;
                                break;
                            default:
                                std::cout << "Opção inválida. Pressione Enter para Tentar novamente.\n";
                                std::cin.ignore();
                                std::cin.get();
                                break;
                        }
                    }
                } else{
                    std::cout << "Falha no serviço. Pressione Enter para continuar" << std::endl;
                    std::cin.ignore();
                    std::cin.get();

                }
                break;
            }
            case 2:
            {
                cntrIAConta->criar();
                break;
            }
            case 0:
            {
                std::cout << "Pressione Enter para sair...";
                std::cin.ignore(); // Limpa o buffer de entrada
                std::cin.get(); // Aguarda o usuário pressionar Enter

                sair = true;

                break;
            }
            default:
            {
                std::cout << "Opção inválida. Tente novamente.\n";
                break;
            }
        }

        if(sair == true){
            break;
        }
    }
}

void CntrAInterfaceUsuario::setCntrAAutenticacao(IAAutenticacao *cntr) {
    cntrAAutenticacao = cntr;
}

void CntrAInterfaceUsuario::setCntrIAConta(IAConta *cntr) {
    cntrIAConta = cntr;
}

void CntrAInterfaceUsuario::setCntrIAProjeto(IAProjeto *cntr) {
    cntrIAProjeto = cntr;
}

// Controladora Apresentacao Autenticacao - 222005395

bool CntrAAutenticacao::autenticar(Email *email) {

    // cria variavel para senha
    Senha senha;

    // Mensagens a serem apresentadas
    char texto1[]="Digite a senha: ";
    char texto2[]="Dados de entrada em formato incorreto.";
    char texto3[]="Digite novos dados.";
    char texto4[]="Falha na autenticacao, digite algo para continuar.\n";


    while(true) {
        // Campos de entrada
        string EntradaSenha;

        // Ler senha
        std::cout << texto1;
        std::cin >> EntradaSenha;

        try {
            senha.setSenha(EntradaSenha);
            break;
        }
        catch (const invalid_argument &exp) {

            CLR_SCR;

            // relata falha
            std::cout << texto2;
            std::cout << texto3;

            std::cin.ignore();
            std::cin.get();
        }
    }

    // Solicitar autenticação.
    if(cntrSAutenticacao->autenticar(*email, senha))
        return true;

    // Falha na autenticacao

    CLR_SCR;

    // Imprimir mensagem de erro de autenticacao.
    std::cout << texto4;
    std::cin.ignore();
    std::cin.get();

    return false;
}


//--------------------------------------------------------------------------------------------

// Controladora Apresentacao conta

void CntrIAConta::criar(){

    // Mensagens a serem apresentadas na tela de cadastramento.

    char texto1[] ="Preencha os seguintes campos: ";
    char texto2[] ="Nome            : ";
    char texto3[] ="Email           : ";
    char texto4[] ="Senha           : ";
    char texto5[]="Dados em formato incorreto. Digite algo.";
    char texto6[]="Sucesso no cadastramento. Digite algo.";
    char texto7[]="Falha no cadastramento. Digite algo.";

    // Instancia os domínios.

    Texto nome;
    Email email;
    Senha senha;

    // Instancia variaveis de entrada

    string EntradaNome;
    string EntradaEmail;
    string EntradaSenha;

    // Apresenta tela de cadastramento.

    // limpa tela
    CLR_SCR;

    std::cout << texto1 << "\n";
    std::cout << texto2;                                                 // Imprime campo nome.
    std::cin >> EntradaNome;                                             // Le nome.
    std::cout << "\n";                                                   // Imprime linha nova
    std::cout << texto3;                                                 // Imprime campo email.
    std::cin >> EntradaEmail;                                            // Le email.
    std::cout << "\n";                                                   // Imprime linha nova
    std::cout << texto4;                                                 // Imprime campo senha.
    std::cin >> EntradaSenha;                                            // Le senha.
    std::cout << "\n";                                                   // Imprime linha nova

    // Apresenta tela de cadastramento.

    try{
        nome.setTexto(EntradaNome);
        email.setEnderecoEmail(EntradaEmail);
        senha.setSenha(EntradaSenha);
    }
    catch(invalid_argument &exp){
        std::cout << texto5;                                           // Informa formato incorreto.
        std::cin.ignore();
        std::cin.get();
        return;
    }

    // Instancia e inicializa entidades.

    Conta conta;

    conta.setNomeUsuario(nome);
    conta.setEmail(email);
    conta.setSenha(senha);

    // Cadastra usuário e conta.

    if(cntrSConta->criar(conta)){
        std::cout << texto6;                                           // Informa sucesso.
        std::cin.ignore();
        std::cin.get();
        return;
    }

    std::cout << texto7;                                           // Informa falha.
    std::cin.ignore();
    std::cin.get();

    return;
}

void CntrIAConta::executar(Email email){

    // Mensagens a serem apresentadas na tela de seleção de serviço..

    char texto1[]="Selecione um dos servicos : ";
    char texto2[]="1 - Visualizar dados pessoais.";
    char texto3[]="2 - Editar dados pessoais.";
    char texto4[]="3 - Eliminar Conta.";
    char texto5[]="4 - Retornar.";

    int campo;                                                                                  // Campo de entrada.

    bool apresentar = true;                                                                     // Controle de laço.

    while(apresentar){

        // Apresenta tela de selação de serviço.

        CLR_SCR;

        std::cout << texto1 << endl;
        std::cout << texto2 << endl;
        std::cout << texto3 << endl;
        std::cout << texto4 << endl;
        std::cout << texto5 << endl;

        // Le opcao
        std::cin >> campo;

        switch(campo){
            case 1:
            {
                CLR_SCR;

                // textos a serem apresentados
                char texto6[]="Dados Pessoais";
                char texto7[]="Nome: ";
                char texto8[]="Email: ";
                char texto11[]="Senha: ";
                char texto9[]="Digite algo para Retornar.";
                char texto10[]="Falha no servico. Digite algo.";

                // cria referencia para conta a ser preenchida
                Conta conta;
                conta.setEmail(email);

                if(cntrSConta->visualizar(&conta) == true){
                    std::cout << texto6 << "\n";
                    std::cout << texto7 << conta.getNomeUsuario().getTexto() << "\n";      // apresenta nome
                    std::cout << texto8 << conta.getEmail().getEnderecoEmail() << "\n";            // apresenta email
                    std::cout << texto11 << conta.getSenha().getSenha() << "\n";            // apresenta senha
                    std::cout << texto9 << "\n";                                           // apresenta opcao de retornar

                    std::cin.ignore();
                    std::cin.get();

                }else{

                    std::cout << texto10 << "\n";       // notifica falha
                    std::cin.ignore();
                    std::cin.get();
                }

                break;
            }
            case 2:
            {
                while(true){

                    CLR_SCR;

                    // textos a serem apresentados
                    char texto11[]="Digite novos dados: ";
                    char texto12[]="Nome: ";
                    char texto13[]="Senha: ";
                    char texto14[]="Alteracoes feitas com sucesso!";
                    char texto15[]="Falha no servico. Digite para continuar.";
                    char texto16[]="Dados fornecidos incorretos. Tente novamente.";

                    // cria referencia para conta com as alteracoes desejadas
                    Conta conta;
                    conta.setEmail(email);          // adiciona a PK

                    // campos a serem preenchidos
                    string EntradaNome;
                    string EntradaSenha;

                    // referencia para as classes dominio
                    Texto nome;
                    Senha senha;

                    std::cout << texto11 << "\n";
                    std::cout << texto12;
                    std::cin >> EntradaNome;
                    std::cout << "\n";
                    std::cout << texto13;
                    std::cin >> EntradaSenha;
                    std::cout << "\n";

                    // valinda nome
                    try{
                        nome.setTexto(EntradaNome);
                        senha.setSenha(EntradaSenha);

                    } catch(exception& invalid_argument){
                        std::cout << texto16 << "\n";
                        std::cin.ignore();
                        std::cin.get();

                        continue;       // recarrega a tela
                    }

                    // Dados validados com sucesso, proceder para edicao de conta.

                    // adiciona dados validados
                    conta.setNomeUsuario(nome);
                    conta.setSenha(senha);

                    CLR_SCR;

                    // solicita edicao de conta
                    if(cntrSConta->editar(conta) == true){

                        std::cout << texto14 << "\n";


                        break;              // retorna para tela de selecao de servicos
                    } else{

                        std::cout << texto15 << "\n";           // notifica erro e prepara a recarga da tela
                        std::cin.ignore();
                        std::cin.get();
                    }

                }

                break;
            }
            case 3:
            {
                CLR_SCR;

                // textos a serem apresentados
                char texto17[]="Digite \"S\" para confirmar ou \"N\" para cancelar a operacao";
                char texto18[]="Conta removida com sucesso!";

                char opcao;

                std::cout << texto17 << "\n";
                std::cin >> opcao;

                if(opcao == 'S'){
                    if(cntrSConta->eliminar(email) == true){

                        CLR_SCR;

                        std::cout << texto18 << "\n";
                        std::cin.ignore();
                        std::cin.get();

                        apresentar = false;
                        throw -1;
                    }
                } // Se N, retorna para a tela de apresentacao de servicos de conta

                break;
            }
            case 4:
            {
                apresentar = false;
                break; // retorna para a tela de apresentacao de servicos de conta
            }
        }
    }
}

// ---------- metodos controladoras camada de servico ----------------------

// Controladora Servico Autenticacao - 211026548

//implementando o metodo autenticar
bool CntrISAutenticacao::autenticar(Email email, Senha senha) {
    ContainerConta *container;
    container = ContainerConta::getInstancia();
    Conta conta_provisoria;
    Conta conta_real;
    conta_provisoria.setEmail(email);
    conta_provisoria.setSenha(senha);
    if (container->existe(&conta_provisoria)) {
        conta_real = container->pesquisar(&conta_provisoria);
        if(conta_real.getSenha().getSenha()==senha.getSenha()){
            return true;
        }
    }
    return false;
}

// ----------- Controladora Servico Conta ----------

// implementacao do metodo criar
bool CntrISC::criar(Conta conta){
    ContainerConta *CoConta;
    CoConta = ContainerConta::getInstancia();

    return CoConta->incluir(conta);
}

// implementacao do metodo eliminar
bool CntrISC::eliminar(Email email){

    // instancia containers

    ContainerConta *coConta;
    coConta = ContainerConta::getInstancia();

    ContainerCartao *coCartao;
    coCartao = ContainerCartao::getInstancia();

    ContainerQuadro *coQuadro;
    coQuadro = ContainerQuadro::getInstancia();

    // eliminar cartoes e quadros associados a conta

    // busca quadros associados a conta
    stack<Codigo> codigosQuadros = coQuadro->pesquisarQuadrosUsuario(email.getEnderecoEmail());

    while(!codigosQuadros.empty()){

        // tira codigo da pilha
        Codigo codigoQuadro = codigosQuadros.top();
        codigosQuadros.pop();

        // elimina todos os cartoes do quadro
        stack<Cartao> cartoes = coCartao->pesquisarCartoesQuadro(codigoQuadro);

        while(!cartoes.empty()){
            Cartao cartao = cartoes.top();
            cartoes.pop();

            coCartao->remover(cartao.getCodigo());
        }

        // elimina quadro
        coQuadro->remover(codigoQuadro);
    }

    // elimina conta
    return coConta->remover(email);
}

// implementacao do metodo visualizar
bool CntrISC::visualizar(Conta* conta){
    ContainerConta *coConta;
    coConta = ContainerConta::getInstancia();

    return coConta->existe(conta);
}

// implementacao do metodo editar
bool CntrISC::editar(Conta conta){
    ContainerConta *coConta;
    coConta = ContainerConta::getInstancia();

    return coConta->atualizar(conta);
}


//  Controladora Servico Projeto
//  Codigo:222025960
//  Revisao: 222005395
void CntrIAProjeto::executar(){

    bool apresentar = true;

    while(apresentar){

        CLR_SCR;

        int opcao;

        cout << "O que deseja? \n";
        cout << "1 - Gerenciar Quadros\n";
        cout << "2 - Gerenciar Cartões\n";
        cout << "3 - Retornar\n";

        cin >> opcao;

        switch(opcao){
            case 1:
                this->executarQuadros();
                break;
            case 2:
                this->executarCartoes();
                break;
            case 3:
                apresentar = false;
                return;
        }
    }
}

void CntrIAProjeto::executarCartoes(){

    ComandoIAProjeto *comando;

    int opcao;

    bool apresentar = true;

    while(apresentar){

        CLR_SCR;

        cout << endl << "Gerenciamento de Cartao." << endl << endl;
        cout << "Criar   - 1 " << endl;
        cout << "Vizualizar   - 2 " << endl;
        cout << "Mover - 3 " << endl;
        cout << "Eliminar    - 4 " << endl;
        cout << "Retornar  - 8 " << endl;
        cout << "Selecione uma opcao :";

        cin >> opcao;

        switch(opcao){
            case CRIAR_CARTAO:   comando = new ComandoIAProjetoCriar_Cartao();
                            comando->executar(cntrISProjeto);
                            delete comando;
                            break;
            case VIZUALIZAR_CARTAO:   comando = new ComandoIAProjetoVizualizar_Cartao();
                            comando->executar(cntrISProjeto);
                            delete comando;
                            break;
            case MOVER_CARTAO: comando = new ComandoIAProjetoMover_Cartao();
                            comando->executar(cntrISProjeto);
                            delete comando;
                            break;
            case ELIMINAR_CARTAO:    comando = new ComandoIAProjetoEliminar_Cartao();
                            comando->executar(cntrISProjeto);
                            delete comando;
                            break;
            case RETORNAR:
                apresentar = false;
                break;
        }
    }
    return;
}

void CntrIAProjeto::executarQuadros(){

    ComandoIAProjeto *comando;

    int opcao;

    bool apresentar = true;

    while(apresentar){

        CLR_SCR;

        // Apresentar opções.

        cout << endl << "Gerenciamento de Quadro." << endl << endl;
        cout << "Criar   - 5 " << endl;
        cout << "Vizualizar   - 6 " << endl;
        cout << "Eliminar    - 7 " << endl;
        cout << "Retornar  - 8 " << endl;
        cout << "Selecione uma opcao :";

        cin >> opcao;

        switch(opcao){
            case CRIAR_QUADRO:
                            comando = new ComandoIAProjetoCriar_Quadro();
                            comando->executar(cntrISProjeto);
                            delete comando;
                            break;
            case VIZUALIZAR_QUADRO:   comando = new ComandoIAProjetoVizualizar_Quadro();
                            comando->executar(cntrISProjeto);
                            delete comando;
                            break;
            case ELIMINAR_QUADRO:    comando = new ComandoIAProjetoEliminar_Quadro();
                            comando->executar(cntrISProjeto);
                            delete comando;
                            break;
            case RETORNAR:
                apresentar = false;
                break;
        }
    }

    return;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
bool CntrISProjeto::criar_cartao(Cartao cartao){

    // Instancia container de cartoes.

    ContainerCartao *container;

    container = ContainerCartao::getInstancia();
    if(container->existe(&cartao)){
        return false;
    }else{
        return container->incluir(cartao);
    }
}

Cartao CntrISProjeto::vizualizar_cartao(Cartao cartao){

    ContainerCartao *container;

    container = ContainerCartao::getInstancia();

    if (container->existe(&cartao)) {
        return cartao;
    }
    else{
        throw runtime_error("Cartao nao existe");
    }
}

Cartao CntrISProjeto::mover_cartao(Cartao cartao){

    // Instancia container de cartoes.

    ContainerCartao *container;

    container = ContainerCartao::getInstancia();

    if (container->existe(&cartao)) {
        return container->pesquisar(&cartao);
    }
    else{
        throw runtime_error("Cartao nao existe");
    }
}


bool CntrISProjeto::atualizar_cartao(Cartao cartao){

    // Instancia container de cartoes.

    ContainerCartao *container;

    container = ContainerCartao::getInstancia();

    return container->atualizar(cartao);


}


bool CntrISProjeto::eliminar_cartao(Codigo codigo){

    // Instancia container de cartoes.

    ContainerCartao *container;

    container = ContainerCartao::getInstancia();

    return container->remover(codigo);

    }


bool CntrISProjeto::criar_quadro(Quadro quadro){

    ContainerQuadro *container;

    container = ContainerQuadro::getInstancia();

    return container->incluir(quadro);
}


Quadro CntrISProjeto::vizualizar_quadro(Quadro quadro){


    ContainerQuadro *container;

    container = ContainerQuadro::getInstancia();

    try {
        return container->pesquisar(&quadro);
    }catch(exception& exp){
        throw runtime_error("Cartao inexistente");
    }
}

bool CntrISProjeto::atualizar_quadro(Quadro quadro){

    ContainerQuadro *container;

    container = ContainerQuadro::getInstancia();
    if (container->existe(&quadro)) {
        return container->atualizar(quadro);
    }else{
        throw runtime_error("");

    }
}

bool CntrISProjeto::eliminar_quadro(Codigo codigoQuadro){

    ContainerCartao *coCartao;
    coCartao = ContainerCartao::getInstancia();

    ContainerQuadro *coQuadro;
    coQuadro = ContainerQuadro::getInstancia();

    stack<Cartao> cartoes = coCartao->pesquisarCartoesQuadro(codigoQuadro);

    while(!cartoes.empty()){
        Cartao cartao = cartoes.top();
        cartoes.pop();

        coCartao->remover(cartao.getCodigo());
    }

    return coQuadro->remover(codigoQuadro);
}
