#include <iostream>
#include <string>
#include <sstream>

using namespace std;

struct Pilha_Num_Ilimitada
{
    int lim_atual = 8;
    double *p = new double [lim_atual];
    int n = 0;
};

struct Pilha_Op_Ilimitada
{
    int lim_atual = 8;
    char *p = new char [lim_atual];
    int n = 0;
};

bool empilhar_double(Pilha_Num_Ilimitada &P, double d)
{
    if(P .n == P .lim_atual){
        realocar_pilha_num(P);
    }

    P.p[P.n] = d;
    P.n++;

    return true;
}

bool empilhar_string(Pilha_Op_Ilimitada &P, char s)
{
    if(P .n == P .lim_atual){
        realocar_pilha_string(P);
    }

    P.p[P.n] = s;
    P.n++;

    return true;
}

double desempilhar_double(Pilha_Num_Ilimitada &P)
{
    double res = P.p[P.n - 1];
    P.n--;
    return res;
}

bool realizar_op(Pilha_Op_Ilimitada &P_op, Pilha_Num_Ilimitada &P_num)
{
    double x, y, res;
    char op = P_op.p[P_op.n - 1];

    y = desempilhar_double(P_num);
    x = desempilhar_double(P_num);

    if (op == '-')
        res = x - y;
    else if (op == '+')
        res = x + y;
    else if (op == '*')
        res = x * y;
    else if (op == '/')
        res = x / y;

    P_op.n--;

    empilhar_double(P_num, res);

    return true;
}

void realocar_pilha_num(Pilha_Num_Ilimitada &P){

    int lim_novo = P .lim_atual * 2;
    double *p2 = new double [lim_novo];

    for(int i = 0; i < P .lim_atual; i++){
        p2[i] = P .p[i];
    }

    delete[] P .p;

    P .lim_atual = lim_novo;
    P .p = p2;

}

void realocar_pilha_string(Pilha_Op_Ilimitada &P){

    int lim_novo = P .lim_atual * 2;
    char *p2 = new char [lim_novo];

    for(int i = 0; i < P .lim_atual; i++){
        p2[i] = P .p[i];
    }

    delete[] P .p;

    P .lim_atual = lim_novo;
    P .p = p2;

}

int main()
{

    Pilha_Op_Ilimitada P_op;
    Pilha_Num_Ilimitada P_num;

    string s;

    cout << "Digite sua expressão: \n";

    getline(cin, s);

    char compara;
    double valor_acumulado = 0;

    for (unsigned int i = 0; i < s.size(); i++)
    {
        compara = s[i];

        if ('0' <= compara and compara <= '9')
        {
            valor_acumulado = valor_acumulado * 10 + (compara - '0');
        }
        else
        {
            if (compara == '+' or compara == '-' or compara == '/' or compara == '*')
            {
                empilhar_string(P_op, compara);
            }
            else if (compara == ')')
            {
                realizar_op(P_op, P_num);
            }
            else if(compara == ' ')
            {
                char anterior = s[i - 1];
                
                if(anterior >= '0' and anterior <= '9'){
                    empilhar_double(P_num, valor_acumulado);
                    valor_acumulado = 0;  
                }  
            }
        }
    }

    cout << "Resultado: " << P_num.p[0] << endl;

    return 0;
}