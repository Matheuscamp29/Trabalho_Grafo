#ifndef GRAFOLISTAADJ_H
#define GRAFOLISTAADJ_H

#include <iostream>
#include <vector>
#include <list>
#include <utility>
#include <algorithm>
#include <queue>

using namespace std;

class GrafoListaAdj
{
private:
    int vertice;
    vector<list<pair<int, int>>> adjList;

    void dfsUtil(int v, vector<bool> &visitado)
    {
        visitado[v] = true;
        cout << v << " ";

        for (const auto &par : adjList[v])
        {
            int vizinho = par.first;
            if (!visitado[vizinho])
            {
                dfsUtil(vizinho, visitado);
            }
        }
    }

public:
    GrafoListaAdj(int V)
    {
        this->vertice = V;
        adjList.resize(this->vertice);
    }

    int getNumVertices() const
    {
        return vertice;
    }

    void adicionarVertice()
    {
        vertice++;
        adjList.resize(vertice);
        cout << "Vertice " << vertice - 1 << " adicionado." << endl;
    }

    void adicionarAresta(int u, int v, int p)
    {
        if (u >= 0 && u < vertice && vertice >= 0 && v < vertice)
        {
            adjList[u].push_back(make_pair(v, p));
        }
        else
        {
            cerr << "Erro: Vértice inválido." << endl;
        }
    }

    void removerAresta(int u, int v)
    {
        if (u >= 0 && u < vertice)
        {
            auto &vizinhos = adjList[u];
            vizinhos.remove_if([v](const pair<int, int> &aresta)
                               { return aresta.first == v; });
            cout << "Arestas de " << u << " para " << v << " removidas." << endl;
        }
        else
        {
            cerr << "Erro: Vértice de origem inválido." << endl;
        }
    }

    void removerVertice(int v)
    {
        if (v >= 0 && v < vertice)
        {
            adjList[vertice].clear();

            for (int i = 0; i < vertice; ++i)
            {
                removerAresta(i, v);
            }
            cout << "Vértice " << v << " e suas conexões foram removidos." << endl;
        }
        else
        {
            cerr << "Erro: Vértice inválido." << endl;
        }
    }

    void imprimirGrafo()
    {
        cout << "\nRepresentação do Grafo (Lista de Adjacência):" << endl;
        for (int i = 0; i < vertice; ++i)
        {
            cout << "Vértice " << i << ":";
            for (const auto &par : adjList[i])
            {
                cout << " -> (" << par.first << ", peso: " << par.second << ")";
            }
            cout << endl;
        }
    }

    void bfs(int v)
    {
        if (v < 0 || v >= vertice)
        {
            cerr << "Erro: Vértice inválido para BFS." << endl;
            return;
        }

        vector<bool> visitado(vertice, false);
        queue<int> fila;

        visitado[v] = true;
        fila.push(v);

        cout << "BFS a partir do vértice " << v << ": ";

        while (!fila.empty())
        {
            int atual = fila.front();
            fila.pop();
            cout << atual << " ";

            for (const auto &par : adjList[atual])
            {
                int vizinho = par.first;
                if (!visitado[vizinho])
                {
                    visitado[vizinho] = true;
                    fila.push(vizinho);
                }
            }
        }

        cout << endl;
    }

    void dfs(int v)
    {
        if (v < 0 || v >= vertice)
        {
            cerr << "Erro: Vértice inválido para DFS." << endl;
            return;
        }

        vector<bool> visitado(vertice, false);
        cout << "DFS a partir do vértice " << v << ": ";
        dfsUtil(v, visitado);
        cout << endl;
    }

    const vector<list<pair<int, int>>>& getAdjList() const {
        return adjList;
    }
};

#endif
