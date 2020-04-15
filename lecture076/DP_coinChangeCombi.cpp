
//  coin change single move combination AKA target sum
//  coin change single move permutation does not support DP

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

//  using for loop method, tough to create in dp
int coinChangeNormal(int tar, int idx, vi &arr)
{
    if (tar == 0)
        return 1;

    int count = 0;
    for (int i = idx; i < arr.size(); i++)
    {
        if (tar - arr[i] >= 0)
        {
            count += coinChangeNormal(tar - arr[i], i + 1, arr);
        }
    }
    return count;
}

//  using subsequence like calls method, no dp
int coinChangeNormal01(int idx, int tar, vi &arr)
{
    if (idx == arr.size() || tar <= 0)
    {
        if (tar == 0)
        {
            return 1;
        }
        return 0;
    }

    int count = 0;
    if (tar - arr[idx] >= 0)
    {
        count += coinChangeNormal01(idx + 1, tar - arr[idx], arr);
        count += coinChangeNormal01(idx + 1, tar, arr);
    }
    return count;
}

//  using subsequence like calls method, with dp memorization (calling in reverse order of option array)
int coinChangeMemorisation(int idx, int tar, vi &arr, vii &dp)
{
    if (tar <= 0 || idx == -1)
    {
        if (tar == 0)
        {
            dp[idx + 1][tar] = 1; //  idx + 1 as we assume we also have a coin of 0 present in the beginning of the array which is actually not present, but still our dp is created based on that assumtion so idx = 0 row of dp is utilised for coin of zero
            return 1;
        }
        return 0;
    }

    if (dp[idx + 1][tar] != 0) //  idx + 1 as we assume we also have a coin of 0 present in the beginning of the array which is actually not present, but still our dp is created based on that assumtion so idx = 0 row of dp is utilised for coin of zero
    {
        return dp[idx][tar];
    }

    int count = 0;
    count += coinChangeMemorisation(idx - 1, tar - arr[idx], arr, dp);
    count += coinChangeMemorisation(idx - 1, tar, arr, dp);
    dp[idx + 1][tar] = count;   //  idx + 1 as we assume we also have a coin of 0 present in the beginning of the array which is actually not present, but still our dp is created based on that assumtion so idx = 0 row of dp is utilised for coin of zero
    return count;
}

// DP tabulation
// repetaion is allowed
int coinChangeCombination_DP(vi &arr, int tar)
{
    vii dp(arr.size() + 1, vi(tar + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= arr.size(); i++)
    {
        int idx = i - 1;
        for (int t = 0; t <= tar; t++)
        {
            if (t == 0)
            {
                dp[i][t] = 1;//  idx + 1 as we assume we also have a coin of 0 present in the beginning of the array which is actually not present, but still our dp is created based on that assumtion so idx = 0 row of dp is utilised for coin of zero
                continue;
            }

            if (t - arr[idx] >= 0)
            {
                dp[i][t] += dp[i - 1][t - arr[idx]];
            }
            dp[i][t] += dp[i - 1][t];
        }
    }
    display_2d(dp);
    return dp[arr.size()][tar];
}

void solve()
{
    vi arr = {2, 3, 5, 7};
    int target = 10;
    cout << coinChangeNormal(target, 0, arr) << endl;

    cout << coinChangeNormal01(0, target, arr) << endl;

    vii dp(arr.size() + 1,vi(target + 1, 0));
    cout << coinChangeMemorisation(arr.size() - 1, target, arr, dp) << endl;  //  we iterate from back of array to get desired dp

    cout << coinChangeCombination_DP(arr, target) << endl;
}

int main(int args, char **argv)
{
    solve();
    return 0;
}