
//  coin change problem multi move permutation and combination by for loop solution(not subsequence solution)
//  ********** we can use coin change combination for solving equation -->  2x + 3y + 5z + 7p = 10 **********
/* 
solution :- 
    2 2 2 2 2   -> 2x  {x = 5}
    2 2 3 3     -> 2x + 3y  {x = 2, y = 2}
    2 3 5       -> 2x + 3y + 5z  {x = 1, y = 1, z = 1}
    3 7         -> 3y + 7p  {y = 1, p = 1}
*/

#include <iostream>
#include <vector>

#define vi vector<int>
#define vii vector<vi>
#define vb vector<bool>
#define vbb vector<vb>

using namespace std;

void display_1d(vi &arr)
{
    for (int i : arr)
    {
        cout << i << " ";
    }
}

void display_2d(vii &arr)
{
    for (vi &ar : arr)
    {
        for (int i : ar)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}

//  coin change permutation multi move by for loop(no subsequence), no dp
int coinChangePerm_Normal(int tar, vi &coins)
{
    if (tar == 0)
    {
        return 1;
    }
    int count = 0;
    for (int i = 0; i < coins.size(); i++)
    {
        if (tar - coins[i] >= 0)
        {
            count += coinChangePerm_Normal(tar - coins[i], coins);
        }
    }
    return count;
}

//  coin change combination multi move by for loop(no subsequence), no dp
int coinChangeComb_Normal(int tar, int vidx, vi &coins)
{
    if (tar == 0)
    {
        return 1;
    }
    int count = 0;
    for (int i = vidx; i < coins.size(); i++)
    {
        if (tar - coins[i] >= 0)
        {
            count += coinChangeComb_Normal(tar - coins[i], i, coins);
        }
    }
    return count;
}

//  coin change combination multi move by for loop(no subsequence), with dp memorization( not recommended as uses 2D dp)
int coinChangeComb_Memorisation(int tar, int vidx, vi &coins, vii &dp)
{
    if (tar == 0)
    {
        return dp[tar][vidx] = 1;
    }
    if (dp[tar][vidx] != 0)
    {
        return dp[tar][vidx];
    }
    int count = 0;
    for (int i = vidx; i < coins.size(); i++)
    {
        if (tar - coins[i] >= 0)
        {
            count += coinChangeComb_Memorisation(tar - coins[i], i, coins, dp);
        }
    }
    dp[tar][vidx] = count;
    return count;
}

//* target is variable
//* so we are making dp Array of target values

// memorisation
// permutation and repetaion is allowed
int coinChangePermutation_memorisation(vi &arr, int tar, vi &dp)
{
    if (tar == 0)
    {
        return dp[tar] = 1;
    }

    if (dp[tar] != 0)
    {
        return dp[tar];
    }

    int count = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (tar - arr[i] >= 0)
        {
            count += coinChangePermutation_memorisation(arr, tar - arr[i], dp);
        }
    }
    return dp[tar] = count;
}

// DP tabulation
int coinChangePermutation_DP(vi &arr, int tar, vi &dp)
{
    dp[0] = 1;
    for (int t = 1; t <= tar; t++)
    {
        int count = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            if (t - arr[i] >= 0)
            {
                dp[t] += dp[t - arr[i]];
            }
        }
    }
    return dp[tar];
}

//  coin change combination multi move by for loop(no subsequence), with dp tabulation
int coinChangeCombination_DP(vi &arr, int tar)
{
    vi dp(tar + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < arr.size(); i++) //  find solution for one coin for all 0 to target numbers
    {
        for (int t = 1; t <= tar; t++) //  change to next target for calculating answer for a particular coin as previous
        {
            if (t - arr[i] >= 0)
            {
                dp[t] += dp[t - arr[i]];
            }
        }
    }
    display_1d(dp);
    return dp[tar];
}

void solvePerm(int tar, vi &arr)
{
    cout << coinChangePerm_Normal(tar, arr) << endl;

    vi dp(tar + 1, 0);
    cout << coinChangePermutation_memorisation(arr, tar, dp) << endl;
    display_1d(dp);
    cout << endl;

    cout << coinChangePermutation_DP(arr, tar, dp) << endl;
    display_1d(dp);
    cout << endl;
}

void solveComb(int tar, vi &arr)
{
    cout << coinChangeComb_Normal(tar, 0, arr) << endl;

    vii dp(tar + 1, vi(arr.size(), 0));
    cout << coinChangeComb_Memorisation(tar, 0, arr, dp) << endl;
    display_2d(dp);

    cout << coinChangeCombination_DP(arr, tar) << endl;
}

void solve()
{
    vi arr = {2, 3, 5, 7};
    int target = 10;
    solvePerm(target, arr);
    solveComb(target, arr); 
}

int main(int args, char **argv)
{
    solve();
    return 0;
}