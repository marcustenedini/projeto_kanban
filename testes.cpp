#include "testes.h"
/*
const std::string TUCartao::STRING_VALIDO = "Tarefa 1";
const std::string TUCartao::STRING_INVALIDO = "";
*/

void teste_cartao::setUp() {
    cntrISProjeto = new CntrISProjeto();
    container = ContainerQuadro::getInstancia();
}

void teste_cartao::testarCenarioSucesso(){

    Codigo codigo;
    Codigo codigo_quadro;
    Texto nome;
    Texto desc;
    Coluna coluna;
    /*
    // Executa o comando.
    ComandoIAProjetoCriar_Cartao comando;
    comando.executar(cntrISProjeto);*/

    codigo.setValor("AB54");
    codigo_quadro.setValor("TP1");
    nome.setTexto("Tarefa 1");
    desc.setTexto("Esta é a primeira tarefa.");
    coluna.setColuna("EM EXECUÇÃO");

    cartao->setCodigo(codigo);
    cartao->setCodigoQuadro(codigo_quadro);
    cartao->setNomeCartao(nome);
    cartao->setDescricaoCartao(desc);
    cartao->setColuna(coluna);

    // Verifica se o cartão foi criado com sucesso.
    if (!cntrISProjeto->criar_cartao(&cartao)) {   //foi possível criar cartao
        estado = FALHA;
        std::cout << "Erro: o cartão não foi criado corretamente." << std::endl;
    }

    if (!container->existe(&cartao)){           //se não existir cartão
        estado = FALHA;
    }
}

void teste_cartao::tearDown(){
    // Destruir controladora de serviço.
    delete cartao;
    delete cntrISProjeto;
}

int teste_cartao::run() {
    setUp();
    testarCenarioSucesso();
    tearDown();
    return estado;
}