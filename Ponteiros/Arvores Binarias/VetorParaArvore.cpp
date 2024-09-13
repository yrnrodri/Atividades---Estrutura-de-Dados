/*Escreva uma função que receba um vetor com números em ordem crescente 
e que retorne uma árvore binária de busca contendo esses números. 
Essa árvore deve ser a melhor possível, no sentido de que sua raiz 
deve ser "o elemento do meio" do vetor, e analogamente para cada subárvore, 
atingindo assim a menor altura possível. Você pode escolher os parâmetros a 
serem recebidos pela função, mas ela deve retornar um ponteiro para a raiz da árvore criada.*/

#include <iostream>

using namespace std;

struct Noh{
    Noh *esq;
    int elem;
    Noh *dir;
};

Noh* converter_vetor_para_arvore(int v[], int inicio, int fim){

    if(inicio > fim) return nullptr;

    int meio = (inicio + fim) / 2;

    Noh *arvore = new Noh;

    arvore -> elem = v[meio];

    arvore -> esq = converter_vetor_para_arvore(v, inicio, meio - 1);
    arvore -> dir = converter_vetor_para_arvore(v, meio + 1, fim);

    return arvore;
}

