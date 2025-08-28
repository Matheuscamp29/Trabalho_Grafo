#include <iostream>
#include <vector>
#include <iomanip>
#include <queue>

using namespace std;

class GrafoMatrizAdj
{
private:
    int vertice;
    vector<vector<int>> adjMatrix;

    void dfsUtil(int v, vector<bool> &visitado)
    {
        visitado[v] = true;
        cout << v << " ";

        for (int i = 0; i < vertice; ++i)
        {
            if (adjMatrix[v][i] != 0 && !visitado[i])
            {
                dfsUtil(i, visitado);
            }
        }
    }

public:
    GrafoMatrizAdj(int v)
    {
        this->vertice = v;
        adjMatrix.resize(vertice, vector<int>(vertice, 0));
    }

    int getNumVertices() const
    {
        return vertice;
    }

    void adicionarVertice()
    {
        adjMatrix.push_back(vector<int>(vertice, 0));
        vertice++;

        for (int i = 0; i < vertice; i++)
        {
            adjMatrix[i].resize(vertice, 0);
        }

        cout << "Vertice " << vertice - 1 << " adicionado." << endl;
    }

    void adicionarAresta(int u, int v, int p)
    {
        if (u >= 0 && u < vertice && v >= 0 && v < vertice)
        {
            adjMatrix[u][v] = p;
        }
        else
        {
            cerr << "Erro: Vértice inválido." << endl;
        }
    }

    void removerAresta(int u, int v)
    {
        if (u >= 0 && u < vertice && v >= 0 && v < vertice)
        {
            adjMatrix[u][v] = 0;
            cout << "Aresta de " << u << " para " << v << " removida." << endl;
        }
        else
        {
            cerr << "Erro: Vértice inválido." << endl;
        }
    }

    void removerVertice(int v)
    {
        if (v >= 0 && v < vertice)
        {
            for (int i = 0; i < vertice; ++i)
            {
                adjMatrix[v][i] = 0;
                adjMatrix[i][v] = 0;
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
        cout << "\nRepresentação do Grafo (Matriz de Adjacência):" << endl;
        cout << "   ";
        for (int i = 0; i < vertice; ++i)
        {
            cout << setw(3) << i;
        }
        cout << "\n---";
        for (int i = 0; i < vertice; ++i)
        {
            cout << "---";
        }
        cout << endl;

        for (int i = 0; i < vertice; ++i)
        {
            cout << setw(2) << i << "|";
            for (int j = 0; j < vertice; ++j)
            {
                cout << setw(3) << adjMatrix[i][j];
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

        for (int i = 0; i < vertice; ++i)
        {
            if (adjMatrix[atual][i] != 0 && !visitado[i])
            {
                visitado[i] = true;
                fila.push(i);
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
};