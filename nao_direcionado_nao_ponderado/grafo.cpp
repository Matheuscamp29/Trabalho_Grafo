//funcoes/metodos do grafo
using namespace std;
#include <iostream>
#include <vector>   
#include <string>
#include "Grafo.hpp"
#include "vertice.hpp"

vector<Grafo> grafos; //guarda todos os grafos criados


void criar_grafo() {
    string nome;
    int id;

    cout << "Digite o nome do grafo: ";
    cin >> nome;

    Grafo* g = new Grafo(nome); //cria um novo grafo
    grafos.push_back(*g);  //add o grafo no vetor de grafos

    cout << "Grafo criado com sucesso!" << endl;
}

void listarGrafos() {
    if (grafos.empty()) {
        cout << "Nao ha grafos criados." << endl;
    }

    cout << "Grafos existentes: " << endl;
    for (int i = 0; i < grafos.size(); i++) {
        cout << i + 1 << ". " << grafos[i].getNome() << endl;  //exibe o nome de cada grafo
    }
}

void excluirGrafo(int indice) {
   
    grafos[indice - 1] = grafos.back(); //substitui o grafo a ser removido pelo ultimo grafo
    grafos.pop_back(); //remove o ultimo grafo pra n ficar repetido
    cout << "Grafo excluido com sucesso!" << endl;
}
//gatilho pra ir para o menu de vertices do grafo escolhido
void menu2(int indice) {
   menuVertice(grafos[indice]);
}

