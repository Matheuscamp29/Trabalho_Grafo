#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <random>
#include <iomanip>
#include <set> 

#include "GrafoListaAdj.h"
#include "GrafoMatrizAdj.h"
#include "EdmondsAlgorithm.h"

using namespace std;

void gerar_arestas_aleatorias(int V, int E, vector<Edge>& arestas) {
    arestas.clear();
    if (V <= 1) return;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib_v(0, V - 1);
    uniform_int_distribution<> distrib_p(1, 100); 
    
    set<pair<int, int>> arestas_unicas;
    long long max_arestas = (long long)V * (V-1);
    if(E > max_arestas) E = max_arestas;

    while (arestas_unicas.size() < E) {
        int u = distrib_v(gen);
        int v = distrib_v(gen);
        if (u != v) {
            arestas_unicas.insert({u, v});
        }
    }

    for (const auto& aresta : arestas_unicas) {
        arestas.push_back({aresta.first, aresta.second, distrib_p(gen)});
    }
}

int main() {
    ofstream arquivo_saida("resultados_edmonds.csv"); 

    cout << "Iniciando análise de desempenho do Algoritmo de Edmonds..." << endl;
    cout << "Resultados serão salvos em 'resultados_edmonds.csv'" << endl;
    arquivo_saida << "Tipo,V,E,Algoritmo,Representacao,Tempo (us),Peso" << endl;

    vector<int> tamanhos_v = {50, 100, 150}; 

    for (int V : tamanhos_v) {
        // --- Cenário Esparso ---
        int E_esparso = V * 2;
        vector<Edge> arestas_esparsas;
        gerar_arestas_aleatorias(V, E_esparso, arestas_esparsas);

        // Teste com LISTA DE ADJACÊNCIA (Esparso)
        GrafoListaAdj grafo_lista_esparso(V);
        for(const auto& aresta : arestas_esparsas) grafo_lista_esparso.adicionarAresta(aresta.u, aresta.v, aresta.peso);
        
        auto start_lista_e = chrono::high_resolution_clock::now();
        double peso_lista_e = findMinimumArborescence(grafo_lista_esparso, 0);
        auto stop_lista_e = chrono::high_resolution_clock::now();
        auto duration_lista_e = chrono::duration_cast<chrono::microseconds>(stop_lista_e - start_lista_e);
        arquivo_saida << "Esparso," << V << "," << E_esparso << ",Edmonds,Lista," << duration_lista_e.count() << "," << peso_lista_e << endl;

        // Teste com MATRIZ DE ADJACÊNCIA (Esparso)
        GrafoMatrizAdj grafo_matriz_esparso(V);
        for(const auto& aresta : arestas_esparsas) grafo_matriz_esparso.adicionarAresta(aresta.u, aresta.v, aresta.peso);
        
        auto start_matriz_e = chrono::high_resolution_clock::now();
        double peso_matriz_e = findMinimumArborescence(grafo_matriz_esparso, 0);
        auto stop_matriz_e = chrono::high_resolution_clock::now();
        auto duration_matriz_e = chrono::duration_cast<chrono::microseconds>(stop_matriz_e - start_matriz_e);
        arquivo_saida << "Esparso," << V << "," << E_esparso << ",Edmonds,Matriz," << duration_matriz_e.count() << "," << peso_matriz_e << endl;

        // --- Cenário Denso ---
        int E_denso = (V * V) / 4;
        vector<Edge> arestas_densas;
        gerar_arestas_aleatorias(V, E_denso, arestas_densas);

        // Teste com LISTA DE ADJACÊNCIA (Denso)
        GrafoListaAdj grafo_lista_denso(V);
        for(const auto& aresta : arestas_densas) grafo_lista_denso.adicionarAresta(aresta.u, aresta.v, aresta.peso);
        
        auto start_lista_d = chrono::high_resolution_clock::now();
        double peso_lista_d = findMinimumArborescence(grafo_lista_denso, 0);
        auto stop_lista_d = chrono::high_resolution_clock::now();
        auto duration_lista_d = chrono::duration_cast<chrono::microseconds>(stop_lista_d - start_lista_d);
        arquivo_saida << "Denso," << V << "," << E_denso << ",Edmonds,Lista," << duration_lista_d.count() << "," << peso_lista_d << endl;

        // Teste com MATRIZ DE ADJACÊNCIA (Denso)
        GrafoMatrizAdj grafo_matriz_denso(V);
        for(const auto& aresta : arestas_densas) grafo_matriz_denso.adicionarAresta(aresta.u, aresta.v, aresta.peso);
        
        auto start_matriz_d = chrono::high_resolution_clock::now();
        double peso_matriz_d = findMinimumArborescence(grafo_matriz_denso, 0);
        auto stop_matriz_d = chrono::high_resolution_clock::now();
        auto duration_matriz_d = chrono::duration_cast<chrono::microseconds>(stop_matriz_d - start_matriz_d);
        arquivo_saida << "Denso," << V << "," << E_denso << ",Edmonds,Matriz," << duration_matriz_d.count() << "," << peso_matriz_d << endl;
    }

    arquivo_saida.close();
    cout << "Análise concluída com sucesso." << endl;
    return 0;
}