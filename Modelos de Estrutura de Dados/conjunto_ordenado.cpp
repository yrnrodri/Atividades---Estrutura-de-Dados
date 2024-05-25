#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Conjunto{
    static constexpr int tam_v = 4;
    char v[tam_v];
    int n = 0;
};

bool vazio(Conjunto &C){
    return (C .n == 0);
}

bool cheio(Conjunto &C){
    return (C .n == C .tam_v);
}

bool pertence_recursivo(Conjunto &C, char x, int i, int f){

    int m = (i + (f - i))/ 2;

    if(i > f) return false;

    if(x == C .v[m]) return true;

    if(x < C .v[m]){
        return pertence_recursivo(C, x, i, m - 1);
    }
    else{
        return pertence_recursivo(C, x, m + 1, f);
    }
   
}

int pos_inserir(Conjunto &C, char x){

    if(vazio(C)) return 0;

    int i = 0, f = C .n - 1;
    int m = (i + (f - i))/ 2;

     if(x < C .v[m] and m == 0) return 0;
    
    while(i <= f){

    int m = (i + (f - i))/ 2;

    if(x < C .v[m]) f = m - 1;
    else if(x > C .v[m]) i = m + 1;
    else return m;

   // if(x > C .v[m - 1] and x < C .v[m]) return m;
         
    //if(x > C .v[m] and m == C .n - 1) return m + 1;
    
    }

    return i;
    
}

int pos_remover(Conjunto &C, char x){

    int i = 0, f = C .n - 1;
    

    while(i <= f){

    int m = (i + (f - i))/ 2;

    if(x == C .v[m]) return m;
    else if(x < C .v[m]) f = m - 1;
    else i = m + 1;
    }
    
    return -1;
    
}

bool inserir(Conjunto &C, char x){

    if(cheio(C)) return false;

    if(!pertence_recursivo(C, x, 0, C .n - 1)){
        int pos = pos_inserir(C, x);

        for(int i = C .n; i > pos; i--){
            C .v[i] = C .v[i - 1];
        } 

        C .v[pos] = x;
        C .n++;
        
        return true;
    }
    else return false;
} 

bool remover(Conjunto &C, char x){

    if(vazio(C)) return false;

        int pos = pos_remover(C, x);


    if(pos != -1){
        

        for(int i = pos; i < C .n - 1; i++){
        C .v[i] = C .v[i + 1];
        }

        C .n--;
        return true;
    }
    else return false;
    
}

int main(){

    Conjunto C;

    for(;;){

        cout << "Operação(Inserir, Remover, Sair): \n";

        char opcao;

        cin >> opcao;

         if(opcao == 'I'){
            if(cheio(C)) cout << "Conjunto cheio! \n";
            else{
            cout << "Digite o elemento desejado: \n";

            char x;

            cin >> x;
            if(inserir(C, x)) cout << "Elemento inserido!\n";
            else cout << "Elemento já existente.\n";
            }
            
        }

        else if(opcao == 'R'){
            if(vazio(C)) cout << "Conjunto vazio.\n";
            else{
            cout << "Digite o elemento desejado: \n";

            char x;

            cin >> x;

            if(remover(C, x)) cout << "Elemento removido!\n";
            else cout << "Elemento não existente.\n";
            }
            
        }

        else if(opcao == 'S') break;
        else {
            cout << "Opção inválida!\n";
        }
    }

    return 0;
}

