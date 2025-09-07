/*
Autores: Henrique Saldanha Mendes Veloso e Arthur de Sá Camargo
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
    
    vector<int> getVizinhos() {
        return vizinhos;
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
        cout << "Vértice " << vertices.size() - 1 << " adicionado." << endl;
    }
    
    void addAresta(int v, int u) {
        if (v >= vertices.size() || u >= vertices.size()) {
            cout << "Vértice inexistente!" << endl;
            return;
        }
        vertices[v].addAresta(u);
        cout << "Aresta " << v << " -> " << u << " adicionada." << endl;
    }
    
    void removeAresta(int v, int u) {
        if (v >= vertices.size() || u >= vertices.size()) {
            cout << "Vértice inexistente!" << endl;
            return;
        }
        vertices[v].removeAresta(u);
        cout << "Aresta " << v << " -> " << u << " removida." << endl;
    }

    bool buscarAresta(int v, int u) {
        if (v >= vertices.size() || u >= vertices.size()) {
            cout << "Vértice inexistente!" << endl;
            return false;
        }

        vector<int> vizinhos = vertices[v].getVizinhos();
        for (int i = 0; i < vizinhos.size(); ++i) {
            if (vizinhos[i] == u) return true;
        }

        return false;
    }

    int quantidadeVertices() {
        return vertices.size();
    }
    
    void mostrarGrafo() {
        cout << "Listas de Adjacência:" << endl;
        for (int i = 0; i < vertices.size(); i++) {
            cout << i << " ->";
            vertices[i].mostrarVizinhos();
            cout << endl;
        }
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

        cout << "\nMenu: " << endl
        << "0 - Parar" << endl
        << "1 - Adicionar Vertice" << endl
        << "2 - Adicionar Aresta" << endl
        << "3 - Remover Aresta" << endl
        << "4 - Mostrar Grafo" << endl
        << "5 - Buscar Aresta" << endl;

        cin >> x;

        switch(x) {
            case 1:
                g.addVertice();
                break;
            case 2: {
                int v, u;
                cout << "Digite v e u (v -> u): ";
                cin >> v >> u;
                g.addAresta(v, u);
                break;
            }
            case 3: {
                int v, u;
                cout << "Digite v e u (v -> u): ";
                cin >> v >> u;
                g.removeAresta(v, u);
                break;
            }
            case 4:
                g.mostrarGrafo();
                break;
            case 5: {
                int v, u;
                cout << "Digite v e u (v -> u): ";
                cin >> v >> u;
                bool resp = g.buscarAresta(v, u);
                cout << (resp ? "A aresta existe." : "A aresta não existe.") << endl;
                break;
            }    
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