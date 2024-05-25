#include <iostream>

using namespace std;

struct Conjunto{
    static constexpr int tam_v = 3;
    char v[tam_v];
    int n = 0;
};

bool vazia(Conjunto &C){
    return (C .n == 0);
}

bool cheia(Conjunto &C){
    return (C .n == C .tam_v);
}

bool pertence(Conjunto &C, char x){
    for(int i = 0; i <= (C .n - 1); i++){
        if(C .v[i] == x) return true;
    }
    return false;
}

bool inserir(Conjunto &C, char x){
    if(cheia(C)) return false;

    if(!pertence(C, x)){
        C .v[C .n] = x;
        C .n++;
        
        return true;
    }
    else return false;

    
}

bool remover(Conjunto &C, char x){
    if(vazia(C)) return false;

    for(int i = 0; i <= (C .n - 1); i++){
        if(C .v[i] == x){
            C .v[i] = C .v[C. n - 1];
            C. n--;  
        }
        
        return true;
    }
    
    return false;
    
}

int main(){

    Conjunto C;

    for(;;){

        cout << "Operação(Inserir, Remover, Sair): \n";

        char opcao;

        cin >> opcao;

         if(opcao == 'I'){
            if(cheia(C)) cout << "Conjunto cheio! \n";
            else{
            cout << "Digite o elemento desejado: \n";

            char x;

            cin >> x;
            if(inserir(C, x)) cout << "Elemento inserido!\n";
            else if(pertence(C, x)) cout << "Elemento já existente.\n";
            }
            
        }

        else if(opcao == 'R'){
            if(vazia(C)) cout << "Conjunto vazio.\n";
            else{
            cout << "Digite o elemento desejado: \n";

            char x;

            cin >> x;

            if(remover(C, x)) cout << "Elemento removido!\n";
            else if(!pertence(C, x)) cout << "Elemento não existente.\n";
            }
            
        }

        else if(opcao == 'S') break;
        else {
            cout << "Opção inválida!\n";
        }
    }
}