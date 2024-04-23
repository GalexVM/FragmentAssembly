#include <iostream>
#include "graph.h"

int main(){
    graph grafo;
    /*grafo.addNode(1,"TACGA");
    grafo.addNode(2,"ACCC");
    grafo.addNode(3,"CTAAAG");
    grafo.addNode(4,"GACA");
    grafo.addEdge(1,2,1);
    grafo.addEdge(1,4,2);
    grafo.addEdge(2,3,1);
    grafo.addEdge(3,4,1);
    grafo.addEdge(4,2,1);*/
    grafo.buildGraphFromFile("../input.txt");
    grafo.print();
    vector<int> r = grafo.makeHamiltonianPath();
    for(auto i : grafo.path) cout << i << "->";
    cout<<endl;
    for(auto i : r) cout << i << "  ";
    cout<<endl;
    grafo.printReconstructionToFile(r,"../res.txt");
}



