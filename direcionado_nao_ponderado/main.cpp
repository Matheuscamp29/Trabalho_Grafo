// Bibliotecas
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Implementação do grafo direcionado e não ponderado

// Começo da classe Grafo
class Grafo{

    private:
    int nVertices;
    vector<vector<int>> matriz;

    public:
    void criarMatriz(int n) {
        nVertices = n; 
        matriz = vector<vector<int>>(nVertices, vector<int>(nVertices, 0));
    }
    
    void addVertice(int x) {}
    
    void removeVertice(int x) {}
    
    void addAresta(int v, int u) {}
    
    void removeAresta(int v, int u) {}
    
}; // Fim da classe Grafo

// Começo do main
int main() {

    cout << "Digite o numero de vértices: " << endl;
    int nVertices;
    cin >> nVertices;

    Grafo g;
    g.criarMatriz(nVertices);

    do {

        cout << "Menu: " << endl
        << "0 - Parar" << endl
        << "1 - Adicionar Vértice" << endl
        << "2 - Adicionar Aresta" << endl
        << "3 - Remover Vértice" << endl
        << "4 - Remover Aresta" << endl;

        int x;
        cin >> x;

        switch(x) {
        
            case 0:
                cout << "Fim do programa!" << endl;
            break;
            case 1:

            break;
            case 2:

            break;
            case 3:
        
            break;
            case 4:

            break;
            default:
                cout << "Digite um número válido" << endl;
            break;
        }

    } while (x != 0);

    return 0;
} // Fim do main