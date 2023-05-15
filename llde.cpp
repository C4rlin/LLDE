#include "llde.h"

namespace ce{

int LLDE::getQuantidadeDeElementos() const
{
    return quantidadeDeElementos;
}

LLDE::LLDE():
    quantidadeDeElementos(0),
    inicio(0),
    fim(0)
{

}

bool LLDE::estaVazia()const
{
    return (quantidadeDeElementos == 0);
}

QString LLDE::obterLista()const
{
    No* aux = inicio;
    QString saida;
    if (estaVazia())
    {
        return saida;
    }
    saida += "|";
    for (int pos = 0; pos < quantidadeDeElementos; pos++)
    {
        saida += QString::number(aux->getDado());
        if (pos < quantidadeDeElementos - 1)
        {
            saida += "|->|";
        }
        aux = aux->getProximo();
    }
    saida += "|";
    return saida;
}

QString LLDE::obterListaOrdenada(int ordem) const
{
    No* aux;
    QString saida;
    if (estaVazia())
    {
        return saida;
    }
    std::vector<int> dados;

    if (ordem == 0)
    {
        aux = inicio;
        while (aux != nullptr)
        {
            dados.push_back(aux->getDado());
            aux = aux->getProximo();
        }
        std::sort(dados.begin(), dados.end());
    }
    if (ordem == 1)
    {
        aux = fim;
        while (aux != nullptr)
        {
            dados.push_back(aux->getDado());
            aux = aux->getAnterior();
        }
        std::sort(dados.begin(), dados.end(), std::greater<int>());
    }

    saida += "|";
    for (int i = 0; i < dados.size(); i++)
    {
        saida += QString::number(dados[i]);
        if (i < quantidadeDeElementos - 1)
        {
            saida += "|->|";
        }
    }
    saida += "|";
    return saida;
}


void LLDE::inserirInicio(int elemento)
{
    try
    {
        No *aux = new No(elemento);
        if(estaVazia())
        {
            inicio = fim = aux;
            quantidadeDeElementos++;
            return;
        }
        aux->setProximo(inicio);
        inicio->setAnterior(aux);
        inicio = aux;
        quantidadeDeElementos++;

    } catch (std::bad_alloc &erro)
    {
        throw QString("Nó não foi criado!");
    }
}

int LLDE::acessarInicio()const
{
    if(estaVazia()) throw QString("A lista está vazia");
    return inicio->getDado();
}

int LLDE::retirarInicio()
{
    if(estaVazia()) throw QString("A lista está vazia");
    if(quantidadeDeElementos==1)
    {
        int valor = inicio->getDado();
        quantidadeDeElementos--;
        delete inicio;
        fim = inicio = inicio = 0;
        return valor;
    }
    int valor = inicio->getDado();
    inicio = inicio->getProximo();
    delete inicio->getAnterior();
    inicio->setAnterior(0);
    quantidadeDeElementos--;
    return valor;
}

void LLDE::inserirFim(int elemento)
{
    try {
        No* aux = new No(elemento);
        if(estaVazia())
        {
            quantidadeDeElementos++;
            inicio = fim = aux;
            return;
        }
        fim->setProximo(aux);
        aux->setAnterior(fim);
        quantidadeDeElementos++;
        fim = aux;
    } catch (std::bad_alloc &erro)
    {
        throw QString ("Nó não foi criado!");
    }
}

int LLDE::acessarFim() const
{
    if(estaVazia()) throw QString("A lista está vazia");
    return fim->getDado();
}

int LLDE::retirarFim()
{
    if(estaVazia()) throw QString("A lista está vaizia");
    if(quantidadeDeElementos == 1)
    {
       int valor = fim->getDado();
       quantidadeDeElementos--;
       delete fim;
       fim = inicio = 0;
       return valor;
    }

    int valor = fim->getDado();
    fim = fim->getAnterior();
    delete fim->getProximo();
    fim->setProximo(0);
    quantidadeDeElementos--;
    return valor;
}

int LLDE::acessarPosicao(int posicao)
{
    if(estaVazia()) throw QString("A lista está vazia");
    if(posicao < 0 || posicao >= quantidadeDeElementos) throw QString("A posição desejada não existe");
    if(posicao == 0) return inicio->getDado();
    if(posicao == quantidadeDeElementos - 1) return fim->getDado();

    No* aux = inicio;
    for(int pos = 0; pos < posicao; pos++)
    {
        aux = aux->getProximo();
    }
    return aux->getDado();
}

void LLDE::inserirPosicao(int elemento, int posicao)
{
    try {
        if(posicao < 0 || posicao > quantidadeDeElementos) throw QString("A posição desejada não existe");
        if(posicao == 0) return inserirInicio(elemento);
        if(posicao == quantidadeDeElementos) return inserirFim(elemento);

        No* novo = inicio;
        No* aux = new No(elemento);
        for(int pos = 0; pos < posicao; pos++)
        {
            novo = novo->getProximo();
        }
        aux->setAnterior(novo->getAnterior());
        aux->setProximo(novo);
        novo->getAnterior()->setProximo(aux);
        novo->setAnterior(aux);
        quantidadeDeElementos++;

    } catch (std::bad_alloc &erro)
    {
        throw QString("O nó não foi cirado");
    }
}

int LLDE::retirarPosicao(int posicao)
{
    if(estaVazia()) throw QString("A lista está vazia");
    if(posicao < 0 || posicao >= quantidadeDeElementos) throw QString("A posição desejada não existe");
    if(posicao == 0) return retirarInicio();
    if(posicao == quantidadeDeElementos - 1) return retirarFim();

    No* aux = inicio;
    for(int pos = 0; pos < posicao; pos++)
    {
        aux = aux->getProximo();
    }
    int valor = aux->getDado();
    aux->getAnterior()->setProximo(aux->getProximo());
    aux->getProximo()->setAnterior(aux->getAnterior());
    delete aux;
    quantidadeDeElementos--;

    return valor;
}

/*void LLDE::inserirOrdenado(int elemento)
{
    No* aux = new No(elemento);

    if (estaVazia())
    {
        inicio = fim = aux;
        quantidadeDeElementos++;
        return;
    }
    if (elemento < inicio->getDado())
    {
        inserirInicio(elemento);
        return;
    }
    if (elemento > fim->getDado())
    {
        inserirFim(elemento);
        return;
    }
    No* atual = inicio;
    No* anterior = nullptr;

    while (atual != nullptr && atual->getDado() < elemento)
    {
        anterior = atual;
        atual = atual->getProximo();
    }

    aux->setProximo(anterior->getProximo());
    anterior->setProximo(aux);
    aux->setAnterior(anterior);
    aux->getProximo()->setAnterior(aux);
    quantidadeDeElementos++;
}*/

}
