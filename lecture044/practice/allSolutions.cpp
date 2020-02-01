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
    addEdge(0, 1, 10);
    addEdge(0, 3, 10);
    addEdge(1, 2, 10);
    addEdge(2, 3, 40);
    addEdge(3, 4, 2);
    addEdge(4, 6, 3);
    addEdge(4, 5, 2);
    addEdge(5, 6, 3);

    display();
    cout << endl;
}

int lwsf = -1;
string lpsf = "";

int swsf = 1e8;
string spsf = "";

void allSol(int src, int dest, vector<bool> &vis, int wsf, string psf)
{
    if (src == dest)
    {
        if (wsf < swsf)
        {
            swsf = wsf;
            spsf = psf + to_string(dest);
        }

        if (wsf > lwsf)
        {
            lwsf = wsf;
            lpsf = psf + to_string(dest);
        }
    }

    //dfs
    vis[src] = true;
    for (Edge *e : graph[src])
    {
        if (!vis[e->v])
        {
            allSol(e->v, dest, vis, wsf + e->w, psf + to_string(src) + " ");
        }
    }
    vis[src] = false;
}

void solve()
{
    vector<bool> vis(n, false);
    constructGraph();
    allSol(0, 6, vis, 0, "");
    cout << swsf << " @ " << spsf << endl;
    cout << lwsf << " @ " << lpsf << endl;
}

int main(int args, char **argv)
{
    solve();
    return 0;
}