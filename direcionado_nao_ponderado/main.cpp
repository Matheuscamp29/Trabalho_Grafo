/*
Autores: Henrique Saldanha Mendes Veloso e 
*/

// Bibliotecas
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Implementação do grafo direcionado e não ponderado

// Começo da classe Vertice
class Vertice {

    private:
    vector<int> vizinhos;

    public:
    void addAresta(int x) {
        vizinhos.push_back(x);
        sort(vizinhos.begin(), vizinhos.end());
    }

    void removeAresta(int x) {
        auto temp = find(vizinhos.begin(), vizinhos.end(), x);
        
        if(temp != vizinhos.end()) {
            vizinhos.erase(temp);
        }
    }

    void mostrarVizinhos() {
        for(int i = 0; i < vizinhos.size(); i++) {
            cout << " " << vizinhos[i];
        }
    }
};

// Começo da classe Grafo
class Grafo {

    private:
    vector<Vertice> vertices;

    public:
    void criarGrafo(int n) {
        vertices.resize(n);
    }
    
    void addVertice() {
        vertices.push_back(Vertice());
    }
    
    void addAresta(int v, int u) {
        vertices[v].addAresta(u);
    }
    
    void removeAresta(int v, int u) {
        vertices[v].removeAresta(u);
    }

    int quantidadeVertices() {
        return vertices.size();
    }
    
}; // Fim da classe Grafo

// Começo do main
int main() {

    // Início do grafo
    cout << "Digite o numero de vértices: " << endl;
    int nVertices;
    cin >> nVertices;

    Grafo g;
    g.criarGrafo(nVertices);

    // Menu
    int x;
    do {

        cout << "Menu: " << endl
        << "0 - Parar" << endl
        << "1 - Adicionar Vertice" << endl
        << "2 - Adcionar Aresta" << endl
        << "3 - Remover Aresta" << endl
        << "4 - Mostrar Vizinhos" << endl
        << "5 - Mostrar Grafo" << endl; // Função ainda a implementar

        cin >> x;

        switch(x) {
            case 1:

            break;
            case 2:

            break;
            case 3:
        
            break;
            case 4:

            break;
            case 5:

            break;
            case 0:
                cout << "Fim do programa!" << endl;
            break;
            default:
                cout << "Digite um número válido" << endl;
            break;
        }

    } while (x != 0);

    return 0;
} // Fim do main