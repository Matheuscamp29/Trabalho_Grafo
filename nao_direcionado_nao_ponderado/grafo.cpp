//funcoes/metodos do grafo

void criar_grafo() {
    string nome;
    int id;

    cout << "Digite o nome do grafo: ";
    cin >> nome;

    Grafo g(nome);
    grafos.push_back(g); //add o grafo no vetor de grafos

    cout << "Grafo criado com sucesso!" << endl;
}

void listarGrafos() {
    if (grafos.empty()) {
        cout << "Não há grafos criados." << endl;
    }

    cout << "Grafos existentes: " << endl;
    for (int i = 0; i < grafos.size(); i++) {
        cout << i + 1 << ". " << grafos[i].getNome() << endl;  // Exibe o nome de cada grafo
    }
}

void excluirGrafo(int indice) {
   
    grafos[indice - 1] = grafos.back(); // Substitui o grafo a ser removido pelo último grafo
    grafos.pop_back(); //remove o último grafo pra n ficar repetido
    cout << "Grafo excluído com sucesso!" << endl;
}
   

