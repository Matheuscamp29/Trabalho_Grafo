//classe vertice


#include <string>
#include <vector>

using namespace std;

class Vertice {
private:
    string nome; //label
    vector<Vertice> vizinhos; //guarda os vertices vizinhos

public:

    Vertice(string n) : nome(n){}

    //gets
    string getNome() const { 
        return nome; 
    }
    
    vector<Vertice> getVizinhos() const {
        return vizinhos; 
    }


    //sets
    void setNome(string n) { 
        nome = n;
    }
    
    void addVizinho(Vertice v) {
        vizinhos.push_back(v); 
    }
};

