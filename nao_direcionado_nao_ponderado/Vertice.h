//classe vertice


#include <string>
#include <vector>

using namespace std;

class Vertice {
private:
    string nome; //label
    int id;
    vector<int> vizinhos; //guarda o id dos vertices vizinhos

public:

    Vertice(string n, int i) : nome(n), id(i){}

    //gets
    string getNome() const { 
        return nome; 
    }
    int getId() const { 
        return id; 
    }
    vector<int> getVizinhos() const {
        return vizinhos; 
    }


    //sets
    void setNome(string n) { 
        nome = n;
    }
    void setId(int i) {
        id = i; 
    }
    void addVizinho(int v) {
        vizinhos.push_back(v); 
    }
};

