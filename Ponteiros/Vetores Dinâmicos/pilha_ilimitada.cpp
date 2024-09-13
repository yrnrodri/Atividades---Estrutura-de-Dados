/*Escreva uma implementação de pilha ilimitada, no sentido de que ela não deve possuir um limite
 conhecido a priori para o número de elementos passíveis de nela serem armazenados.
 Ao invés de um vetor de tamanho fixo, a "struct" deve possuir um ponteiro que, 
 durante a execução da função de inicialização, deve receber um pequeno vetor alocado dinamicamente.
 Sempre que a função "empilhar" encontrar o vetor cheio, ela deve (1) alocar um vetor maior, 
 (2) copiar para ele os elementos da pilha, (3) desalocar o vetor atual e 
 (4) passar a utilizar o vetor maior como o vetor da pilha.
 */

#include <iostream>
#include <new>

using namespace std;

struct Pilha_Ilimitada{
 
    int lim_atual = 5;
    int n = 0;
    int *p = new int [lim_atual];

};

bool vazia(Pilha_Ilimitada &P){
    return (P .n == 0);
}

bool cheia(Pilha_Ilimitada &P){
    return (P .n == P .lim_atual);
}

bool pertence(Pilha_Ilimitada &P, int x){
    for(int i = 0; i < P .n; i++){
        if(P .p[i] == x) return true;
    }
    return false;
}

void realocar(Pilha_Ilimitada &P){

    int lim_novo = P .lim_atual * 2;
    int *p2 = new int[lim_novo];

    for(int i = 0; i < P .lim_atual; i++){
        p2[i] = P .p[i];
    }

    delete[] P .p;

    P .lim_atual = lim_novo;
    P .p = p2;

}

bool adicionar(Pilha_Ilimitada &P, int x){

    if(cheia(P)){
        realocar(P);
    }
    
    if(!pertence(P, x)){
        P .p[P .n] = x;
        P .n++;

        return true;
    }
    else return false;

}

bool remover(Pilha_Ilimitada &P){

    if(vazia(P)) return false;

    else{
        P .n--;
        return true;
    }

    return false;
}

void mostrar(Pilha_Ilimitada &P){

    for(int i = 0; i < P .n; i++){
        if(i == P .n - 1){
            cout << P .p[i] << endl;
        }
        else{
        cout << P .p[i] << ", ";
        }
     
    }
}

int main(){

    Pilha_Ilimitada P;

    for(;;){

         cout << "Operação(Inserir, Remover, Mostrar, Sair): \n";

        char opcao;

        cin >> opcao;

         if(opcao == 'I'){
            
            cout << "Digite o elemento desejado: \n";

            int x;

            cin >> x;

            if(adicionar(P, x)) cout << "Elemento inserido!\n";
            else if(pertence(P, x)) cout << "Elemento já existente.\n";
            
            
        }

        else if(opcao == 'R'){
            if(vazia(P)) cout << "Conjunto vazio.\n";
            else{

            if(remover(P)) cout << "Elemento removido!\n";

            }
            
        }
        else if(opcao == 'M'){
            if(vazia(P)) cout << "Conjunto Vazio.\n";
            else{
                mostrar(P);
            }
        }

        else if(opcao == 'S') break;
        else {
            cout << "Opção inválida!\n";
        }
  
    }

}