/*Faça um dicionario utilizando tabela hash e nó sentinela*/

#include <iostream>
#include <string>

using namespace std;

class DicionarioTH{

    struct Noh{
        int chave;
        string valor;
        Noh* prox;
    };

    struct ResConsulta{
        bool achou;
        string valor;
    };

    int m; //tamanho da tabela
    int N; //numero de elementos
    Noh** tabela;
    Noh sent;

    int hash(int c){
        return c % m;
    }

    void redimensionar(int novo_tam){
        Noh** nova_tabela = new  Noh* [novo_tam];
        int tam_atual = m;
        m = novo_tam;
        int i;
        for(i = 0; i < novo_tam; i++) nova_tabela[i] = &sent;

        for(i = 0; i < tam_atual; i++){
            Noh* n = tabela[i];

            while(n != &sent){
                int j = hash(n -> chave);
                Noh *p = n -> prox;
                n -> prox = nova_tabela[j];
                nova_tabela[j] = n;
                n = p;
            }

        }
        delete [] tabela;
        tabela = nova_tabela;
    }

    public:

    DicionarioTH(){
        m = 1;
        N = 0;
        tabela = new Noh* [m];

        tabela[0] = &sent;
    }

    ~DicionarioTH(){
        for(int i = 0; i < m; i++){
            Noh *n = tabela[i];

            while(n != &sent){
                tabela[i] = n -> prox;
                delete n;
                n = tabela[i];
            } 
        }
        delete [] tabela;
    }

    ResConsulta consultar(int chave){
        ResConsulta res;
        int i = hash(chave);

        Noh *n = tabela[i];
        while(n != &sent){
            if(n -> chave == chave){
                res.achou = true;
                res.valor = n -> valor;
                return res;
            }
            n = n-> prox;
        }

        res.achou = false;
        return res;
    }

    void inserir(int c, string v){
        ResConsulta consulta = consultar(c);

        if(consulta.achou == false){
            if(m == N) redimensionar(2*m);
            int i = hash(c);
            tabela[i] = new Noh {c, v, tabela[i]};

            N++;
        }
    }

    void remover(int chave){
        ResConsulta consulta = consultar(chave);

        if(consulta.achou == true){
            int i = hash(chave);
            Noh *n = tabela[i];

            if(n -> chave == chave){
                tabela[i] = n -> prox;
                delete n;
                N--;
                if(N == m/4) redimensionar(m/2);
                return;
            }

            while(n -> prox != &sent){
                if(n -> prox -> chave == chave){
                    Noh *aux = n -> prox;
                    n -> prox = aux -> prox;
                    delete aux;
                    N--;
                    if(N == m/4) redimensionar(m/2);
                    return;
                }
                n = n -> prox;
            }
        }

    }

};