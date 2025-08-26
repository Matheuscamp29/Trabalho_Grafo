//classe do grafo


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