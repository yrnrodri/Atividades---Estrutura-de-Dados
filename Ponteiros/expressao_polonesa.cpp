/*Escreva um programa que avalie expressões aritméticas digitadas usando operadores pré-fixos,
 ou seja, que aparecem antes dos seus operandos, como em "/ 6000 * 5 / 1410 94",
 que na notação infixa seria escrita como "6000 / (5 * (1410/94))".
 Observe que, nessa notação polonesa, os parênteses são dispensáveis,
 pois nunca há ambiguidade, desde que o número de operandos de cada operador seja respeitado.
 Outro exemplo de entrada possível: "/ * + 3 5 7 - 20 6",
  que na notação infixa é "((3 + 5) * 7) / (20 - 6)".
*/

#include <iostream>
#include <string>

using namespace std;

struct Pilha_Num
{
    static constexpr int tam = 10;
    double v[tam];
    int n = 0;
};

struct Pilha_Op
{
    static constexpr int tam = 10;
    char v[tam];
    int n = 0;
};

bool empilhar_double(Pilha_Num &P, double d)
{
    P.v[P.n] = d;
    P.n++;

    return true;
}

bool empilhar_string(Pilha_Op &P, char s)
{
    P.v[P.n] = s;
    P.n++;

    return true;
}

double desempilhar_double(Pilha_Num &P)
{
    double res = P.v[P.n - 1];
    P.n--;
    return res;
}

bool realizar_op(Pilha_Op &P_op, Pilha_Num &P_num)
{
    double x, y, res;
    char op = P_op.v[P_op.n - 1];

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

int main()
{

    Pilha_Op P_op;
    Pilha_Num P_num;

    string s;

    cout << "Digite sua expressão: \n";

    getline(cin, s);

    char compara;
    double valor_acumulado = 0;

    for (unsigned int i = s.size(); i > 0 ; i--) //lendo o vetor ao contrario, ou seja, da direita pra esquerda
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
                realizar_op(P_op, P_num);
            }
            else if(compara == ' ')
            {
                char anterior = s[i + 1];
                
                if(anterior >= '0' and anterior <= '9'){
                    empilhar_double(P_num, valor_acumulado);
                    valor_acumulado = 0;  
                }  
            }
        }
    }

    cout << "Resultado: " << P_num.v[0] << endl;

    return 0;
}