#include "GrafoMatrizAdj.h"
#include "GrafoListaAdj.h"
#include <iostream>

using namespace std;

void mostrarMenu()
{
    cout << "\n---- Menu ----\n"
         << "1 - Adicionar Vértice\n"
         << "2 - Adicionar Aresta\n"
         << "3 - Remover Aresta\n"
         << "4 - Remover Vértice\n"
         << "5 - Imprimir Grafo\n"
         << "6 - Caminhamento em Profundidade (DFS)\n"
         << "7 - Caminhamento em Largura (BFS)\n"
         << "0 - Sair\n"
         << "Escolha uma opcao: ";
}

int main()
{
    int tipo, V_inicial;

    cout << "Escolha o tipo de representacao do grafo:\n";
    cout << "1 - Lista de Adjacencia\n";
    cout << "2 - Matriz de Adjacencia\n";
    cout << "Opcao: ";
    cin >> tipo;

    cout << "Digite o numero inicial de vertices: ";
    cin >> V_inicial;

    if (tipo == 1)
    {
        GrafoListaAdj grafo(V_inicial);
        int opc, u, v, peso;

        do
        {
            mostrarMenu();
            cin >> opc;

            switch (opc)
            {
            case 1:
                grafo.adicionarVertice();
                break;
            case 2:
                cout << "Digite a origem, o destino e o peso da aresta (u v p): ";
                cin >> u >> v >> peso;
                grafo.adicionarAresta(u, v, peso);
                break;
            case 3:
                cout << "Digite a origem e o destino da aresta a remover (u v): ";
                cin >> u >> v;
                grafo.removerAresta(u, v);
                break;
            case 4:
                cout << "Digite o vértice a ser removido: ";
                cin >> v;
                grafo.removerVertice(v);
                break;
            case 5:
                grafo.imprimirGrafo();
                break;
            case 6:
                cout << "Digite o vértice inicial para DFS: ";
                cin >> v;
                grafo.dfs(v);
                break;
            case 7:
                cout << "Digite o vértice inicial para BFS: ";
                cin >> v;
                grafo.bfs(v);
                break;
            case 0:
                cout << "Encerrando..." << endl;
                break;
            default:
                cout << "Opcao invalida." << endl;
                break;
            }
        } while (opc != 0);
    }
    else if (tipo == 2)
    {
        GrafoMatrizAdj grafo(V_inicial);
        int opc, u, v, peso;

        do
        {
            mostrarMenu();
            cin >> opc;

            switch (opc)
            {
            case 1:
                grafo.adicionarVertice();
                break;
            case 2:
            {
                int num_v = grafo.getNumVertices();
                if (num_v == 0)
                {
                    cout << "Nao ha vertices no grafo. Adicione um vertice primeiro.\n";
                    break;
                }
                cout << "Vertices disponiveis:" << endl;

                for (int i = 0; i < num_v; i++)
                {
                    cout << "Vertice: " << i << endl;
                }

                cout << "Digite a origem, o destino e o peso da aresta (u v p): ";
                cin >> u >> v >> peso;
                grafo.adicionarAresta(u, v, peso);
                break;
            }
            case 3:
                cout << "Digite a origem e o destino da aresta a remover (u v): ";
                cin >> u >> v;
                grafo.removerAresta(u, v);
                break;
            case 4:
                cout << "Digite o vértice a ser removido: ";
                cin >> v;
                grafo.removerVertice(v);
                break;
            case 5:
                grafo.imprimirGrafo();
                break;
            case 6:
                cout << "Digite o vértice inicial para DFS: ";
                cin >> v;
                grafo.dfs(v);
                break;
            case 7:
                cout << "Digite o vértice inicial para BFS: ";
                cin >> v;
                grafo.bfs(v);
                break;
            case 0:
                cout << "Encerrando..." << endl;
                break;
            default:
                cout << "Opcao invalida." << endl;
                break;
            }
        } while (opc != 0);
    }
    else
    {
        cout << "Tipo de grafo invalido." << endl;
    }

    return 0;
}