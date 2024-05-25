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