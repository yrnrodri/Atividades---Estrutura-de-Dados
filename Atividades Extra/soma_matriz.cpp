#include <iostream>
#include <new>

using namespace std;

class Matriz
{
    private:
    int numero_linhas;
    int numero_colunas;
    double** matriz;

    public:

    Matriz(int m, int n){
        this -> numero_linhas = m;
        this -> numero_colunas = n;
        this -> matriz = new double*[numero_linhas];

        for(int i = 0; i < numero_linhas; i++){
             matriz[i] = new double[numero_colunas];
        }
    }

    void set_valor_pos(int i, int j, double valor){
        matriz[i][j] = valor;
    }

    double get_valor_pos(int i, int j){
        return matriz[i][j];
    }

    void ler_matriz(){
        for(int i = 0; i < numero_linhas; i++){
            for(int j = 0; j < numero_colunas; j++){
                cout << "Elemento [" << i << "][" << j << "]: ";
                cin >> matriz[i][j];
            }
        }
    }

    void imprimir_matriz(){
        for(int i = 0; i < numero_linhas; i++){
            for(int j = 0; j < numero_colunas; j++){
                cout << matriz[i][j] << " ";
            }
            cout << endl;
        }
    }

    Matriz somar_matrizes(Matriz& matriz2){
        if(numero_linhas == matriz2.numero_linhas && numero_colunas == matriz2.numero_colunas){
            Matriz resultado(numero_linhas, numero_colunas);
            for(int i = 0; i < numero_linhas; i++){
                for(int j = 0; j < numero_colunas; j++){
                    resultado.set_valor_pos(i, j, matriz[i][j] + matriz2.get_valor_pos(i, j));    
                }
            }
            
            return resultado;
        }
        else{
            throw invalid_argument("As matrizes devem ter a mesma dimensão.");

        }

    }

};

int main(){

    int m, n;

    cout << "Digite o numero de linhas da matriz: ";
    cin >> m;

    cout << "Digite o numero de colunas da matriz: ";
    cin >> n;

    Matriz matriz1(m, n);
    Matriz matriz2(m, n);

    cout << "Digite os elementos da primeira matriz: ";
    matriz1.ler_matriz();

    cout << "Digite os elementos da segunda matriz: ";
    matriz2.ler_matriz();

    Matriz soma = matriz1.somar_matrizes(matriz2);

    cout << "Resultado da soma: " << endl;

    soma.imprimir_matriz();

    return 0;
}