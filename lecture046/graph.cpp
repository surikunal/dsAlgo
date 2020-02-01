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
    // graph[v].push_back(new Edge(u, w));      // comment this for topological sort
}

void constructGraph()
{
    //pattern for hamiltonion path
    // addEdge(0, 1, 10);
    // addEdge(0, 3, 10);
    // addEdge(1, 2, 10);
    // addEdge(2, 3, 40);
    // addEdge(3, 4, 2);
    // addEdge(4, 5, 2);
    // addEdge(4, 6, 3);
    // addEdge(5, 6, 8);
    // addEdge(5, 2, 8);
    //extra
    // addEdge(2, 5, 8);
    // addEdge(0, 6, 8);

    // pattern for topological sort
    addEdge(0, 1, 8);
    addEdge(1, 2, 8);
    addEdge(2, 3, 8);
    addEdge(0, 4, 8);
    addEdge(7, 4, 8);
    addEdge(7, 6, 8);
    addEdge(6, 5, 8);
    addEdge(5, 3, 8);

    display();
    cout << endl;
}

int hamiltonionPath(int vtx, int src, int vtxCount, vector<bool> &vis, string ans)
{
    if (vtxCount == graph.size() - 1)
    {
        for (Edge *e : graph[vtx])
        {
            if (e->v == src)
            {
                cout << "cycle : " + ans + to_string(vtx) << endl;
                return 1;
            }
        }

        cout << "path : " + ans + to_string(vtx) << endl;
        return 1;
    }

    vis[vtx] = true;
    int count = 0;
    for (Edge *e : graph[vtx])
    {
        if (!vis[e->v])
        {
            count += hamiltonionPath(e->v, src, vtxCount + 1, vis, ans + to_string(vtx) + "->");
        }
    }
    vis[vtx] = false;
    return count;
}

// class ColorPair
// {
// public:
//     int vtx;
//     int color;
//     ColorPair(int vtx, int color)
//     {
//         this->vtx = vtx;
//         this->color - color;
//     }
//     ColorPair()
//     {
//         //default
//     }
// }

// either we can make a pair OR we can define a class
// the class is defined above and pair thing is done right below

bool isBipatite_(int i, vector<int> &vis)
{
    queue<pair<int, int>> que;
    bool flag = true;
    que.push({i, 0});

    while (que.size() != 0)
    {
        pair<int, int> rvtx = que.front();
        que.pop();

        if (vis[rvtx.first] != -1)
        {
            if (vis[rvtx.first] != rvtx.second)
            {
                cout << "conflict : " << endl;
                flag = false;
            }
            continue;
        }

        vis[rvtx.first] = rvtx.second;
        for (Edge *e : graph[rvtx.first])
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
    vector<int> vis(graph.size(), -1);
    int count = 0;

    for (int i = 0; i < graph.size(); i++)
    {
        if (vis[i] == -1)
        {
            cout << count << " " << (boolalpha) << isBipatite_(i, vis) << endl;
            count++;
        }
    }
}

// without handling cycle condition

void topologicalSort01_(int i, vector<bool> &vis, vector<int> &stack)
{
    vis[i] = true;
    for (Edge *e : graph[i])
    {
        if (!vis[e->v])
        {
            topologicalSort01_(e->v, vis, stack);
        }
    }
    stack.push_back(i);
}

void topologicalSort01()
{
    vector<bool> vis(n, false);
    vector<int> stack;

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            topologicalSort01_(i, vis, stack);
        }
    }

    while (stack.size() != 0)
    {
        cout << stack.back() << " ";
        stack.pop_back();
    }
}

// now we handles cycle condition in graph01.cpp
void solve()
{
    constructGraph();
    vector<bool> vis(n, false);
    // cout << hamiltonionPath(0, 0, 0, vis, "");
    // isBipatite();
    // topologicalSort01(); // without handling cycle condition
}

int main(int args, char **argv)
{
    solve();
    return 0;
}