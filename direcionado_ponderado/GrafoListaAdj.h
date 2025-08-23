#include <iostream>
#include <vector>
#include <list>
#include <utility>
#include <algorithm> 

using namespace std;

class GrafoListaAdj {
    private:
        int vertice;
        vector<list<pair<int, int>>> adjList;
    
    public:
        GrafoListaAdj(int V) {
            this->vertice = V;
            adjList.resize(this->vertice);
        }

        int getNumVertices() const {
            return vertice;
        }

        void adicionarVertice() {
            vertice++;
            adjList.resize(vertice);
            cout << "Vertice " << vertice - 1 << " adicionado." << endl;
        }

        void adicionarAresta(int u, int v, int p) {
            if(u >= 0 && u < vertice && vertice >= 0 && v < vertice) {
                adjList[u].push_back(make_pair(v, p));
            } else {
                cerr << "Erro: Vértice inválido." << endl;
            }
        }

        void removerAresta(int u, int v) {
            if (u >= 0 && u < vertice) {
                auto& vizinhos = adjList[u];
                vizinhos.remove_if([v](const pair<int, int>& aresta) {
                    return aresta.first == v;
                });
                cout << "Arestas de " << u << " para " << v << " removidas." << endl;
            } else {
                cerr << "Erro: Vértice de origem inválido." << endl;
            }
        }

        void removerVertice(int v) {
            if (v >= 0 && v < vertice) {
                adjList[vertice].clear();

                for (int i = 0; i < vertice; ++i) {
                    removerAresta(i, v);
                }
                cout << "Vértice " << v << " e suas conexões foram removidos." << endl;
            } else {
                cerr << "Erro: Vértice inválido." << endl;
            }
        }

        void imprimirGrafo() {
            std::cout << "\nRepresentação do Grafo (Lista de Adjacência):" << std::endl;
            for (int i = 0; i < vertice; ++i) {
                std::cout << "Vértice " << i << ":";
                for (const auto& par : adjList[i]) {
                    std::cout << " -> (" << par.first << ", peso: " << par.second << ")";
                }
                std::cout << std::endl;
            }
        }

};