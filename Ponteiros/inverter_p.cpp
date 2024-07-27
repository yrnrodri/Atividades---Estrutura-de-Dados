/*Escreva uma função "void inverter (double *p, int n)" que inverta a ordem dos "n"
 elementos do vetor (cujo primeiro elemento é) apontado por "p", ou seja,
  o último número deve passar a estar na primeira posição, o penúltimo na segunda, etc. 
  Utilize a indexação de ponteiros abordada no final da aula de hoje.
*/


#include <iostream>

using namespace std;

void inverter (int *p, int n){

    for(int i = 0; i <= (n/2); i++){

        int x = *(p + i);
        int y = *(p + (n - 1));

        *(p + i) = y;
        *(p + (n - 1)) = x;

        n--;
    }
}

int main(){
    
    int v[10] = { 10, 2, -7, 4, 2, 2, 9, 2, 3, 2 };
    int *p = & v[0];

    inverter(p, 10);

    
    for(int i = 0; i < 10; i++){
        cout << v[i];
    } 




}