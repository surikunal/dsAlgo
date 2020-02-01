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

int n = 8;
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
    addEdge(0, 1);
    addEdge(0, 4);
    addEdge(1, 2);
    addEdge(2, 3);
    addEdge(5, 4);
    addEdge(5, 6);
    addEdge(6, 7);
    addEdge(7, 3);

    display();
    cout << endl;
}

void topoSort_(int src, vector<bool> &vis, vector<int> &stack)
{
    vis[src] = true;
    for (Edge *e : graph[src])
    {
        if (!vis[e->v])
        {
            topoSort_(e->v, vis, stack);
        }
    }

    stack.push_back(src);
}

void topoSort()
{
    vector<bool> vis(n, false);
    vector<int> stack;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            topoSort_(i, vis, stack);
        }
    }

    while (stack.size() != 0)
    {
        cout << stack.back() << " ";
        stack.pop_back();
    }
}

void solve()
{
    constructGraph();
    topoSort();
}

int main(int args, char **argv)
{
    solve();
    return 0;
}