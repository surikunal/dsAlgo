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

int n = 13;
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
}

void constructGraph()
{
    //purana wala
    // addEdge(0, 1, 10);
    // addEdge(0, 3, 10);
    // addEdge(1, 2, 10);
    // addEdge(2, 3, 40);
    // addEdge(3, 4, 2);
    // addEdge(4, 5, 2);
    // addEdge(4, 6, 3);
    // addEdge(5, 6, 8);
    // //extra
    // addEdge(2, 5, 8);
    // addEdge(0, 6, 8);

    // addEdge(0, 1, 8);
    // addEdge(1, 2, 8);
    // addEdge(2, 3, 8);
    // addEdge(0, 4, 8);
    // addEdge(7, 4, 8);
    // addEdge(7, 6, 8);
    // addEdge(6, 5, 8);
    // addEdge(5, 3, 8);

    // example 1 wala pattern
    addEdge(0, 1, 8);
    addEdge(0, 2, 8);
    addEdge(1, 5, 8);
    addEdge(5, 6, 8);
    addEdge(6, 8, 8);
    addEdge(3, 2, 8);
    addEdge(3, 4, 8);
    addEdge(2, 7, 8);
    addEdge(4, 7, 8);
    addEdge(7, 6, 8);
    addEdge(7, 9, 8);
    addEdge(9, 10, 8);
    addEdge(9, 12, 8);
    addEdge(10, 11, 8);
    addEdge(11, 12, 8);

    // SCC wala graph / pattern
    // addEdge(11, 12, 8);
    // addEdge(11, 12, 8);
    // addEdge(11, 12, 8);
    // addEdge(11, 12, 8);
    // addEdge(11, 12, 8);
    // addEdge(11, 12, 8);
    // addEdge(11, 12, 8);
    // addEdge(11, 12, 8);
    // addEdge(11, 12, 8);
    // addEdge(11, 12, 8);
    // addEdge(11, 12, 8);
    // addEdge(11, 12, 8);
    // addEdge(11, 12, 8);
    // addEdge(11, 12, 8);

    display();
    cout << endl;
}

// without handling cycle condition
void topologicalSort_01(int src, vector<bool> &vis, vector<int> &stack)
{
    vis[src] = true;
    for (Edge *e : graph[src])
    {
        if (!vis[e->v])
        {
            topologicalSort_01(e->v, vis, stack);
        }
    }

    stack.push_back(src);
}
void topologicalSort01()
{
    vector<bool> vis(graph.size(), false);
    vector<int> stack;

    for (int i = 0; i < n; i++)
    {
        topologicalSort_01(i, vis, stack);
    }

    while (stack.size() != 0)
    {
        cout << stack.back() << " "; //giving the last element
        stack.pop_back();
    }
}

//----------------KHANS ALGO-----------------------

void topologicalSort_bfs()
{
    vector<int> inDegree(graph.size(), 0);
    for (int i = 0; i < inDegree.size(); i++)
    {
        for (Edge *e : graph[i])
        {
            inDegree[e->v]++;
        }
    }

    queue<int> que;
    for (int i = 0; i < inDegree.size(); i++)
    {
        if (inDegree[i] == 0)
        {
            que.push(i);
        }
    }

    vector<int> ans;
    while (que.size() != 0)
    {
        int rvtx = que.front();
        que.pop();
        ans.push_back(rvtx);

        for (Edge *e : graph[rvtx])
        {
            inDegree[e->v]--;
            if (inDegree[e->v] == 0)
            {
                que.push(e->v);
            }
        }
    }
    if (ans.size() != graph.size())
    {
        cout << "cycle" << endl;
    }
    else
    {
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
    }
}
void solve()
{
    constructGraph();
    cout << endl;
    // vector<bool> vis(n, false);
    // cout << hamiltonionPath(0, 0, 0, vis, "");
    // isBipatite();
    // topologicalSort01();
    topologicalSort_bfs();
}

int main(int args, char **argv)
{
    solve();
    return 0;
}