/*Escreva uma função "int remover_ocorrencias (double v, int n, double x)" que,
 recebendo um (ponteiro apontando para um) vetor "v" de "n" double's e um double "x",
 remova as eventuais ocorrências de "x" nas "n" posições do vetor.
 A função também deve informar a quantidade de números restantes no vetor. Exemplo:
   · Se "n" for 10,
   · "v" possuir os números { 10, 2, -7, 4, 2, 2, 9, 2, 3, 2 }
   · e "x" for 2,
então o estado final do vetor deve ser { 10, -7, 4, 9, 3, ?, ?, ?, ?, ? } 
e a função deve retornar 5.
*/

#include <iostream>

using namespace std;

int remover_ocorrencias(double v[], int n, double x){

    double *p = & v[0];
    double v2[n];
    int j = 0;
    int c = 0;

    for(int i = 0; i < n; i++){
        if(p[i] != x) {
        v2[j] = p[i];
        j++;
        }
        else{
        c++;
        }
         
    }

    n -= c;

    v = v2;

    for(int i = 0; i < n; i++){
        cout << v[i];
        cout << " ";
    }

    return n;
}

int main(){

    double v[10] = { 10, 2, -7, 4, 2, 2, 9, 2, 3, 2 };
    int x;

    cout << "Digite a ocorrencia que deseja remover: \n";

    cin >> x;

    int tamanho = remover_ocorrencias(v, 10, x);
    cout << endl;
    cout << "Tamanho novo: " << tamanho << endl;

    
}