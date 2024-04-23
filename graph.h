#ifndef GRAPH
#define GRAPH

#include "node.h"
using namespace std;
#include <map>
#include<fstream>
#include <algorithm>

class graph
{
private:
    int numNodes = 0;
    map<int,Node*> nodes;
    
public:
    vector<int> path;
    void buildGraphFromFile(string filepath);
    void addNode(int name, string value);
    void addEdge(Node* ori, Node* des, int t);
    void addEdge(int oriName, int desName, int t);
    void print();
    vector<int> makeHamiltonianPath();
    void printReconstructionToFile(vector<int> pesos, string path);
    ~graph();
};

#endif
