#include <iostream>
#include <vector>
#include <chrono>

#define vi vector<int>
#define vii vector<vi>

using namespace std;

void display(vi &arr)
{
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
}

int singleOrPairingProblem_01(int n, vi &dp)
{
    if (n <= 1)
    {
        dp[n] = 1;
        return 1;
    }

    if (dp[n] != 0)
    {
        return dp[n];
    }

    int single = singleOrPairingProblem_01(n - 1, dp);
    int Pair = (n - 1) * singleOrPairingProblem_01(n - 2, dp);

    dp[n] = single + Pair;

    return dp[n];
}

int singleOrPairingProblem_02(int n, vi &dp)
{
    for (int i = 0; i < n; i++)
    {
        if (n <= 1) 
        {
            return 1;
            continue;
        }

        int single = dp[i - 1];
        int pair = (n - 1) * dp[n - 2];

        dp[i] = single + pair;
    }
    return dp[n];
}

int singleOrPairingProblem_03(int n)
{
    if (n <= 1)
    {
        return 1;
    }

    int a = 1;
    int b = 1;
    int ans = 0;

    for (int i = 2; i <= n; i++)
    {
        ans = b + a * (i - 1);
        a = b;
        b = ans;
    }

    return ans;
}

void solve()
{
    int n = 5;
    vector<int> dp(n + 1, 0);
    auto start = std::chrono::steady_clock::now();

    cout << singleOrPairingProblem_01(n, dp) << endl;
    cout << singleOrPairingProblem_02(n, dp) << endl;
    cout << singleOrPairingProblem_03(n) << endl;       // here we dont even need extra memory

    auto end = std::chrono::steady_clock::now();
    double time = double(std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count());
    std::cout << "time = " << time  << std::endl;
}

int main(int args, char **argv)
{
    solve();
    return 0;
}