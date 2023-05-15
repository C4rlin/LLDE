#ifndef NO_H
#define NO_H

namespace ce{
class No
{
private:
    int dado;
    No* proximo;
    No* anterior;
public:
    No();
    No(int dado);
    int getDado() const;
    void setDado(int newDado);
    No *getProximo() const;
    void setProximo(No *newProximo);
    No *getAnterior() const;
    void setAnterior(No *newAnterior);
};
}
#endif // NO_H
