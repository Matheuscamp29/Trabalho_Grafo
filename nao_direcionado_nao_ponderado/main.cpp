//main

/*
2025/2
Aluno: Matheus de Oliveira Campello
Professor: Silvio Jamil Ferzoli Guimaraes
*/


/*
Compilar: g++ main.cpp grafo.cpp vertice.cpp -o programa
Executar: ./programa
*/
#include <iostream>
#include <vector>
#include <string>
#include "Grafo.hpp"    
#include "Vertice.hpp" 

using namespace std;

int main() {

    int opcao;
    do {
        //começar pelo menu de grafo
        cout << "Menu: " << endl << endl
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
                
                int indi;
                cin >> indi;
                
                menu2(indi - 1); //entra no menu para editar os vertices do grafo escolhido
            break;
            case 3://excluir grafo
                 cout << "Escolhe um grafo para excluir!" << endl;

                listarGrafos();
                int indice;
                cin >> indice;

                excluirGrafo(indice);
            break;
            default:
                cout << "Digite um numero valido" << endl;
            break;
        }

    } while (opcao != 0);

    return 0;
}