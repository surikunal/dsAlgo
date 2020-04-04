#include <iostream>
#include <vector>
#include <chrono>
#define vi vector<int>
#define vii vector<vi>
using namespace std;

void display(vii &dp)
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

int maxSquareAns = 0;
int maxSquareOf1s(int r, int c, vii &arr, vii &dp)
{
    if (r == arr.size() || c == arr[0].size())
    {
        return 0;
    }

    if (dp[r][c] != -1)     // we are putting -1 in dp bcz 0 has some significance
    {
        return dp[r][c];
    }

    int down = maxSquareOf1s(r + 1, c, arr, dp);
    int diag = maxSquareOf1s(r + 1, c + 1, arr, dp);
    int right = maxSquareOf1s(r, c + 1, arr, dp);
    
    int minPossibleSquares = 0;
    if (arr[r][c] == 1)
    {
        minPossibleSquares = min(down, min(right, diag)) + 1;
    }

    dp[r][c] = minPossibleSquares;
    maxSquareAns = max(dp[r][c], maxSquareAns);

    return dp[r][c];
}

//* DP
int maxSquareOf1s_02(vii &arr, vii &dp)
{
    int maxSquareAns = 0;
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        for (int j = arr[0].size() - 1; j >= 0; j--)
        {
            if (arr[i][j] == 1)
                dp[i][j] = min(dp[i + 1][ j], min(dp[i + 1][ j + 1], dp[i][j + 1])) + 1;

            else
                dp[i][j] = 0;

            maxSquareAns = max(dp[i][j],maxSquareAns);
        }
    }

    return maxSquareAns;
}

void solve()
{
    vii arr = {{0, 1, 1, 0, 1},
               {1, 1, 0, 1, 0},
               {0, 1, 1, 1, 0},
               {1, 1, 1, 1, 0},
               {1, 1, 1, 1, 1},
               {0, 0, 0, 0, 0}};
    vii dp(arr.size(), vi(arr[0].size(), -1));

    auto start = std::chrono::steady_clock::now();

    maxSquareOf1s(0, 0, arr, dp);
    cout << maxSquareAns;
    cout << endl;

    cout << maxSquareOf1s_02(arr, dp) << endl;
    
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