//colocar os metodos do vertice aqui


#include <iostream>
#include <vector>
#include <string>
#include "Vertice.hpp"    
#include "Grafo.hpp"      
#include <algorithm>      

using namespace std;

void menuVertice(Grafo& g) {
    int opcao;
    do {
        cout << "Menu de Vertices do grafo " << g.getNome() << ":" << endl << endl
        << "0 - Voltar" << endl
        << "1 - Adicionar vertice" << endl
        << "2 - Listar vertices e seus viznhos" << endl
        << "3 - Adicionar ligacao/aresta" << endl
        << "4 - Excluir vertice" << endl
        << "5 - Adicionar 50 vertices automaticamente" << endl << endl;

        cin >> opcao;

        switch(opcao) {
            case 0://voltar
                cout << "Voltando ao menu principal." << endl;
            break;
            case 1: { //adicionar vertice
                string nome;
                cout << "Digite o label do vertice: ";
                cin >> nome;
                Vertice v(nome);
                g.addVertice(v);  //adiciona diretamente ao grafo
                cout << "Vertice adicionado com sucesso!" << endl << endl;
            }
            break;

            case 2: { //listar vertices
    vector<Vertice> vertices = g.getVertices();
    if (vertices.empty()) {
        cout << "Nao ha vertices no grafo." << endl;
    } else {
        cout << "Vertices do grafo " << g.getNome() << ":" << endl;
        cout << "nome --------------- vizinhos" << endl << endl;
        for (const auto& vertice : vertices) {
            cout << "-Vertice " << vertice.getNome() << " -> Vizinhos de " << vertice.getNome() << ": ";

            const vector<Vertice>& vizinhos = vertice.getVizinhos();  //pega os vizinhos do vertice
            if (vizinhos.empty()) {
                cout << "Nenhum vizinho." << endl;
            } else {
                //mostra os vizinhos
                for (size_t i = 0; i < vizinhos.size(); ++i) {
                    cout << vizinhos[i].getNome() << ", "; //mostra o nome do vizinho
                }
                cout << endl;
            }
        }
    }
}
break;

            case 3: { //adicionar vizinho a um vertice
                //listar os vertices
                vector<Vertice>& vertices = g.getVertices();
                if (vertices.empty()) {
                    cout << "Nao ha vertices no grafo." << endl;
                } else {
                    cout << "Vertices do grafo " << g.getNome() << ":" << endl;
                    for (size_t i = 0; i < vertices.size(); ++i) {
                        cout << i + 1 << ". " << vertices[i].getNome() << endl;  //listar vertices
                    }

                    //escolher um vertice
                    int verticeIndex;
                    cout << "Digite o numero do vertice ao qual voce deseja adicionar um vizinho: ";
                    cin >> verticeIndex;

                    if (verticeIndex < 1 || verticeIndex > static_cast<int>(vertices.size())) {
                        cout << "Indice de vertice invalido!" << endl;
                        break;
                    }

                    Vertice& verticeEscolhido = vertices[verticeIndex - 1];  //pega o vertice escolhido

                    //listar os vertices de novo para escolher o vizinho
                    cout << "Vertices disponíveis para adicionar como vizinho de " << verticeEscolhido.getNome() << ":" << endl;
                    for (size_t i = 0; i < vertices.size(); ++i) {
                        if (vertices[i].getNome() != verticeEscolhido.getNome()) {
                            cout << i + 1 << ". " << vertices[i].getNome() << endl;
                        }
                    }

                    //escolher o vizinho
                    int vizinhoIndex;
                    cout << "Digite o numero do vertice vizinho a ser adicionado: ";
                    cin >> vizinhoIndex;

                    if (vizinhoIndex < 1 || vizinhoIndex > static_cast<int>(vertices.size()) || vizinhoIndex == verticeIndex) {

                        cout << "Indice de vizinho invalido!" << endl;
                        break;
                    }

                    Vertice& vizinhoEscolhido = vertices[vizinhoIndex - 1];  //pega o vizinho escolhido

                    //adiciona o vizinho aos dois vertices (pq é grafo nao direcionado)
                    verticeEscolhido.addVizinho(vizinhoEscolhido);
                    vizinhoEscolhido.addVizinho(verticeEscolhido);

                    cout << "Vizinho " << vizinhoEscolhido.getNome() << " adicionado com sucesso a " << verticeEscolhido.getNome() << "!" << endl;
                }
            }
                            

            break;
            case 4: { //excluir vertice
               //listar todos os vertices
                vector<Vertice>& vertices = g.getVertices();
                if (vertices.empty()) {
                    cout << "Nao há vertices no grafo." << endl;
                    break;
                }

                //mostrar a lista de vertices
                cout << "Vertices do grafo " << g.getNome() << ":" << endl;
                for (size_t i = 0; i < vertices.size(); ++i) {
                    cout << i + 1 << ". " << vertices[i].getNome() << endl;
                }

                //qual vertice excluir
                int verticeIndex;
                cout << "Digite o numero do vertice a ser excluido: ";
                cin >> verticeIndex;

                if (verticeIndex < 1 || verticeIndex > static_cast<int>(vertices.size())) {
                    cout << "Indice de vertice invalido!" << endl;
                    break;
                }

                //pega o vertice a ser excluido
                Vertice& verticeExcluir = vertices[verticeIndex - 1];

                //remover esse vertice da lista de vizinhos de todos os outros vertices
                for (Vertice& v : vertices) {
                    if (v.getNome() != verticeExcluir.getNome()) {
                        //obter o vetor de vizinhos do vertice 'v'
                        vector<Vertice>& vizinhos = v.getVizinhos();

                        //encontrar o vertice a ser removido da lista de vizinhos
                        auto it = find_if(vizinhos.begin(), vizinhos.end(), [&verticeExcluir](const Vertice& vizinho) {
                            return vizinho.getNome() == verticeExcluir.getNome();
                        });

                        //se encontrar remove o vertice da lista de vizinhos
                        if (it != vizinhos.end()) {
                            vizinhos.erase(it);  //remove o vertice da lista de vizinhos
                        }
                    }
                }

                //exclui o vertice da lista de vertices do grafo
                vertices.erase(vertices.begin() + (verticeIndex - 1));  //remove o vertice da lista de vertices

                cout << "Vertice " << verticeExcluir.getNome() << " excluido com sucesso!" << endl << endl;
            }   
            break;
            case 5: { //adicionar 50 vertices automaticamente
                for (int i = 1; i <= 50; ++i) {
                    string nome = "V" + to_string(i);
                    Vertice v(nome);
                    g.addVertice(v);  //adiciona diretamente ao grafo
                }
                cout << "50 vertices adicionados com sucesso!" << endl << endl;
                break;
            }

            default:
                cout << "Opcao invalida. Tente novamente." << endl;
        }
    } while (opcao != 0);
}