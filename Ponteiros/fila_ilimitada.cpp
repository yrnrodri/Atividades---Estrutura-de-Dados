/*Escreva uma implementação de fila ilimitada utilizando vetor (alocado dinamicamente).
 O vetor inicial deve ter tamanho 1 ou 2. Sempre que o vetor estiver cheio, 
 utilize a estratégia de redimensionamento eficiente estudada na aula: 
 substituí-lo por outro com o dobro do tamanho.

Escreva uma variação da implementação da questão anterior que,
 além de expandir o vetor quando ele estiver cheio, 
 também "contraia" o vetor (isto é, substitua-o por outro menor) 
 quando ele estiver significativamente vazio. 
 Atenção: pense numa estratégia eficiente de contração, que faça com que
  o número de cópias ao longo das operações da fila (tanto inserções quanto remoções) 
  seja proporcional ao número de operações realizadas. 
  A grande questão é: você irá contrair o vetor quando ele estiver quantos % vazio? 
  E o vetor menor terá que tamanho em relação ao original? 
  */
 
#include <iostream>
#include <new>

using namespace std;

struct Fila_Ilimitada{
    int lim_atual = 1;
    int *p = new int [lim_atual];
    int primeiro, ultimo;
    int n = 0;
};
bool vazia(Fila_Ilimitada &F){
    return (F .n == 0);
}

bool cheia(Fila_Ilimitada &F){
    return (F .n == F .lim_atual);
}

void expandir(Fila_Ilimitada &F){

    int lim_novo = F .lim_atual * 2;
    int *p2 = new int [lim_novo];

    for(int i = 0; i < F .lim_atual; i++){
        p2[i] = F .p[i + F .primeiro];
    }

    delete [] F .p;

    F .lim_atual = lim_novo;
    F .p = p2;
}

void reduzir(Fila_Ilimitada &F){
    
    int lim_novo = F .lim_atual / 2;
    int *p2 = new int [lim_novo];

    for(int i = 0; i < lim_novo; i++){
        p2[i] = F .p[i + F .primeiro];
    }

    delete [] F .p;

    F .primeiro = 0;
    F .ultimo = F .n - 1;

    F .lim_atual = lim_novo;
    F .p = p2;
}

bool enfilar(Fila_Ilimitada &F, int x){
    
    if(cheia(F)){
        expandir(F);
    }

    if(vazia(F)){
        F .primeiro = 0;
        F .ultimo = 0;
    }

    F .p[F .ultimo] = x;
    F .ultimo++;
    F .n++;

    return true;
    
}

bool desenfilar(Fila_Ilimitada &F){

    if(vazia(F)) return false;

    F .primeiro++;
    F .n--;

    if(F .n == F .lim_atual * 0.25){
        reduzir(F);
    }

}

int main(){

    Fila_Ilimitada F;

    for(;;){

         cout << "Operação(Inserir, Remover, Sair): \n";

        char opcao;

        cin >> opcao;

         if(opcao == 'I'){
            
            cout << "Digite o elemento desejado: \n";

            int x;

            cin >> x;

            if(enfilar(F, x)) cout << "Elemento inserido!\n";   
            
        }

        else if(opcao == 'R'){
            if(vazia(F)) cout << "Conjunto vazio.\n";
            else{

            if(desenfilar(F)) cout << "Elemento removido!\n";

            }
            
        }

        else if(opcao == 'S') break;
        else {
            cout << "Opção inválida!\n";
        }
  
    }
}



