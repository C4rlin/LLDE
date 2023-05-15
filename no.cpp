#include "no.h"

namespace ce{

int No::getDado() const
{
    return dado;
}

void No::setDado(int newDado)
{
    dado = newDado;
}

No *No::getProximo() const
{
    return proximo;
}

void No::setProximo(No *newProximo)
{
    proximo = newProximo;
}
No *No::getAnterior() const
{
    return anterior;
}

void No::setAnterior(No *newAnterior)
{
    anterior = newAnterior;
}

No::No():
    dado(0),
    proximo(0),
    anterior(0)
{
}
No::No(int dado):
    dado(dado),
    proximo(0),
    anterior(0)
{
}

}
