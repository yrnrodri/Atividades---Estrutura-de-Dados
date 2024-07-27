// Implemente uma fila usando lista encadeada

#include <iostream>
#include <new>

using namespace std;

class Fila{

    struct Noh{
        int elem;
        Noh *prox;
    };

    Noh *inicio;
    Noh *fim;

    public:

    Fila(){
        inicio = fim = nullptr;
    }

    void enfilar(int elem){
        Noh *novo = new Noh;
        novo -> elem = elem;
        novo -> prox = nullptr;

        if(vazia()){
            inicio = novo;
        }else{
            fim -> prox = novo;
        }
 
        fim = novo;
    }
    
    bool desenfilar(){
        if(vazia()){
            return false;
        }

        Noh *aux = new Noh;
        aux = inicio;
        inicio = inicio -> prox;

        if(inicio == nullptr){
            fim = nullptr;
        }

        delete aux;

        return true;
    }

    bool vazia(){
        return inicio == nullptr;
    }

    ~Fila(){
        while(desenfilar()){
            desenfilar();
        }
    }
};