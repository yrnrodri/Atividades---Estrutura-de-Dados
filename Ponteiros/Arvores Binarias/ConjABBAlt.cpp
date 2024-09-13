// Em construção...

/*Escreva uma variação da implementação de hoje que:
Possua, na estrutura do nó, também um ponteiro para o nó "pai" 
(que naturalmente será nulo no caso da raiz).
Na função "inserir", retorne um ponteiro apontando para o nó inserido 
(o ideal, para fins de encapsulamento/abstração, seria retornar um "iterador" para o nó, 
mas esse tipo não foi definido em aula, então retornar um ponteiro para o nó é mais simples 
de explicar). Observe que, nesse caso, a definição do tipo "Noh" tem que ficar fora do tipo 
"ConjABB".
Na função "remover", ao invés de receber um double, receba um ponteiro para o nó a ser removido. 
Observe que, nesse caso, o nó não precisa ser procurado. Além disso, como todo nó possui um 
ponteiro para o "pai", então a remoção pode ser iniciada imediatamente.*/

#include <iostream>

using namespace std;

struct Noh{
        Noh* pai;
        Noh* esq;
        int elem;
        Noh* dir;
    };

class ConjABB{

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

    Noh* inserir(int elem){
        Noh *novo = new Noh;
        novo -> esq = nullptr;
        novo -> elem = elem;
        novo -> dir = nullptr;

        if(vazio()){
            raiz = novo;
            novo -> pai = nullptr;
            return novo;
        }

        Noh *n = raiz;

        
        while(true){
            if(n -> elem > elem){
                if(n -> esq == nullptr){
                    n -> esq = novo;
                    novo -> pai = n;
                    return novo;
                } 
                n = n -> esq;
            }
            else{
                if(n -> dir == nullptr){
                    n -> dir = novo;
                    novo -> pai = n;
                    return novo;
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

    void remover(Noh *n){

        if(n == nullptr) return;

        if(n -> dir == nullptr){
            if(n == raiz) raiz = n -> esq;
            else if(n == n -> pai -> esq) n -> pai -> esq = n -> esq;
            else n -> pai -> dir = n -> esq;
        }
        else if(n -> esq == nullptr){
            if(n == raiz) raiz = n -> dir;
            else if(n == n -> pai -> esq) n -> pai -> esq = n -> dir;
            else n -> pai -> dir = n -> dir;
        }
        else{
            Noh *aux = n -> esq;

            while(aux -> dir != nullptr){
                aux = aux -> dir;
            }

            if(aux -> pai != n){
                aux -> pai -> dir = aux -> esq;

                if(n == n -> pai -> dir) n -> pai -> dir = aux;
                else n -> pai -> esq = aux;

                n -> esq -> pai = aux;
                n -> dir -> pai = aux;
            }
            else{
                if(n == n -> pai -> esq){
                    n -> pai -> esq = aux;
                    aux -> pai = n -> pai -> esq;
                }
                else{
                    n -> pai -> dir = aux;
                    aux -> pai = n -> pai -> dir;
                }
            }

            if(n == raiz) raiz = aux;
        
            aux -> esq = n -> esq;
            aux -> dir =  n -> dir;
            aux -> pai = n -> pai;
        }

        delete n;
    }
    
};