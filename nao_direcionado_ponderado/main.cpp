/*
    Trabalho de Grafos - Grafos Não Direcionados e Ponderados
    Aluno: João Victor Ferreira Pena
    Lista de melhorias:
    - Adicionar verificação de entrada para evitar erros ao inserir ou remover arestas.
    - Conferir se as arestas já existem antes de inseri-las.
*/


#include <iostream>
#include <cstdlib>
#include <vector>

void inicializarMatriz(int** matriz, int n)
{
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
            matriz[i][j] = 0;
    }
}

int** gerarMatriz(int n)
{
    int** matriz = new int*[n];
    for(int i = 0; i < n; i++)
        matriz[i] = new int[n];
    inicializarMatriz(matriz, n);
    return matriz;
}

int** deletarMatriz(int** matriz, int n)
{
    for (int i = 0; i<n; i++)
        delete[] matriz[i];
    delete[] matriz;
    return nullptr;
}

int** gerarMatrizPeso(int n)
{
    return gerarMatriz(n);
}

int** gerarGrafo(int n)
{
    return gerarMatriz(n);
}

void inserirAresta(int** grafo, int** matrizPeso)
{
    int u, v, peso = 0;
    std::cout << "Digite os valores para a aresta" << std::endl;
    std::cout << "Vertice 1:" << std::endl;
    std::cin >> u;
    std::cout << "Vertice 2:" << std::endl;
    std::cin >> v;
    std::cout << "Peso da aresta:" << std::endl;
    std::cin >> peso;
    grafo[u][v] = 1;
    grafo[v][u] = 1;
    matrizPeso[u][v] = peso;
    matrizPeso[v][u] = peso;
}

void removerAresta(int** grafo, int** matrizPeso)
{
    int u, v, peso = 0;
    std::cout << "Digite os valores para a aresta" << std::endl;
    std::cout << "Vertice 1:" << std::endl;
    std::cin >> u;
    std::cout << "Vertice 2:" << std::endl;
    std::cin >> v;
    grafo[u][v] = 0;
    grafo[v][u] = 0;
    matrizPeso[u][v] = 0;
    matrizPeso[v][u] = 0;
}

void lerGrafo(int** grafo, int** matrizPeso, int n)
{
    std::cout << "Numero de vertices: " << n << std::endl;
    std::cout << "Modelo: (vertice de partida, vertice de chegada, peso da aresta)";
    for(int i = 0; i<n; i++)
    {
        for(int j = i; j<n; j++)
        {   
            if(grafo[i][j]==1)
            {
                std::cout << "(" << i << ", " << j << ", ";
                std::cout << matrizPeso[i][j] << ")";
            }
        }
        std::cout << std::endl;
    }
}

void menu(int n, int** grafo, int** matrizPeso)
{
    int opcao;
    do
    {
        std::cout << "Menu de opcoes:" << std::endl;
        std::cout << "1 - Inserir aresta" << std::endl;
        std::cout << "2 - Remover aresta" << std::endl;
        std::cout << "3 - Ler grafo" << std::endl;
        std::cout << "0 - Sair" << std::endl;
        std::cout << "Digite a opcao desejada: ";
        std::cin >> opcao;
        switch (opcao)
        {
        case 1:
            inserirAresta(grafo, matrizPeso);
            break;
        case 2:
            removerAresta(grafo, matrizPeso);
            break;
        case 3:
            lerGrafo(grafo, matrizPeso, n);
            break;
        case 0:
            std::cout << "Saindo..." << std::endl;
            break;
        default:
            std::cout << "Opcao invalida!" << std::endl;
            break;
        }
    } while (opcao != 0);
}

int main (){
    int n, u, v, peso = 0;
    std::cout << "Digite o numero de vertices: ";
    std::cin >> n;
    n = n+1;

    int** grafo = gerarGrafo(n);
    int** matrizPeso = gerarMatrizPeso(n);
    menu(n, grafo, matrizPeso);
    grafo = deletarMatriz(grafo, n);
    matrizPeso = deletarMatriz(matrizPeso, n);
}
