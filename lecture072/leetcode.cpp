

/* leetcode questions 64, 746, 70 */

//* 70. =======================================

class Solution
{
public:
    int climbStairs(int n)
    {
        if (n <= 1)
            return n;

        int a = 0, b = 1, sum = 0;
        while (n > 0)
        {
            sum = a + b;
            a = b;
            b = sum;
            n--;
        }
        return sum;
    }
};

//* 746. ========================================

class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        cost.push_back(0);
        int n = cost.size();

        vector<int> dp(n, 0);
        return minCostClimbingStairs_01(n - 1, cost, dp);
    }

    int minCostClimbingStairs_01(int n, vector<int> &cost, vector<int> &dp)
    {
        if (n <= 1)
            return cost[n];
        if (dp[n] != 0)
            return dp[n];
        int c1 = minCostClimbingStairs_01(n - 1, cost, dp);
        int c2 = minCostClimbingStairs_01(n - 2, cost, dp);

        return dp[n] = min(c1, c2) + cost[n];
    }

    int minCostClimbingStairs_02(int n, vector<int> &cost, vector<int> &dp)
    {

        for (int i = 0; i <= n; i++)
        {
            if (i <= 1)
            {
                dp[i] = cost[i];
                continue;
            }

            int c1 = dp[i - 1];
            int c2 = dp[i - 2];

            dp[i] = min(c1, c2) + cost[i];
        }

        return dp[n];
    }

    int minCostClimbingStairs_03(vector<int> &cost)
    {

        if (cost.size() == 1)
            return cost[0];
        if (cost.size() == 2)
            return min(cost[0], cost[1]);

        int a = cost[0];
        int b = cost[1];
        for (int i = 2; i < cost.size(); i++)
        {
            int ans = cost[i] + min(a, b);
            a = b;
            b = ans;
        }

        return min(a, b);
    }
};

//* 64. =========================================

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                if (i == n - 1 && j == m - 1)
                {
                    continue;
                }
                
                int c1 = i + 1 < n ? grid[i + 1][j] : 1e6;
                int c2 = j + 1 < m ? grid[i][j + 1] : 1e6;
                
                int minCost = min(c1, c2);
                grid[i][j] += minCost;
            }
        }
        return grid[0][0];
    }
};