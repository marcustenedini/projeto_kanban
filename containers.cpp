#include "containers.h"

// ----------------------------------------------------------------------
// Implementações de métodos de classe container.


ContainerQuadro* ContainerQuadro::instancia = nullptr;//nullptr é melhor

ContainerQuadro* ContainerQuadro::getInstancia() {
    if (instancia == nullptr){
        instancia = new ContainerQuadro();
    }
    return instancia;
}

bool ContainerQuadro::incluir(Quadro quadro){

    // Busca o email associado ao quadro (Fk)
    string fk = quadro.getEmailConta().getEnderecoEmail();

    // Registra o quadro como pertencente
    // ao usuario identificado pela Fk
    quadrosUsuario[fk].push(quadro.getCodigo());

    //cout << "deu bom\n";
    return container.insert(make_pair(quadro.getCodigo().getValor(), quadro)).second;
}

bool ContainerQuadro::remover(Codigo codigo){
    map<string, Quadro>::iterator it = container.find(codigo.getValor());
    if(it != container.end()){
        container.erase(it);
        return true;
    }
    return false;
}

Quadro ContainerQuadro::pesquisar(Quadro* quadro){
    map<string, Quadro>::iterator it = container.find(quadro->getCodigo().getValor());
    if(it != container.end()){
        //cout << "found\n";
        *quadro = it->second;
        return it->second;
    }else{
        throw runtime_error("erro");
    }
}

// Retorna quadros do usuario em forma de pilha
stack<Codigo> ContainerQuadro::pesquisarQuadrosUsuario(string email){
    return quadrosUsuario[email];
}

bool ContainerQuadro::existe(Quadro* quadro){
    map<string, Quadro>::iterator it = container.find(quadro->getCodigo().getValor());
    if(it != container.end()){
        *quadro = it->second;
        return true;
    }else{
        return false;
    }
}

bool ContainerQuadro::atualizar(Quadro quadro){
    map<string, Quadro>::iterator it = container.find(quadro.getCodigo().getValor());
    if(it != container.end()){
        it->second = quadro;
        return true;
    }
    return false;
}

ContainerConta* ContainerConta::instancia = nullptr;

ContainerConta* ContainerConta::getInstancia() {
    if (instancia == 0)
        instancia = new ContainerConta();
    return instancia;
}

bool ContainerConta::incluir(Conta conta){
    return container.insert(make_pair(conta.getEmail().getEnderecoEmail(), conta)).second;
}

bool ContainerConta::remover(Email email){
    map<string, Conta>::iterator it = container.find(email.getEnderecoEmail());
    if(it != container.end()){
        container.erase(it);
        return true;
    }
    return false;
}

Conta ContainerConta::pesquisar(Conta* conta){
    map<string, Conta>::iterator it = container.find(conta->getEmail().getEnderecoEmail());
    if(it != container.end()){
        *conta = it->second;
        return it->second;
    }
    else{
        throw runtime_error("");
    }
}

bool ContainerConta::existe(Conta* conta){
    map<string, Conta>::iterator it = container.find(conta->getEmail().getEnderecoEmail());
    if(it != container.end()){
        *conta = it->second;
        return true;
    }
    return false;
}


bool ContainerConta::atualizar(Conta conta){
    map<string, Conta>::iterator it = container.find(conta.getEmail().getEnderecoEmail());
    if(it != container.end()){
        it->second = conta;
        return true;
    }
    return false;
}

ContainerCartao* ContainerCartao::instancia = nullptr;

ContainerCartao* ContainerCartao::getInstancia() {
    if (instancia == 0)
        instancia = new ContainerCartao();
    return instancia;
}

bool ContainerCartao::incluir(Cartao cartao){
    return container.insert(make_pair(cartao.getCodigo().getValor(), cartao)).second;
}

bool ContainerCartao::remover(Codigo codigo){
    map<string, Cartao>::iterator it = container.find(codigo.getValor());
    if(it != container.end()){
        container.erase(it);
        return true;
    }
    return false;
}

stack<Cartao> ContainerCartao::pesquisarCartoesQuadro(Codigo codigoQuadro){

    // cria pilha
    stack<Cartao> cartoes;

    // passa pelo repositorio procurando cartoes do quadro
    for(auto itCartao : container){

        Cartao cartao = itCartao.second;

        // adiciona na pilha se o codigo do quadro bate
        if(cartao.getCodigoQuadro().getValor() == codigoQuadro.getValor()){
            cartoes.push(itCartao.second);
        }
    }

    //retorna a pilha
    return cartoes;
}

bool ContainerCartao::existe(Cartao* cartao){
    map<string, Cartao>::iterator it = container.find(cartao->getCodigo().getValor());
    if(it != container.end()){
        *cartao = it->second;
        return true;
    }
    return false;
}
Cartao ContainerCartao::pesquisar(Cartao* cartao){
    map<string, Cartao>::iterator it = container.find(cartao->getCodigo().getValor());
    if(it != container.end()){
        *cartao = it->second;
        return it->second;
    }
    else{
        throw runtime_error("Cartao nao existe!");
    }
}

bool ContainerCartao::atualizar(Cartao cartao){
    map<string, Cartao>::iterator it = container.find(cartao.getCodigo().getValor());
    if(it != container.end()){
        it->second = cartao;
        return true;
    }
    return false;
}

