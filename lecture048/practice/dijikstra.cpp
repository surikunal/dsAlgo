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
    Edge()
    {
        //defaut
    }
};

int n = 7;
vector<vector<Edge *>> graph(n, vector<Edge *>());
vector<vector<Edge *>> dGraph(n, vector<Edge *>());
vector<int> dShortestPath(n, 0);

void display(vector<vector<Edge *>> &gp)
{
    for (int i = 0; i < gp.size(); i++)
    {
        cout << i << "->";
        for (Edge *e : gp[i])
        {
            cout << "(" << e->v << ", " << e->w << ")";
        }
        cout << endl;
    }
}

void addEdge(vector<vector<Edge *>> &gp, int u, int v, int w)
{
    if (u < 0 || v < 0 || u >= n || v >= n)
        return;

    gp[u].push_back(new Edge(v, w));
    gp[v].push_back(new Edge(u, w));
}

void constructGraph()
{
    addEdge(graph, 0, 1, 11);
    addEdge(graph, 0, 3, 10);
    addEdge(graph, 1, 2, 20);
    addEdge(graph, 2, 3, 10);
    addEdge(graph, 3, 4, 2);
    addEdge(graph, 4, 5, 2);
    addEdge(graph, 4, 6, 3);
    addEdge(graph, 5, 6, 8);
    cout << endl;
}

class dpair{
public:
    int vtx = 0;
    int parent = 0;
    int wt = 0;
    int wsf = 0;

    dpair(int vtx, int parent, int wt, int wsf)
    {
        this->vtx = vtx;
        this->parent = parent;
        this->wt = wt;
        this->wsf = wsf;
    }

    bool operator<(dpair const &o) const
    {
        return this->wt > o.wt;
    }
};

void dijikstra(int src)
{
    priority_queue<dpair> que;  // not in heap (on stack) bcz no * is there , so here we use . to represent their children
    que.push(dpair(src, -1, 0, 0));
    vector<bool> vis(n, false);

    while (que.size() != 0)
    {
        dpair rp = que.top();
        que.pop();

        if (vis[rp.vtx])
        {
            continue;
        }

        if (rp.parent != -1)
        {
            addEdge(dGraph, rp.vtx, rp.parent, rp.wt);
            dShortestPath[rp.vtx] = rp.wsf;
        }

        vis[rp.vtx] = true;
        for (Edge *e : graph[rp.vtx])
        {
            if (!vis[e->v])
            {
                que.push(dpair(e->v, rp.vtx, e->w, rp.wsf + e->w));
            }
        }
    }
    
    display(dGraph);
    cout << endl;
    for (int ele : dShortestPath)
    {
        cout << ele << " ";
    }
}






void solve()
{
    constructGraph();
    dijikstra(0);
}

int main(int args, char **argv)
{
    solve();
    return 0;
}