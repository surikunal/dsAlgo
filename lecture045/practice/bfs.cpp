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

    Edge()
    {
        //default
    }
    Edge(int v, int w)
    {
        this->v = v;
        this->w = w;
    }
};
int n = 10;
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
    addEdge(4, 5, 2);
    addEdge(4, 6, 3);
    addEdge(5, 6, 8);

    addEdge(2, 7, 8);
    addEdge(7, 8, 8);
    addEdge(8, 9, 8);
    addEdge(7, 9, 8);

    display();
    cout << endl;
}

void bfs1(int src, int desti)
{
    queue<int> que;
    vector<bool> vis(n, false);

    int cycle = 0;
    int level = 0;
    que.push(src);
    que.push(-1);
    while (que.size() != 1)
    {
        int rvtx = que.front();
        que.pop();

        if (rvtx == -1)
        {
            level++;
            que.push(-1);
            continue;
        }

        if (vis[rvtx])
        {
            cout << "cycle : " << ++cycle << " @ " << rvtx << endl;
            continue;
        }

        if (rvtx == desti)
        {
            cout << "goal : " << level << endl;
        }

        vis[rvtx] = true;
        for (Edge *e : graph[rvtx])
        {
            if (!vis[e->v])
            {
                que.push(e->v);
            }
        }
    }
}

void bfs2(int src, int dest)
{
    queue<int> que;
    bool isDest = false;
    int level = 0;
    int cycle = 0;

    vector<bool> vis(n, false);
    que.push(src);

    while (que.size() != 0)
    {
        int size = que.size();
        while (size-- > 0)
        {
            int rvtx = que.front();
            que.pop();

            if (vis[rvtx])
            {
                cout << "cycle : " << ++cycle << " @ " << rvtx << endl;
                continue;
            }

            if (rvtx == dest && !isDest)
            {
                cout << "goal : " << level << endl;
                isDest = true;
            }

            vis[rvtx] = true;
            for (Edge *e : graph[rvtx])
            {
                if (!vis[e->v])
                {
                    que.push(e->v);
                }
            }
        }
        level++;
    }
}

void solve()
{
    constructGraph();
    // bfs1(0, 9);
    bfs2(0, 9);
}
int main(int args, char **argv)
{
    solve();
    return 0;
}