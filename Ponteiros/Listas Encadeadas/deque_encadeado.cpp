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

        imprimir();
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

        imprimir();
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

        imprimir();
        
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

        imprimir();
    }

    int consultar_esq(){
        return esq -> elem;
    }

    int consultar_dir(){
        return dir -> elem;
    }

    void imprimir(){
        if(not vazio()){
            Noh *aux = esq;
            while(aux != nullptr){
                cout << aux -> elem << " ";

                aux = aux -> prox;
            }

            cout << "\n";
        }
    }

    ~Deque(){
        while(!vazio()){
            remover_esq();
        }
    }
};

int main(){
    try
    {
        int escolha, valor;
        Deque deque;
        do
        {
            cout << "Digite 1 para enfilar pela esquerda" << endl;
            cout << "Digite 2 para enfilar pela direita" << endl;
            cout << "Digite 3 para desenfilar pela esquerda" << endl;
            cout << "Digite 4 para desenfilar pela direita" << endl;
            cout << "Digite 5 para sair" << endl;

            cin >> escolha;
            if (escolha == 1)
            {
                cin >> valor;
                deque.inserir_esq(valor);
            }
            else if (escolha == 2)
            {
                cin >> valor;
                deque.inserir_dir(valor);
            }
            else if (escolha == 3)
            {
                deque.remover_esq();
            }
            else if (escolha == 4)
            {
                deque.remover_dir();
            }

        } while (escolha != 5);
    }
    catch (bad_alloc &e)
    {
        cout << "Alocação de memória mal executada" << endl;
        cerr << e.what() << '\n';
    }
    return 0;
}