/*Implementar um procedimento de remoção em lista simplesmente encadeada que não 
necessite testar se o nó removido é o primeiro da lista (sendo portanto apontado pelo ponteiro 
inicial da lista) ou se não é (nesse caso sendo apontado pelo campo "prox" do nó anterior).
Escrever uma variação da nossa implementação de árvore em que não haja duplicação do processo 
de procurar um nó. Mais especificamente, você pode escrever uma função privada que sirva para 
procurar um nó, mas que retorne um ponteiro apontando para o ponteiro da árvore que aponta para 
o nó (que pode ser o ponteiro raiz ou um ponteiro de filho esquerdo ou direito), 
caso o nó exista (e se o nó não existir?). Nesse caso, essa função pode ser utilizada para evitar
 a repetição do procedimento de busca realizado pelas funções "inserir", "pertence" e "remover".*/

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

     Noh** buscar_noh(int elem){
        Noh* n = raiz;
        Noh **pont = & raiz;

        while(n != nullptr){
            if(elem > n -> elem){
                pont = & n -> dir;
                n = n -> dir;
            }
            else if(elem < n -> elem){
                pont = & n -> esq;
                n = n -> esq;
            }
            else return pont;
        }

        return pont;
    }

    void inserir(int elem){
        Noh *novo = new Noh{nullptr, elem, nullptr};

        Noh **cima = buscar_noh(elem);

        *cima = novo;
    }

    bool pertence(int elem){
        Noh **cima = buscar_noh(elem);

        if(*cima != nullptr) return true;
        return false;
    }

    void inserir_se_novo(int elem){

        if(pertence(elem) == false){
            inserir(elem);
        }
        else return;
    }

    void remover(int elem){

        Noh **cima = buscar_noh(elem);
        Noh *n = *cima;

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