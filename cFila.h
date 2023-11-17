#ifndef CFILA_H
#define CFILA_H
#include "cstdlib"

struct no{
    int valor;
    struct no *prox;
};

class cFila {
public:
    
    no *inicio=NULL, *fim=NULL, *aux=NULL;
    
    cFila();
    cFila(const cFila& orig);
    virtual ~cFila();
    
    void menu();
    void inserir();
    void pesquisar();
    void imprimir();
    void remover();
    bool vazia(struct no*);
    
private:

};

#endif /* CFILA_H */

