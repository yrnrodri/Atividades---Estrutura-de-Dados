/*Considere uma variação do TAD fila em que, além de remoção no início e inserção no final, 
seja possível também inserir no início; você pode imaginar, por exemplo, 
que a inserção no início seria utilizada esporadicamente, 
para adicionar elementos com prioridade máxima. 
Implemente então essa variação da fila usando lista simplesmente encadeada.
*/

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

    void enfilar_dir(int elem){
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

    void enfilar_esq(int elem){
        Noh *novo = new Noh;
        novo -> elem = elem;
        novo -> prox = inicio;

        if(vazia()){
            fim = novo;
        }
 
        inicio = novo;
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