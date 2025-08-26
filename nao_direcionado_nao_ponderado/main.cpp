//main

#include <iostream>
#include <vector>
#include <string>
#include "vertice.hpp"
#include "Grafo.hpp"
#include "vertice.cpp"
#include "Grafo.cpp"


using namespace std;

vector<Grafo> grafos; //guarda todos os grafos criados

int main() {

    int opcao;
    do {
        //começar pelo menu de grafo
        cout << "Menu: " << endl
        << "0 - Parar" << endl
        << "1 - Adicionar grafo" << endl
        << "2 - Editar grafo existente" << endl
        << "3 - Excluir grafo" << endl;

        cin >> opcao;

        switch(opcao) {
        
            case 0: //parar
                cout << "Fim do programa!" << endl;
            break;
            case 1://adicionar grafo
                criar_grafo();
            break;
            case 2://editar grafo existente
                cout << "Escolhe um grafo!" << endl;

                listarGrafos();//mostra os grafos existentes para o usuario escolher um 
                
                int indice;
                cin >> indice;
                
                if (indice >= 1 && indice <= grafos.size()) {
                    cout << "Você escolheu o grafo: " << grafos[indice - 1].getNome() << endl;
                } else {
                    cout << "Grafo inválido!" << endl;
                    break; //sai do switch se o índice for inválido
                }

                menuVertice(grafos[indice - 1]); //entra no menu para editar os vertices do grafo escolhido
            break;
            case 3://excluir grafo
                 cout << "Escolhe um grafo!" << endl;

                listarGrafos();
                int indice;
                cin >> indice;

                excluirGrafo(indice);
            break;
            case 4:
                
            break;
            default:
                cout << "Digite um número válido" << endl;
            break;
        }

    } while (opcao != 0);

    return 0;
}