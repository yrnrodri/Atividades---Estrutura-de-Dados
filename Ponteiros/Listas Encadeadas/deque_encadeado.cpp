// Implemente um deque via lista duplamente encadeada

#include <iostream>
#include <new>

using namespace std;

class Deque{
    struct Noh{
        Noh *ant;
        int elem;
        Noh *prox;
    };

    Noh *esq, *dir;

    public:

    Deque(){
        esq = dir = nullptr;
    }

    bool vazio(){
        return (esq == nullptr and dir == nullptr);
    }

    void inserir_esq(int elem){
        Noh *novo = new Noh;
        novo -> ant = nullptr;
        novo -> elem = elem;
        novo -> prox = esq;

        if(esq == nullptr){
            dir = novo;
        }
        else{
            esq -> ant = novo;
        }

        esq = novo;
    }

    void inserir_dir(int elem){

        Noh *novo = new Noh {dir, elem, nullptr};

        if(dir == nullptr){
            esq = novo;
        }
        else{
            dir -> prox = novo;
        }

        dir = novo;
    }

    void remover_esq(){
        if(vazio()){
            return;
        }

        Noh *aux = esq;
        esq = esq -> prox;
        
        if(esq == nullptr){
            dir = nullptr;
        }
        else{
            esq -> ant = nullptr;
        }

        delete aux;
        
    }

    void remover_dir(){

        if(vazio()){
            return;
        }

        Noh *aux = dir;
        dir = dir -> ant;

        if(dir == nullptr){
            esq = nullptr;
        }
        else{
            dir -> prox = nullptr;
        }

        delete aux;
    }

    int consultar_esq(){
        return esq -> elem;
    }

    int consultar_dir(){
        return dir -> elem;
    }

    ~Deque(){
        while(!vazio()){
            remover_esq();
        }
    }
};