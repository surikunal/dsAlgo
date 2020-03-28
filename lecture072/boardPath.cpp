#include <iostream>
#include <vector>

#define vi vector<int>
#define vii vcetor<vi>

using namespace std;

void display(vi &arr)
{
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
}

int boardPath_normal(int si, int ei, vi &dp)
{
    if (si == ei)
    {
        return 1;
    }

    int count = 0;
    for (int jump = 1; jump <= 6 && si + jump <= ei; jump++)
    {
        count += boardPath_normal(si + jump, ei, dp);
    }
    return count;
}

int boardPath_memorisation(int si, int ei, vi &dp)
{
    if (si == ei)
    {
        dp[si] = 1;
        return 1;
    }

    if (dp[si] != 0)
    {
        return dp[si];
    }

    int count = 0;
    for (int jump = 1; jump + si <= ei && jump <= 6; jump++)
    {
        count += boardPath_memorisation(si + jump, ei, dp);
    }

    dp[si] = count; // here we are making that array which is used for dynamic programming
    return count;
}

int boardPath_tabulation(int st, int end, vi &dp)
{
    for (int i = end; i >= st; i--)
    {
        if (i == end)
        {
            dp[i] = 1;
            continue;
        }
        int count = 0;

        for (int jump = 1; jump <= 6 && jump + i <= end; jump++)
        {
            count += dp[i + jump];
        }
        dp[i] = count;
    }
    return dp[0];
}

//* memorisation
int boardPath_01_givenOutcomes(int st, int end, vi &outcomes, vi &dp)
{
    if (st == end)
    {
        dp[st] = 1;
        return 1;
    }

    if (dp[st] != 0)
    {
        return dp[st];
    }

    int count = 0;
    for (int jump = 1; jump + st <= end; jump++)
    {
        count += boardPath_01_givenOutcomes(st + jump, end, outcomes, dp);
    }

    dp[st] = count;
    return count;
}

int boardPath_02_givenOutcomes(int st, int end, vi &outcomes, vi &dp)
{
    for (int i = st; i < end; i++)
    {
        if (i == end)
        {
            dp[i] = 1;
            continue;
        }

        int count = 0;
        for (int jump = 1; jump + st <= end; jump++)
        {
            count += boardPath_01_givenOutcomes(st + jump, end, outcomes, dp);
        }
        dp[i] = count;
    }
    return dp[0];
}

int main(int args, char **argv)
{
    int n = 10;
    vector<int> dp(n + 1, 0);
    // cout << boardPath_normal(0, n, dp) << endl;
    //* normal method does not use any array, so output of array will always be 0 in all indeces

    // cout << boardPath_memorisation(0, n, dp) << endl;
    // display(dp);

    // cout << boardPath_tabulation(0, n, dp) << endl;
    // display(dp);

    vi dp1 = {2, 3, 7, 5};
    // cout << boardPath_01_givenOutcomes(0, n, dp1, dp) << endl;
    // display(dp1);

    cout << boardPath_02_givenOutcomes(0, n, dp1, dp) << endl;
    display(dp1);
}