// Programe um conjunto em forma de arvore binaria

#include <iostream>

using namespace std;

class ConjABB{
    struct Noh{
        Noh* esq;
        int elem;
        Noh* dir;
    };

    Noh* raiz;

    public:

    ConjABB(){
        raiz = nullptr;
    }

    ~ConjABB(){
        destruir(raiz);
    }

    void destruir(Noh *n){
        if(n == nullptr) return;

        destruir(n -> esq);
        destruir(n -> dir);
        delete n;
    }

    bool vazio(){
        return (raiz == nullptr);
    }

    void inserir(int elem){
        Noh *novo = new Noh{nullptr, elem, nullptr};

        if(vazio()){
            raiz = novo;
            return;
        }

        Noh *n = raiz;

        
        while(true){
            if(n -> elem > elem){
                if(n -> esq == nullptr){
                    n -> esq = novo;
                    return;
                } 
                n = n -> esq;
            }
            else{
                if(n -> dir == nullptr){
                    n -> dir = novo;
                    return;
                }
                n = n -> dir;
            }
        }
    }

    bool pertence(int elem){
        Noh *n = raiz;

        while(n != nullptr){
            if(n -> elem == elem) return true;
            else if(n -> elem > elem) n = n -> esq;
            else n = n -> dir;
        }

        return false;
    }

    void inserir_se_novo(int elem){

        if(pertence(elem) == false){
            inserir(elem);
        }
        else return;
    }

    void remover(int elem){

        Noh *n = raiz;
        Noh **cima = &raiz;

        while(n != nullptr){
            if(elem > n -> elem){
                cima = & n -> dir;
                n = n -> dir;
            }
            else if (elem < n -> elem){
                cima = & n -> esq;
                n = n -> esq;
            }
            else break;
        }

        if(n == nullptr) return;

        if(n -> dir == nullptr) *cima = n -> esq;
        else if(n -> esq == nullptr) *cima = n -> dir;
        else{
            Noh *aux = n -> esq;
            Noh **cima_aux = & n -> esq;

            while(aux -> dir != nullptr){
                cima_aux = & aux -> dir;
                aux = aux -> dir;
            }

            *cima_aux = aux -> esq;

            *cima = aux;
            aux -> esq = n -> esq;
            aux -> dir =  n -> dir;
        }

        delete n;
    }
    
};