//classe do grafo
#ifndef GRAFO_HPP
#define GRAFO_HPP

#include <string>
#include <vector>
#include "Vertice.hpp" 

using namespace std;

class Grafo {
private:
    string nome; //nome do grafo (label)
    vector<Vertice> vertices; //guarda todos os vertices do grafo

public:

    Grafo(string n) : nome(n){}

    //gets
    string getNome() const { 
        return nome; 
    }
    vector<Vertice>& getVertices() { 
        return vertices; 
    }


   
     //sets
    void setNome(string n) { 
        nome = n;
    }
    void addVertice(Vertice v) {
        vertices.push_back(v); 
    }

}; 
    void criar_grafo();  
    void listarGrafos();  
    void excluirGrafo(int indice);  
    void menu2(int indice);  
#endif 
