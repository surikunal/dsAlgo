#include <iostream>
#include <vector>

#define vi vector<int>
#define vii vector<vi>

using namespace std;

void display(vi &dp)
{
    for (int ele : dp)
    {
        cout << ele << " ";
    }
}

// memorisation
int fibo_01(int n, vi &dp)
{
    if (n <= 1)
    {
        dp[n] = n;
        return n;
    }

    if (dp[n] != 0)
    {
        return dp[n];
    }

    int ans = fibo_01(n - 1, dp) + fibo_01(n - 2, dp);
    dp[n] = ans; // dp can be on and off here (by commenting or decommenting this line)
    return ans;
}

// tabulation
int fibo_02(int n, vi &dp)
{
    for (int i = 0; i <= n; i++)
    {
        if (i <= 1)
        {
            dp[i] = i;
            continue;
        }

        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

void set_01()
{
    // int n = 10;
    // vector<int> arr(n + 1, 0);
    // cout << fibo_01(10, arr);
    // cout << endl;
    // display(arr);
    // cout << endl;

    // vector<int> arr(n + 1, 0);
    // cout << fibo_02(10, arr);
    // cout << endl;
    // display(arr);
    // cout << endl;
}

void display_2D(vii &arr)
{
    for (vi i : arr)
    {
        for (int j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

//* memorisation
int mazepathHV_01(int sr, int sc, int er, int ec, vii &dp)
{
    if (sr == er && sc == ec)
    {
        dp[sr][sc] = 1;
        return 1;
    }

    //  if we already have a answer the we are going to use it, without call any further
    if (dp[sr][sc] != 0)
    {
        return dp[sr][sc];
    }

    // upper traingular and lower triangular matrix have the same answer then why call twice
    //* but it only work for square matrix
    if (er == ec && dp[sr][sc] != 0)
    {
        return dp[sc][sr];
    }

    int count = 0;
    if (sr + 1 <= er)
    {
        count += mazepathHV_01(sr + 1, sc, er, ec, dp);
    }

    if (sc + 1 <= ec)
    {
        count += mazepathHV_01(sr, sc + 1, er, ec, dp);
    }

    //* if we comment this line that means we commented the dp
    dp[sr][sc] = count;

    if (er == ec)
    {
        dp[sc][sr] = count;
    }

    return count;
}

//* tabulation
int mazepathHV_02(int er, int ec, vii &dp)
{
    for (int sr = er; sr >= 0; sr--)
    {
        for (int sc = ec; sc >= 0; sc--)
        {
            if (sr == er && sc == ec)
            {
                dp[sr][sc] = 1;
                continue;
            }

            int count = 0;
            if (sr + 1 <= er)
            {
                count += dp[sr + 1][sc];
            }

            if (sc + 1 <= ec)
            {
                count += dp[sr][sc + 1];
            }

            dp[sr][sc] = count;
        }
    }
    return dp[0][0];
}

//* memorisation
int mazepathHVD_01(int sr, int sc, int er, int ec, vii &dp)
{
    if (sr == er && sc == ec)
    {
        dp[sr][sc] = 1;
        return 1;
    }

    if (dp[sr][sc] != 0)
    {
        return dp[sr][sc];
    }

    if (er == ec && dp[sr][sc] != 0)
    {
        return dp[sc][sr];
    }

    int count = 0;
    if (sr + 1 <= er)
    {
        count += mazepathHVD_01(sr + 1, sc, er, ec, dp);
    }

    if (sc + 1 <= ec)
    {
        count += mazepathHVD_01(sr, sc + 1, er, ec, dp);
    }

    if (sr + 1 <= er && sc + 1 <= ec)
    {
        count += mazepathHVD_01(sr + 1, sc + 1, er, ec, dp);
    }

    dp[sr][sc] = count;

    if (er == ec)
    {
        dp[sc][sr] = count;
    }

    return count;
}

//* tabulation
int mazepathHVD_02(int er, int ec, vii &dp)
{
    for (int sr = er; sr >= 0; sr--)
    {
        for (int sc = ec; sc >= 0; sc--)
        {
            if (sr == er && sc == ec)
            {
                dp[sr][sc] = 1;
                continue;
            }

            int count = 0;
            if (sr + 1 <= er)
            {
                count += dp[sr + 1][sc];
            }

            if (sc + 1 <= ec)
            {
                count += dp[sr][sc + 1];
            }

            if (sc + 1 <= ec && sr + 1 <= er)
            {
                count += dp[sr + 1][sc + 1];
            }

            dp[sr][sc] = count;
        }
    }
    return dp[0][0];
}

void set_02()
{
    int n = 3;
    vii arr(n, vi(n, 0));
    // cout << mazepathHV_01(0, 0, n - 1, n - 1, arr) << endl;
    // display_2D(arr);
    // cout << mazepathHV_02(n - 1, n - 1, arr) << endl;
    // display_2D(arr);

    // cout << mazepathHVD_01(0, 0, n - 1, n - 1, arr) << endl;
    // display_2D(arr);
    // cout << mazepathHVD_02(n - 1, n - 1, arr) << endl;
    // display_2D(arr);
}

void solve()
{
    // set_01();
    // set_02();
}

int main(int args, char **argv)
{
    solve();
    return 0;
}