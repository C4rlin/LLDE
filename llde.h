#ifndef LLDE_H
#define LLDE_H
#include <no.h>
#include <QString>
#include <QMessageBox>
#include <vector>

namespace ce{

class LLDE
{
private:
    int quantidadeDeElementos;
    No* inicio;
    No* fim;
public:
    LLDE();
    QString obterLista()const;
    QString obterListaOrdenada(int ordem)const;
    bool estaVazia()const;
    int getQuantidadeDeElementos() const;

    //Início
    void inserirInicio(int elemento);
    int acessarInicio()const;
    int retirarInicio();

    //fim
    void inserirFim(int elemento);
    int acessarFim()const;
    int retirarFim();

    //pos
    int acessarPosicao(int posicao);
    void inserirPosicao(int elemento, int posicao);
    int retirarPosicao(int posicao);

    //ordem
    /*void inserirOrdenado(int elemento);*/

};
}
#endif // LLDE_H
