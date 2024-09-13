#include <iostream>

using namespace std;

class lista_encadeada{
    struct Noh{
        int elem;
        Noh* prox;
    };

    Noh *inicio;

    public:
    
    lista_encadeada(){
        inicio = nullptr;
    }

    void remover(int elem){
        Noh *n = inicio;
        Noh **ant = & inicio;

        while(n != nullptr){
            if(n -> elem == elem) break;

            ant = & n -> prox;
            n = n -> prox;
        }

        if(n == nullptr) return;

        *ant = n -> prox;
        delete n;
    }
};