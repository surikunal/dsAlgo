/*
khans algo is nothing but just topologocal sort using bfs method to solve
*/

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

int n = 13;
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
    addEdge(0, 2);
    addEdge(3, 2);
    addEdge(3, 4);
    addEdge(1, 5);
    addEdge(5, 6);
    addEdge(6, 8);
    addEdge(4, 7);
    addEdge(7, 6);
    addEdge(2, 7);
    addEdge(7, 9);
    addEdge(9, 12);
    addEdge(9, 10);
    addEdge(10, 11);
    addEdge(11, 12);

    display();
    cout << endl;
}

void topoSort_bfs()
{
    vector<int> InDegree(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (Edge *e : graph[i])
        {
            InDegree[e->v]++;
        }
    }

    queue<int> que;
    for (int i = 0; i < n; i++)
    {
        if (InDegree[i] == 0)
        {
            que.push(i);
        }
    }

    vector<int> stack;
    while (que.size() != 0)
    {
        int rvtx = que.front();
        que.pop();
        stack.push_back(rvtx);

        for (Edge *e : graph[rvtx])
        {
            InDegree[e->v]--;
            if (InDegree[e->v] == 0)
            {
                que.push(e->v);
            }
        }
    }
    if (stack.size() != n)
    {
        cout << "cycle" << endl;
    }
    else
    {
        for (int i = 0; i < stack.size(); i++)
        {
            cout << stack[i] << " ";
        }
    }
}

void solve()
{
    constructGraph();
    topoSort_bfs();
}

int main(int args, char **argv)
{
    solve();
    return 0;
}