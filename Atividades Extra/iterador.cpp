#include <iostream>
#include <new>

using namespace std;

struct Iterador
{
    int *p;
};

struct Conjunto
{
    int lim = 10;
    int *elementos = new int[lim];
    int n = 0;
};

Iterador inicio(Conjunto &C)
{
    Iterador it;
    it.p = C.elementos;
    return it;
}

Iterador fim(Conjunto &C)
{
    Iterador it;
    it.p = C.elementos + C.n;
    return it;
}

bool sao_diferentes(Iterador &I, Iterador &F)
{
    return (I.p != F.p);
}

void avancar(Iterador &it)
{
    ++it.p;
}

int acessar_elemento(Iterador &it)
{
    return *it.p;
}

bool vazia(Conjunto &C)
{
    return (C.n == 0);
}

bool cheia(Conjunto &C)
{
    return (C.n == C.lim);
}

bool pertence(Conjunto &C, int x)
{
    for (int i = 0; i <= (C.n - 1); i++)
    {
        if (C.elementos[i] == x)
            return true;
    }
    return false;
}

bool inserir(Conjunto &C, int x)
{
    if (cheia(C))
        return false;

    if (!pertence(C, x))
    {
        C.elementos[C.n] = x;
        C.n++;

        return true;
    }
    else
        return false;
}

int main()
{

    Conjunto C;
    bool parar = false;

    while (parar == false)
    {
        int x;

        cout << "digite: " << endl;
        cin >> x;

        if (x == 0)
            break;

        inserir(C, x);
    }

    Iterador f = fim(C);

    for (Iterador it = inicio(C); sao_diferentes(it, f); avancar(it))
    {
        cout << acessar_elemento(it) << '\n';
    }

    return 0;
}
