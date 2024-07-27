// Implemente uma pilha usando lista encadeada

#include <iostream>
#include <new>

using namespace std;

class Pilha{

    struct Noh{
        int elem;
        Noh *prox;
    };

    Noh *topo;

    public:

    Pilha(){
        topo = nullptr;
    }

    bool vazia(){
        return topo == nullptr;
    }

    void empilhar(int elem){
        Noh *novo = new Noh;
        novo -> elem = elem;
        novo -> prox = topo;
        topo = novo;
    }

    int consultar_topo(){
        return topo -> elem;
    }

    void desempilhar(){
        Noh *ultimo = topo;
        topo = topo -> prox;

        delete ultimo;
    }

    ~Pilha(){
        while(!vazia){
            desempilhar();
        }
    }
};