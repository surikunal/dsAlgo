#include<iostream>
#include<vector>
using namespace std;

class Edge{
    public:
    int v=0; 
    int w=0;
    Edge(int v, int w)
    {
        this->v = v;
        this->w = w;
    } 
    Edge()
    {
        //default
    }
};
vector<vector<Edge*>> graph(7, vector<Edge *>());

void addEdge(int u,int v, int w)
{
    if(u<0|| v<0 || u>=graph.size() || v>=graph.size())
    return;

    graph[u].push_back(new Edge(v,w));
    graph[v].push_back(new Edge(u,w));
}

void display()
{
    for(int i=0; i<graph.size() ; i++)
    {
        cout<<i<< " => ";
        for(int j=0; j<graph[i].size() ; j++)
        {
            cout<< "( "<<graph[i][j]->v << ","<<graph[i][j] -> w <<" )";
        }
        cout<<endl;
    }
}
void removeEdge()
{

}

int main(int args, char** argv)
{
    addEdge(0,3,10);
    addEdge(0,1,10);
    addEdge(1,2,10);
    addEdge(2,3,10);
    addEdge(4,3,10);
    addEdge(4,5,10);
    addEdge(4,6,10);
    addEdge(5,6,10);
    cout<<endl;

    display();
    return 0;    
}