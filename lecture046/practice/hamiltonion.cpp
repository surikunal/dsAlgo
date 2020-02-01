#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;

class Edge{
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
int n = 7;
vector<vector<Edge *>> graph(n, vector<Edge *>());

void display()
{
    for (int i = 0; i < n; i++)
    {
        cout << i << " -> ";
        for (Edge *e : graph[i])
        {
            cout << "(" << e->v << ", " << e->w << ")";
        }
        cout << endl;
    }
}

void addEdge(int u, int v)
{
    if (u < 0 || v < 0 || u >= n || v >= n)
    return;

    graph[u].push_back(new Edge(v));
    graph[v].push_back(new Edge(u));
}

constructGraph()
{
    addEdge(0, 3);
    addEdge(0, 1);
    addEdge(1, 2);
    addEdge(2, 3);
    addEdge(4, 3);
    addEdge(4, 5);
    addEdge(4, 6);
    addEdge(5, 6);
    addEdge(2, 5);

    display();
    cout << endl;
}


int hamiltonion(int vtx, int src, int vtxCount, vector<bool> &vis, string ans)
{
    if (vtxCount == graph.size() - 1)
    {
        for (Edge *e : graph[vtx])
        {
            if (e->v == src)
            {
                cout << "hami cycle : " << ans + to_string(vtx) <<endl;
                return 1;
            }
        }

        cout << "path : " << ans + to_string(vtx) << endl;
        return 1;
    }

    int count = 0;
    vis[vtx] = true;
    for (Edge *e : graph[vtx])
    {
        if (!vis[e->v])
        {
            count += hamiltonion(e->v, src, vtxCount + 1, vis, ans + to_string(vtx) + "->");
        }
    }
    vis[vtx] = false;
    return count;
}


void solve()
{
    constructGraph();
    vector<bool> vis(n, false);
    cout << hamiltonion(0, 0, 0, vis, "");
}

int main(int args, char **argv)
{
    solve();
    return 0;
}