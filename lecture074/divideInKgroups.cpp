#include <iostream>
#include <vector>
#include <chrono>

#define vi vector<int>
#define vii vector<vi>
using namespace std;

void display(vii &arr)
{
    for (vi ar : arr)
    {
        for (int n : ar)
        {
            cout << n << " ";
        }
        cout << endl;
    }
}

//! this code will be best understaned by the tree in copy
int divideNelementsInKsets_01(int n, int k, vii &dp)
{
    if (n < k)
    {
        return 0;
    }

    if (n == k || k == 1)
    {
        dp[n][k] = 1;
        return 1;
    }

    if (dp[n][k] != 0)
    {
        return dp[n][k];
    }

    int saperateSet = divideNelementsInKsets_01(n - 1, k - 1, dp);
    int combinedSet = divideNelementsInKsets_01(n - 1, k, dp);

    dp[n][k] += saperateSet + (combinedSet * k);

    return dp[n][k];
}

int divideNelementsInKsets_02(int n, int k, vii &dp)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (i < j)
            {
                dp[i][j] = 0;
                continue;
            }

            if (i == j || j == 1)
            {
                dp[i][j] = 1;
                continue;
            }

            int saperateSet = dp[i - 1][j - 1];
            int combinedSet = dp[i - 1][j]; // n-1, number will divide in k sets and generate some x group.

            dp[i][j] += saperateSet + (combinedSet * j);
        }
    }
    return dp[n][k];
}

solve()
{
    int n = 5;
    int k = 2;
    vii dp(n + 1, vi(k + 1, 0));
    auto start = std::chrono::steady_clock::now();
    cout << divideNelementsInKsets_01(n, k, dp) << endl;
    display(dp);
    cout << divideNelementsInKsets_02(n, k, dp) << endl;
    display(dp);
    auto end = std::chrono::steady_clock::now();
    double time = double(std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count());
    std::cout << "time = " << time / 1e6 << std::endl;
}

int main(int args, char **argv)
{
    solve();
    return 0;
}