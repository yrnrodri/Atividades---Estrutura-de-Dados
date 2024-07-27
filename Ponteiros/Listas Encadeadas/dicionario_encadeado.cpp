// Implemente um dicionario via lista encadeada

#include <iostream>
#include <new>

using namespace std;

class Dicionario{
    struct Noh{
        int chave;
        char valor;
        Noh *prox;
    };
     
    Noh *inicio;

    public:

    Dicionario(){
        inicio = nullptr;
    }

    bool vazio(){
        return inicio == nullptr;
    }

    void inserir(int chave, char valor){
        inicio = new Noh {chave, valor, inicio};
    }

    struct ResConsulta{
        bool achou;
        char valor;
    };

    ResConsulta consultar(int chave){
        ResConsulta res;
        Noh *busca = inicio;

        while(busca != nullptr){
            if(busca -> chave == chave){
                res.achou = true;
                res.valor = busca -> valor;
                return res;
            }
            
            busca = busca -> prox;
            
        }

        res.achou = false;
        return res;
    }

    void inserir_se_novo(int chave, char valor){
        ResConsulta res = consultar(chave);

        if(res.achou == false){
            inserir(chave, valor);
        }
    }

    void remover(int chave){
        Noh *aux = inicio;

        if(aux == nullptr) return;

        if(aux -> chave == chave){
            inicio = inicio -> prox;
            delete aux;
            return;
        }

        while(aux -> prox != nullptr){
            if(aux -> prox -> chave == chave){
                Noh *p = aux -> prox;
                aux -> prox = p -> prox;
                delete p;
                return;
            }

            aux = aux -> prox;
        }
    }

    ~Dicionario(){
        Noh *aux = inicio;

        while(inicio != nullptr){
            inicio = inicio -> prox;
            delete aux;
            aux = inicio;
        }
    
    }
};