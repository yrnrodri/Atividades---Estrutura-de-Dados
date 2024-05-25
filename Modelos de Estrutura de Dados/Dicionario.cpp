#include <iostream>
#include <string>

using namespace std;

struct Par{

    int c;
    string v;
};

struct Dicionario{

    static constexpr int tam_v = 5;
    Par v[tam_v];
    int n = 0;
};



bool vazio(Dicionario &D){
    return (D .n == 0);
}

bool cheio(Dicionario &D){
    return (D . n == D .tam_v);
}

string consultar(Dicionario &D, int c){
        for(int i = 0; i < D .n; i ++){
            if(D .v[i] .c == c) return D. v[i] .v;
        }
    
    return "Não existe tal valor.";
}

bool pertence(Dicionario &D, int c){
    for(int i = 0; i < D .n; i ++){
            if(D .v[i] .c == c) return true;
        }

    return false;
}

bool inserir(Dicionario &D, int c, string v){
    
    if(cheio(D)) return false;

    if(!pertence(D, c)){
        D .v[D .n] .c = c;
        D .v[D .n] .v = v;
        D .n++;

        return true;
    }

    return false;
}

bool remover(Dicionario &D, int c){
    if(vazio(D)) return false;

    if(pertence(D, c)){
    for(int i = 0; i < D .n; i++){
        if(D .v[i] .c == c){
            D .v[i] .c = D .v[D. n - 1] .c;
            D .v[i] .v = D .v[D. n - 1] .v;
            D. n--;  
            return true;
        }
        
        
    }
    
    }
    
    return false;
}

int main(){

    Dicionario D;

    for(;;){
        
        cout << "Operação(Inserir, Remover, Consultar, Sair): \n";

        char opcao;

        cin >> opcao;

        if(opcao == 'I'){
            if(cheio(D)) cout << "Dicionario cheio! \n";
            else cout << "Digite a chave e o valor desejado: \n";

            int c;
            string v;

            cin >> c;
            cin >> v;

            if(inserir(D, c, v)) cout << "Par inserido!\n";
            else cout << "Par já existente.\n";

        }

        else if(opcao == 'R'){
            if(vazio(D)) cout << "Dicionario vazio!\n";
            else cout << "Digite a chave: \n";

            int c;

            cin >> c;

            if(remover(D, c)) cout << "Par removido. \n";
            else cout << "Par não existente\n";

        }
        else if(opcao == 'C'){
            if(vazio(D)) cout << "Dicionario vazio!\n";
            else cout << "Digite a chave desejada: \n";

            int c;

            cin >> c;

            cout << consultar(D, c);
            cout << "\n";
        }
        else if(opcao == 'S') break;
        else cout << "Opção inválida!\n";

    }

    return 0;
}