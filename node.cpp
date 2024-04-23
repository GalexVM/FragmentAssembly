#include "node.h"

void Node::addEdge(edge * e)
{
    edges.emplace_back(e);
}
Node::~Node()
{
    for(auto& edge:edges){
        delete edge;
    }
}