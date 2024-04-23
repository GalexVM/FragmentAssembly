#ifndef NODE
#define NODE
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Node;
struct edge;

struct edge{
    int t;
    Node* origin = nullptr, *destiny = nullptr;
    edge(Node* ori, Node* dest, int n):t(n),origin(ori),destiny(dest){}
};

class Node{
    private:
        
    public:
        int name;
        string fragment;
        bool inPath = false;
        Node(int n, string fr): name(n), fragment(fr){}
        vector<edge*> edges;
        void addEdge(edge* e);
    ~Node();

};
#endif