#include <iostream>
#include <vector>
#include <chrono>
#include <list>
#define vi vector<int>
#define vii vector<vi>
using namespace std;

void display_1D(vi &dp)
{
    for (int i : dp)
    {
        cout << i << " ";
    }
    cout << endl;
}

void display_2D(vii &dp)
{
    for (vi ar : dp)
    {
        for (int i : ar)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}

int countTileTheFloor_01(int n, int m, vi &dp)
{
    if (n <= m)
    {
        dp[n] = ((n == m) ? 2 : 1);
        return dp[n];
    }

    if (dp[n] != 0)
    {
        return dp[n];
    }

    int horizontal = countTileTheFloor_01(n - 1, m, dp);
    int vertical = countTileTheFloor_01(n - m, m, dp);

    dp[n] = horizontal + vertical;

    return dp[n];
}

//* DP
int countTileTheFloor_02(int n, int m, vi &dp)
{
    for (int i = 0; i <= n; i++)
    {
        if (i <= m)
        {
            dp[i] = ((i == m) ? 2 : 1);
            continue;
        }

        int horizontal = dp[i - 1];
        int vertical = dp[i - m];

        dp[i] = horizontal + vertical;
    }
    return dp[n];
}

int countTileTheFloor_03(int n, int m)
{
    if (n <= m)
    {
        return ((n == m) ? 2 : 1);
    }

    list<int> ll;
    for (int i = 1; i <= m; i++)
    {
        ll.push_back(1);
    }

    for (int i = m; i <= n; i++)
    {
        int horizontal = ll.back();     //dp[i-1]
        int vertical = ll.front();     //dp[i-m]

        ll.push_back(horizontal + vertical);
        ll.pop_front();
    }
    return ll.back();
}

void solve()
{
    int n = 7;
    int m = 4;
    vi dp(n + 1, 0);
    auto start = std::chrono::steady_clock::now();

    // cout << countTileTheFloor_01(n, m, dp) << endl;
    // display_1D(dp);      // first one in the array should be 1, but it is never hitting the base case thats why it is printing 0

    // cout << countTileTheFloor_02(n, m, dp) << endl;
    // display_1D(dp);

    // cout << countTileTheFloor_03(n, m) << endl;

    auto end = std::chrono::steady_clock::now();
    double time = double(std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count());
    std::cout << "time = " << time / 1e6 << std::endl;
}

int main(int args, char **argv)
{
    solve();
    return 0;
}