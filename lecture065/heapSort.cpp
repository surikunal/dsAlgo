#include <iostream>
#include <vector>
using namespace std;

int compareTo(vector<int> &arr, int child, int par, bool isMax)
{
    if (isMax)
    {
        return arr[child] - arr[par];
    }
    else
    {
        return arr[par] - arr[child];
    }
}

void downheapify(vector<int> &arr, int idx, int lidx, bool isMax)       //log(n)
{
    int maxidx = idx;
    int lci = (2 * idx) + 1;
    int rci = (2 * idx) + 2;

    if (lci <= lidx && compareTo(arr, lci, maxidx, isMax) > 0)
    {
        maxidx = lci;
    }

    if (rci <= lidx && compareTo(arr, rci, maxidx, isMax) > 0)
    {
        maxidx = rci;
    }

    if (maxidx != idx)
    {
        swap(arr[maxidx], arr[idx]);
        downheapify(arr, maxidx, lidx, isMax);
    }
}

void heapSorting()
{
    vector<int> arr{10, 20, 30, -2, -3, -4, 5, 6, 7, 8, 9, 22, 11, 13};
    int n = arr.size() - 1;
    bool isMax = true;

    for (int i = arr.size() - 1; i >= 0; i--) 
    {
        downheapify(arr, i, n, isMax);
        // gives us a maxHeap
    }

    for (int i = 0; i <= n; i++) 
    {
        // for (int ele: arr)
        // {
        //     cout << ele << " ";
        // }
        // cout << endl;

        swap(arr[0], arr[n - i]);
        downheapify(arr, 0, n - i - 1, isMax);
    }

    for (int ele: arr)
    {
        cout << ele << " ";
    }
}

int main(int args, char **argv)
{
    heapSorting();
    return 0;
}