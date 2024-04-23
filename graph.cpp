#include "graph.h"
void graph::buildGraphFromFile(string filepath)
{
    /*Read strings*/
    vector<string> strings;
    ifstream input(filepath);
    if(!input.is_open()){
        cout << "Error openning input file\n";
    }else{
        while (!input.eof())
        {
            string temp;
            getline(input,temp);
            strings.emplace_back(temp);
        }
    }
    input.close();
    /*Build graph*/
    for(int i = 0; i < strings.size(); i++) //Choose a string
    {
        if(nodes.count(i) == 0)
            this->addNode(i,strings[i]);
        for(int j =0; j < strings.size(); j++) //choose another string
        {
            if(j == i) continue; //no cicles
            int coincidence = 0;
            for(int k = 0; k < strings[i].size(); k++){ //look for sufixx-prefixx
                int pos = k;
                int length = strings[i].size()-k;
                string sub = strings[i].substr(pos,length);
                if (strings[j].size()>sub.size() && mismatch(sub.begin(), sub.end(), strings[j].begin()).first == sub.end()) //suffix-preffix
                {
                    coincidence = sub.size(); //t found
                    break;
                }
            }
            if(nodes.count(j) == 0) //Add node if new
                this->addNode(j,strings[j]);
            if(coincidence != 0)
                this->addEdge(i,j,coincidence); //Add edge
        }
    }
}
void graph::addNode(int name, string value)
{
    auto n = new Node(name, value);
    nodes[name] = n;
}
void graph::addEdge(Node * ori, Node * des, int t)
{
    auto e =  new edge(ori,des,t);
    ori->addEdge(e);
}
void graph::addEdge(int oriName, int desName, int t)
{
    this->addEdge(nodes[oriName], nodes[desName], t);
}
void graph::print()
{
    for(auto& node: nodes)
    {
        cout << node.first <<" -> ";
        for(auto& edge : node.second->edges)
        {
            cout << edge->destiny->name << ", ";
        }cout << endl;
    }
}
vector<int> graph::makeHamiltonianPath()
{
    path.clear();
    vector<int> pesos;
    bool canContinue = false;
    auto firstNode = nodes.begin()->second; //initial node
    
    if(firstNode->edges.size() > 0){
        firstNode->inPath = true; //add to path 
        canContinue = true;//make sure it has outs
        path.emplace_back(firstNode->name); //add to answer
    } 
    while(canContinue){
        edge** maxEdge = nullptr;
        for(auto& edge : firstNode->edges){
            if(!edge->destiny->inPath){
                maxEdge = &edge;//find an initial max that is out of the path
            }
            else{
                continue;
            }
            if(edge->t > (*maxEdge)->t && !edge->destiny->inPath)
                maxEdge = &edge; //heaviest out
        }
        if(!maxEdge){
            canContinue = false;
        }
        else{
            (*maxEdge)->destiny->inPath = true; //Add to path
            path.emplace_back((*maxEdge)->destiny->name); //Add to answer
            pesos.emplace_back((*maxEdge)->t);
            firstNode = (*maxEdge)->destiny; 
        }
        

    }
    return pesos;
}
void graph::printReconstructionToFile(vector<int> pesos, string filepath)
{
    int gap = 0;
    ofstream output(filepath);
    if(!output.is_open()){
        cout << "Error al abrir archivo\n";
    }
    else{
        output << nodes[path[0]]->fragment << endl;
        
        for(auto i = 1; i < path.size(); i++)
        {   
            gap+=nodes[path[i-1]]->fragment.size()-pesos[i-1];
            for(auto j = 0; j < gap; j++) 
                output << " ";
            output << nodes[path[i]]->fragment<<endl;
        }
    }
    output.close();
}
graph::~graph()
{
    for(auto& node : nodes){
        delete node.second;
    }
}