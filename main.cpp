#include <iostream>
#include "graph.h"

int main(){
    graph grafo;
    grafo.buildGraphFromFile("../input.txt", true);
    grafo.print();
    vector<int> r = grafo.makeHamiltonianPath();
    for(auto i : grafo.path) cout << i << "->";
    cout<<endl;
    for(auto i : r) cout << i << "  ";
    cout<<endl;
    grafo.printReconstructionToFile(r,"../res.txt");
    grafo.exportGraphToFile("../graph.txt");
}



