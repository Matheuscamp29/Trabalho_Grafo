#ifndef EDMONDS_ALGORITHM_H
#define EDMONDS_ALGORITHM_H

#include <iostream>
#include <vector>
#include <algorithm>
#include "GrafoListaAdj.h"
#include "GrafoMatrizAdj.h"

using namespace std;

// Estrutura para representar uma aresta
struct Edge {
    int u, v, peso;
};

// --- DECLARAÇÕES ANTECIPADAS (FORWARD DECLARATIONS) ---
double edmondsRecursive(const vector<Edge>& edges, int num_vertices, int root);
bool findCycleUtil(int u, const vector<vector<int>>& adj, vector<int>& color, vector<int>& parent, int& cycle_start, int& cycle_end);


// --- DEFINIÇÃO DAS FUNÇÕES PÚBLICAS ---
double findMinimumArborescence(const GrafoListaAdj& graph, int root) {
    int V = graph.getNumVertices();
    vector<Edge> all_edges;

    for (int u = 0; u < V; ++u) {
        for (const auto& pair : graph.getAdjList()[u]) {
            all_edges.push_back({u, pair.first, pair.second});
        }
    }

    if (all_edges.empty()) {
        return 0.0;
    }
    
    return edmondsRecursive(all_edges, V, root);
}

double findMinimumArborescence(const GrafoMatrizAdj& graph, int root) {
    int V = graph.getNumVertices();
    vector<Edge> all_edges;
    const auto& matrix = graph.getAdjMatrix();

    for (int u = 0; u < V; ++u) {
        for (int v = 0; v < V; ++v) {
            if (matrix[u][v] != 0) {
                all_edges.push_back({u, v, matrix[u][v]});
            }
        }
    }

    if (all_edges.empty()) {
        return 0.0;
    }
    return edmondsRecursive(all_edges, V, root);
}


// --- DEFINIÇÃO DAS FUNÇÕES AUXILIARES ---

double edmondsRecursive(const vector<Edge>& edges, int num_vertices, int root) {
    // 1. Passo de Seleção Gulosa
    vector<Edge> min_incoming_edges(num_vertices, {-1, -1, -1});
    for (const auto& edge : edges) {
        if (min_incoming_edges[edge.v].u == -1 || edge.peso < min_incoming_edges[edge.v].peso) {
            min_incoming_edges[edge.v] = edge;
        }
    }
    min_incoming_edges[root] = {-1, -1, -1};

    // 2. Detecção de Ciclo
    vector<vector<int>> adj(num_vertices);
    double current_weight = 0;
    for (const auto& edge : min_incoming_edges) {
        if (edge.u != -1) {
            adj[edge.u].push_back(edge.v);
            current_weight += edge.peso;
        }
    }

    vector<int> color(num_vertices, 0);
    vector<int> parent(num_vertices, -1);
    int cycle_start = -1, cycle_end = -1;

    for (int i = 0; i < num_vertices; ++i) {
        if (color[i] == 0 && findCycleUtil(i, adj, color, parent, cycle_start, cycle_end)) {
            break;
        }
    }
    
    // 3. Se não há ciclos, a arborescência foi encontrada
    if (cycle_start == -1) {
        return current_weight;
    }

    // 4. Contração de Ciclo
    vector<int> cycle_nodes;
    vector<bool> is_in_cycle(num_vertices, false);
    int temp = cycle_end;
    while (true) {
        cycle_nodes.push_back(temp);
        is_in_cycle[temp] = true;
        if (temp == cycle_start) break;
        temp = parent[temp];
    }

    double cycle_weight = 0;
    for (int node : cycle_nodes) {
        cycle_weight += min_incoming_edges[node].peso;
    }

    vector<Edge> contracted_edges;
    for (const auto& edge : edges) {
        if (!is_in_cycle[edge.u] && is_in_cycle[edge.v]) {
            contracted_edges.push_back({edge.u, cycle_start, edge.peso - min_incoming_edges[edge.v].peso});
        } else if (!is_in_cycle[edge.u] && !is_in_cycle[edge.v]) {
            contracted_edges.push_back(edge);
        } else if (is_in_cycle[edge.u] && !is_in_cycle[edge.v]) {
            contracted_edges.push_back({cycle_start, edge.v, edge.peso});
        }
    }

    // 5. Chamada Recursiva
    return cycle_weight + edmondsRecursive(contracted_edges, num_vertices, root);
}

// Função auxiliar para o DFS de detecção de ciclo
bool findCycleUtil(int u, const vector<vector<int>>& adj, vector<int>& color, vector<int>& parent, int& cycle_start, int& cycle_end) {
    color[u] = 1; // Marca como visitando (cinza)

    for (int v : adj[u]) {
        if (color[v] == 0) { // Se o vizinho não foi visitado
            parent[v] = u;
            if (findCycleUtil(v, adj, color, parent, cycle_start, cycle_end))
                return true;
        } else if (color[v] == 1) { // Se encontrou um nó cinza, achou um ciclo
            cycle_end = u;
            cycle_start = v;
            return true;
        }
    }

    color[u] = 2; // Marca como visita completa (preto)
    return false;
}

#endif