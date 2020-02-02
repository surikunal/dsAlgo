#include<iostream>
#include<string>
#include<vector>

#define pii pair<int, int>
#define piii pair<int, pii>

using namespace std;

void desplay(vector<vector<pii>> &gp)
{
    for (int i = 0; i < gp.size(); i++)
    {
         cout << i << "->";
         for (pii e : gp[i])
         {
             cout << "(" << e.first << ", " << e.second << ")";
         }
         cout << endl;
    }
}

void merge(int p1, int p2, vector<int> &par, vector<int> &size)
{
    if (size[p1] < size[p2])
    {
        par[p1] = p2;
        size[p2] += size[p1];
    }
    else
    {
        par[p2] = p1;
        size[p1] += size[p2];
    }
}

int findPar(int vtx, vector<int> &par)
{
    if (par[vtx] == vtx)
    {
        return vtx;
    }

    par[vtx] = findPar(par[vtx], par);          //DATA COMPRESSION
    return par[vtx];
}

void kruskal()

void solve()
{
    kruskal();
}

int main(int args, char** argv)
{
    solve();
    return 0;
}