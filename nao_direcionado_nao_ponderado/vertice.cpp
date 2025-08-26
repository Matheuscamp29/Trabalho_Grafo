//colocar os metodos do vertice aqui


#include <iostream>
#include <vector>
#include <string>
#include "vertice.hpp"
#include "Grafo.hpp"
#include "Grafo.cpp"
using namespace std;

void menuVertice(Grafo &g) {
    int opcao;
    do {
        cout << "Menu de Vértices do grafo " << g.getNome() << ":" << endl
        << "0 - Voltar" << endl
        << "1 - Adicionar vértice" << endl
        << "2 - Listar vértices" << endl
        << "3 - Adicionar ligação/aresta (n implementado)" << endl
        << "3 - Excluir vértice" << endl;

        cin >> opcao;

        switch(opcao) {
            case 0://voltar
                cout << "Voltando ao menu principal." << endl;
            break;
            case 1: { //adicionar vertice
                string nome;
                cout << "Digite o label do vértice: ";
                cin >> nome;
                Vertice v1(nome);
                g.addVertice(v1);
                cout << "Vértice adicionado com sucesso!" << endl;

                //perguntar ao usuário se deseja adicionar um vizinho
                string nomeVizinho;
                cout << "Deseja adicionar um vizinho pra esse vértice? (s/n): ";
                char resposta;
                cin >> resposta;

                if (resposta == 's' || resposta == 'S') {
                    cout << "Digite o nome do vizinho: ";
                    cin >> nomeVizinho;

                    // Buscar o vértice vizinho
                    for (Vertice& v : g.getVertices()) { //percorre todos os vertices do grafo
                        if (v.getNome() == nomeVizinho) { 
                            v1.addVizinho(v); //adiciona o vizinho ao vértice atual
                            v.addVizinho(v1); //adiciona o vértice atual como vizinho do outro vértice
                            cout << "Vizinho " << nomeVizinho << " adicionado com sucesso!" << endl;
                            break;
                        }
                    }
                }
                            


            }
            break;
            case 2: { //listar vertices
                vector<Vertice> vertices = g.getVertices();
                if (vertices.empty()) {
                    cout << "Não há vértices no grafo." << endl;
                } else {
                    cout << "Vértices do grafo " << g.getNome() << ":" << endl;
                    for (const auto& vertice : vertices) {
                        cout << "- " << vertice.getNome() << endl;
                    }
                }
            }
            break;
            case 3: { 

                
            }
                

            break;
            case 4: { //excluir vertice
                string label;
                cout << "Digite o label do vértice a ser excluído: ";
                cin >> label;
                vector<Vertice>& vertices = g.getVertices();
                auto it = find_if(vertices.begin(), vertices.end(), [&label](const Vertice& v) {
                    return v.getNome() == label;
                });
                if (it != vertices.end()) {
                    vertices.erase(it);
                    cout << "Vértice excluído com sucesso!" << endl;
                } else {
                    cout << "Vértice não encontrado!" << endl;
                }
            }
            break;
            default:
                cout << "Opção inválida. Tente novamente." << endl;
        }
    } while (opcao != 0);
}