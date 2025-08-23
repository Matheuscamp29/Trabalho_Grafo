//classe do grafo


#include <string>
#include <vector>
#include "Vertice.h" 

using namespace std;

class Grafo {
private:
    string nome; //nome do grafo
    int id;
    vector<Vertice> vertices; //guarda todos os vertices do grafo

public:

    Grafo(string n, int i) : nome(n), id(i){}

    //gets
    string getNome() const { 
        return nome; 
    }
    int getId() const { 
        return id; 
    }
    
     //sets
    void setNome(string n) { 
        nome = n;
    }
    void setId(int i) {
        id = i; 
    }
};