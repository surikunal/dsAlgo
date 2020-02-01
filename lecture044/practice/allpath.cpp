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
            cout << "(" << e->v << ", " << e->w << ") ";
        }
        cout << endl;
    }
}

void addEdge(int u, int v, int w)
{
    if (u < 0 || v < 0 || u >= graph.size() || v >= graph.size())
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
    addEdge(3, 4, 8);
    addEdge(4, 5, 8);
    addEdge(4, 6, 8);
    addEdge(5, 6, 8);

    display();
    cout << endl;
}

int allpath(int src, int dest, vector<bool> &vis, int wsf, string psf)
{
    if (src == dest)
    {
        cout << psf + " @ " + to_string(wsf) <<endl;
        return 0;
    }

    int count = 0;
    vis[src] = true;
    for (Edge *e : graph[src])
    {
        if (!vis[e->v])
        {
            count += allpath(e->v, dest, vis, wsf + e->w, psf + to_string(e->v));
        }
    }
    vis[src] = false;
    return count;
}

void solve()
{
    constructGraph();
    vector<bool> vis(n, false);
    cout << allpath(0, 6, vis, 0, to_string(0) + "");
}

int main(int args, char **argv)
{
    solve();
    return 0;
}