#include <iostream>
#include <new>
#include <string>

using namespace std;

class Dicionario(){
    
    struct Noh{
        Noh *ant;
        int chave;
        string valor;
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
    
    void inserir(int chave, string valor){
        Noh *novo = {nullptr, chave, valor, inicio};
        
        if(inicio != nullptr){
            inicio -> ant = novo;
        }
        
        inicio = novo;
        
    }
    
    struct ResConsulta{
        bool achou;
        string valor;
    };
    
    ResConsulta consultar(int chave){
        Noh *busca = inicio;
        ResConsulta res;
        
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
    
    void remover(int chave){
        if(vazio()) return;
        
        Noh *aux = inicio;
        
        while(aux != nullptr){
            if(aux -> chave == chave){
                if(aux -> ant == nullptr){
                    inicio = inicio -> prox;
                }
                else{
                    aux -> ant -> prox = aux -> prox;
                }
                
                delete aux;
                return;
            }
            
            aux = aux -> prox;
        }
    }
    
    void imprimir(){
        if(not vazio()){
            Noh *aux = inicio;
            while(aux != nullptr){
                cout << aux -> elem << " ";

                aux = aux -> prox;
            }

            cout << "\n";
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
