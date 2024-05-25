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

    remover_ocorrencias(v, 10, x);

    
}