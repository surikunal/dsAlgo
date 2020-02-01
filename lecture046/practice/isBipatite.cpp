#include <iostream>
#include <vector>
#include <string>
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

bool isBipatite_(int i, vector<int> &vis)
{
    queue<pair<int, int>> que;
    que.push({i, 0});
    bool flag = true;

    while (que.size() != 0)
    {
        pair<int, int> rvtx = que.front();
        que.pop();

        if (vis[rvtx.first] != -1)
        {
            if (vis[rvtx.first] != rvtx.second)
            {
                cout << "conflict at " << rvtx.first << endl;
                flag = false;
            }
            continue;
        }

        vis[rvtx.first] = rvtx.second;
        for (Edge* e : graph[rvtx.first])
        {
            if (vis[e->v] == -1)
            {
                que.push({e->v, (rvtx.second + 1) % 2});
            }
        }
    }
    return flag;
}

void isBipatite()
{
    vector<int> vis(n, -1);
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == -1)
        {
            cout << (boolalpha) << isBipatite_(i, vis);
        }
    }
}

void solve()
{
    constructGraph();
    vector<bool> vis(n, false);
    isBipatite();
}

int main(int args, char **argv)
{
    solve();
    return 0;
}