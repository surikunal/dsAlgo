#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Edge
{
public:
    int v = 0;
    int w = 0;

    Edge(int v, int w)
    {
        this->v = v;
        this->w = w;
    }
    Edge(int v)
    {
        this->v = v;
    }
};

int n = 11;
vector<vector<Edge *>> graph(n, vector<Edge *>());

void display()
{
    for (int i = 0; i < graph.size(); i++)
    {
        cout << i << " -> ";
        for (Edge *e : graph[i])
        {
            cout << "(" << e->v << ")";
        }
        cout << endl;
    }
}

void addEdge(int u, int v)
{
    if (u < 0 || v < 0 || u >= n || v >= n)
        return;

    graph[u].push_back(new Edge(v));
}

void constructGraph()
{
    // addEdge(0, 1);
    // addEdge(0, 4);
    // addEdge(1, 2);
    // addEdge(2, 3);
    // addEdge(5, 4);
    // addEdge(5, 6);
    // addEdge(6, 7);
    // addEdge(7, 3);

    addEdge(0, 1);
    addEdge(1, 3);
    addEdge(3, 5);
    addEdge(0, 2);
    addEdge(2, 4);
    addEdge(4, 5);
    addEdge(7, 2);
    addEdge(7, 8);
    addEdge(8, 9);
    addEdge(9, 10);
    addEdge(10, 7);
    
    display();
    cout << endl;
}

//      here we also handled the case , if there is a cycle in the graph

bool topoSort_(int i, vector<bool> &vis, vector<bool> &cycleDetermination, vector<int> &stack)
{
    vis[i] = true;
    cycleDetermination[i] = true;
    bool res = false;

    for (Edge *e : graph[i])
    {
        if (!vis[e->v])
        {
            res = res || topoSort_(e->v, vis, cycleDetermination, stack);
        }
        else if (cycleDetermination[e->v])
        {
            return true;
        }
    }
    stack.push_back(i);
    cycleDetermination[i] = false;
    
    return res;
}

void  topoSort()
{
    vector<bool> vis(n, false);
    vector<bool> cycleDetermination(n, false);
    vector<int> stack;
    bool res = false;

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            res = res || topoSort_(i, vis, cycleDetermination, stack);
        }
    }

    // so if cycle detected then code will not give any output
    while (stack.size() != 0 && !res)
    {
        cout << stack.back() << " ";
        stack.pop_back();
    }
    cout << endl;
}

void solve()
{
    constructGraph();
    cout << endl;
    topoSort();
}

int main(int args, char **argv)
{
    solve();
    return 0;
}