#include <iostream>
#include <vector>
#include <string>
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

    Edge()
    {
        //default
    }
};
int n = 7;
vector<vector<Edge *>> graph(n, vector<Edge *>());

void display()
{
    for (int i = 0; i < graph.size(); i++)
    {
        cout << i << " -> ";
        for (Edge *e : graph[i])
        {
            cout << "(" << e->v << ", " << e->w << ")";
        }
        cout << endl;
    }
}

void addEdge(int u, int v, int w)
{
    if (u < 0 || v < 0 || u >= n || v >= n)
        return;

    graph[u].push_back(new Edge(v, w));
    graph[v].push_back(new Edge(u, w));
}

void constructGraph()
{
    addEdge(0, 1, 8);
    addEdge(0, 3, 8);
    addEdge(1, 2, 8);
    addEdge(2, 3, 8);
    // addEdge(3, 4, 8);
    addEdge(4, 6, 8);
    addEdge(4, 5, 8);
    addEdge(5, 6, 8);

    display();
    cout << endl;
}

void dfs(int src, vector<bool> &vis)
{
    vis[src] = true;
    for (Edge *e : graph[src])
    {
        if (!vis[e->v])
        {
            dfs(e->v, vis);
        }
    }
}
void getConnectedComponents()
{
    vector<bool> vis(n, false);
    int count = 0;
    for (int i = 0; i < graph.size(); i++)
    {
        for (Edge *e : graph[i])
        {
            if (!vis[e->v])
            {
                count++;
                dfs(e->v, vis);
            }
        }
    }
    cout << count;
}

void solve()
{
    constructGraph();
    getConnectedComponents();
}

int main(int args, char **argv)
{
    solve();
    return 0;
}