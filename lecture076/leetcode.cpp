
#include <iostream>
#include <vector>
using namespace std;
/* leetcode 377 */

int combinationSum4(vector<int> &nums, int target)
{
    vector<unsigned int> dp(target + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= target; i++)
    {
        for (int coin : nums)
        {
            if (i - coin >= 0)
            {
                dp[i] += dp[i - coin];
            }
        }
    }
    return dp[target];
}

/* leetcode 322 */

// memorisation
int minCoinsHeight(vector<int> &arr, int tar, vector<int> &dp)
{
    if (tar == 0)
        return 0;

    if (dp[tar] != 0)
        return dp[tar];

    int height = 1e8;
    for (int i = 0; i < arr.size(); i++)
    {
        if (tar - arr[i] >= 0)
        {
            int recAns = minCoinsHeight(arr, tar - arr[i], dp);
            if (recAns < height)
                height = recAns + 1;
        }
    }

    dp[tar] = height;
    return height;
}

// dp tabulation
int minCoinsHeight_dp(vector<int> &arr, int tar, vector<int> &dp)
{

    // for (int i = 0; i < dp.size(); i++)
    //     dp[i] = 1e8;

    dp[0] = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int t = 1; t <= tar; t++)
        {

            if (t - arr[i] >= 0)
            {
                dp[t] = min(dp[t], dp[t - arr[i]] + 1);
            }
        }
    }
    return dp[tar];
}

int coinChange(vector<int> &arr, int tar)
{
    if (arr.size() == 0 || tar <= 0)
        return 0;
    vector<int> dp(tar + 1, 1e8); // Arrays.fill(dp,(int)1e8);

    // int ans = minCoinsHeight(arr, tar, dp);
    int ans = minCoinsHeight_dp(arr, tar, dp);

    return ans != 1e8 ? ans : -1;
}