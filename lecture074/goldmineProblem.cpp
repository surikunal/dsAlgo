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

vii dirArr = {{0, 1}, {1, 1}, {-1, 1}};
int goldMineProblem_01(int x, int y, vii &arr, vii &dp)
{
    if (y == arr[0].size() - 1)
    {
        dp[x][y] = arr[x][y];
        return arr[x][y];
    }

    if (dp[x][y] != 0)
    {
        return dp[x][y];
    }

    int maxAns = -1e6;
    for (int d = 0; d < 3; d++)
    {
        int r = x + dirArr[d][0];
        int c = y + dirArr[d][1];

        if (r >= 0 && c >= 0 && r < arr.size() && c < arr[0].size())
        {
            maxAns = max(maxAns, goldMineProblem_01(r, c, arr, dp));
        }
    }

    dp[x][y] = maxAns + arr[x][y];
    return dp[x][y];
}

int goldMineProblem_02(vii &arr, vii &dp)
{
    for (int i = arr.size(); i >= 0; i--)
    {
        for (int j = arr[0].size(); j >= 0; j--)
        {
            if (j == arr[0].size() - 1)
            {
                dp[i][j] = arr[i][j];
                continue;
            }

            int maxAns = -1e6;
            for (int d = 0; d < 3; d++)
            {
                int r = i + dirArr[d][0];
                int c = j + dirArr[d][1];

                if (r >= 0 && c >= 0 && r < arr.size() && c < arr[0].size())
                {
                    maxAns = max(maxAns, dp[r][c]);
                }
            }
            dp[i][j] = maxAns + arr[i][j];
        }
    }

    int maxAns = -1e6;
    for (int row = 0; row < arr.size(); row++)
    {
        maxAns = max(maxAns, dp[row][0]);
    }
    return maxAns;
}

void solve()
{
    auto start = std::chrono::steady_clock::now();
    vii arr = {{1, 3, 3},
               {2, 1, 4},
               {0, 6, 4}};
    vii dp(arr.size(), vi(arr[0].size(), 0));

    // int maxAns = -1e6;
    // for (int row = 0; row < arr.size(); row++)
    // {
    //     maxAns = max(maxAns, goldMineProblem_01(row, 0, arr, dp));
    // }
    // cout << maxAns << endl;
    // display(dp);

    cout << goldMineProblem_02(arr, dp) << endl;
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