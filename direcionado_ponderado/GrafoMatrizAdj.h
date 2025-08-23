#include <iostream>
#include <vector>
#include <iomanip> 

using namespace std;

class GrafoMatrizAdj {
    private:
        int vertice;
        vector<vector<int>> adjMatrix;
    
    public:
        GrafoMatrizAdj(int v) {
            this->vertice = v;
            adjMatrix.resize(vertice, vector<int>(vertice, 0));
        }

        int getNumVertices() const {
            return vertice;
        }

        void adicionarVertice() {
            adjMatrix.push_back(vector<int>(vertice, 0));
            vertice++;
            
            for(int i = 0; i < vertice; i++) {
                adjMatrix[i].resize(vertice, 0);
            }

            cout << "Vertice " << vertice - 1 << " adicionado." << endl;
        }

        void adicionarAresta(int u, int v, int p) {
            if(u >= 0 && u < vertice && v >= 0 && v < vertice) {
                adjMatrix[u][v] = p;
            } else {
                cerr << "Erro: Vértice inválido." << endl;
            }
        }

        void removerAresta(int u, int v) {
            if (u >= 0 && u < vertice && v >= 0 && v < vertice) {
                adjMatrix[u][v] = 0;
                cout << "Aresta de " << u << " para " << v << " removida." << endl;
            } else {
                cerr << "Erro: Vértice inválido." << endl;
            }
        }

        void removerVertice(int v) {
            if (v >= 0 && v < vertice) {
                for (int i = 0; i < vertice; ++i) {
                    adjMatrix[v][i] = 0;
                    adjMatrix[i][v] = 0;
                }
                cout << "Vértice " << v << " e suas conexões foram removidos." << endl;
            } else {
                cerr << "Erro: Vértice inválido." << endl;
            }
        }

        void imprimirGrafo() {
            std::cout << "\nRepresentação do Grafo (Matriz de Adjacência):" << std::endl;
            std::cout << "   ";
            for (int i = 0; i < vertice; ++i) {
                std::cout << std::setw(3) << i;
            }
            std::cout << "\n---";
            for (int i = 0; i < vertice; ++i) {
                std::cout << "---";
            }
            std::cout << std::endl;

            for (int i = 0; i < vertice; ++i) {
                std::cout << std::setw(2) << i << "|";
                for (int j = 0; j < vertice; ++j) {
                    std::cout << std::setw(3) << adjMatrix[i][j];
                }
                std::cout << std::endl;
            }
        }
};   