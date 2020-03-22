
/* leetcode question 215 , 378 , 703 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/* leet 215 =======================================*/

void downheapify(vector<int> &arr, int idx, int lidx) // log(n)
{
    int maxidx = idx;
    int leftChild = (idx << 1) + 1;  // same as (2 * idx) + 1
    int rightChild = (idx << 1) + 2; // same as (2 * idx) + 2

    if (leftChild <= lidx && arr[leftChild] > arr[maxidx])
    {
        maxidx = leftChild;
    }

    if (rightChild <= lidx && arr[rightChild] > arr[maxidx])
    {
        maxidx = rightChild;
    }

    if (maxidx != idx)
    {
        swap(arr[maxidx], arr[idx]);
        downheapify(arr, maxidx, lidx);
    }
}

int findKthLargest(vector<int> &arr, int k)
{
    int n = arr.size() - 1;
    for (int i = n; i >= 0; i--) // n times
    {
        downheapify(arr, i, n); // log(k)
    }

    for (int i = 0; i < k; i++)
    {
        swap(arr[0], arr[n - i]);
        downheapify(arr, 0, n - i - 1); //log(k)
    }
    return arr[n - k + 1];
}

/* leet 378 ======================================= */

// int kthSmallest(vector<vector<int>> &matrix, int k)
// {
//     pair<int, pair<int, int>> pair;
//     priority_queue<pair<int, pair<int, int>>> pq;

//     int n = matrix.size();
//     int m = matrix[0].size();
//     for (int i = 0; i < n; i++)
//     {
//         pq.add(matrix[i][0]); // min pq
//         // pq.add(-matrix[i][0], i, 0);     // max pq
//     }

//     while(--k > 0)
//     {
//         pair p = pq.pop();
//         int x = p.i;
//         int y = p.j;

//         if (++y < m)
//             pq.add(new pair(matrix[x][y], x, y));
//     }
//     return pq.pop().ele;
// }

/* leet 703 ===================================== */

priority_queue<int, vector<int>, greater<int>> pq;
int size;
KthLargest(int k, vector<int> &nums)
{
    size = k;

    for (int ele : nums)
    {
        pq.push(ele);

        if (pq.size() > k)
        {
            pq.pop();
        }
    }
}

int add(int val)
{
    pq.push(val);

    if (pq.size() > size)
    {
        pq.pop();
    }
    return pq.top();
}

// main ===========================================

int main(int args, char **argv)
{
    // vector<int> arr = {3,2,3,1,2,4,5,5,6};
    // int k = 4;
    // cout << findKthLargest(arr, k);          // O(n + log(k) + log(k))

    //==============================================

    vector<vector<int>> matrix = {{1, 5, 9},
                                  {10, 11, 13},
                                  {12, 13, 15}};
    int k = 8;
    cout << kthSmallest(matrix, k);
}