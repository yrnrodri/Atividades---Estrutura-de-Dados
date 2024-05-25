#include <iostream>

struct Fila{

    static constexpr int tam_v = 10;
    int v1[tam_v / 2];
    int v2[tam_v / 2];
    int p, u;
    int n = 0;
    int count = 0;
};

bool cheia(Fila &F){
    return (F .n == F .tam_v);
}

bool vazia(Fila &F){
    return (F .n == 0);
}

bool enfilar(Fila &F, int x){
    
    if(cheia(F)) return false;

    if(vazia(F)){ 
        F .u = 0;
        F .p = 0;
     F .v1[F .u] = x;
     F .u = (F .u + 1) % (F .tam_v / 2);
     F .n++;
    }

    if(F .count < (F .tam_v / 2)){
        F .v1[F .u] = x;
        F .u = (F .u + 1) % (F .tam_v / 2);
        F .count++;
    }
    else{
        F .v2[F .u] = x;
        F .u = (F .u + 1) % (F .tam_v / 2);
        F .count = (F .count + 1) % F .tam_v;
    }
    F .n++;

    return true;
    
}

bool desenfilar(Fila &F){

    if (vazia(F)) return false;

    F .p = (F. p + 1) % (F .tam_v / 2);
    F .n--;

    return true;
}
