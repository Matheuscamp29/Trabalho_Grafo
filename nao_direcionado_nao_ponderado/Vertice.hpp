#ifndef VERTICE_HPP
#define VERTICE_HPP

#include <string>
#include <vector>

class Grafo;

using namespace std;

class Vertice {
private:
    string nome; //label
    vector<Vertice> vizinhos; //guarda os vertices vizinhos

public:
    Vertice(string n) : nome(n) {}

    //gets
    string getNome() const { 
        return nome; 
    }
    
    const vector<Vertice>& getVizinhos() const {
        return vizinhos; 
    }

    vector<Vertice>& getVizinhos() {
        return vizinhos; 
    }


    //sets
    void setNome(string n) { 
        nome = n;
    }
    
    void addVizinho(Vertice& v) {
        vizinhos.push_back(v); 
    }
};

void menuVertice(Grafo& g);

#endif
