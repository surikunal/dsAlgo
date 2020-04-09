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
        for (int i : ar)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}

int burstBalloon(vi &arr, int si, int ei, vii &dp)
{
    if (dp[si][ei] != 0)
        return dp[si][ei];

    int l = ((si - 1) == -1) ? 1 : arr[si - 1];
    int r = ((ei + 1) == arr.size()) ? 1 : arr[ei + 1];

    int maxAns = 0;
    for (int cut = si; cut <= ei; cut++)
    {
        int left = (cut == si) ? 0 : burstBalloon(arr, si, cut - 1, dp);
        int right = (cut == ei) ? 0 : burstBalloon(arr, cut + 1, ei, dp);

        int myCost = left + l * arr[cut] * r + right;

        if (maxAns < myCost)
            maxAns = myCost;
    }

    dp[si][ei] = maxAns;
    return dp[si][ei];
}

int burstBalloonDP(vi &arr, int si, int ei, vii &dp)
{
    for (int gap = 0; gap <= arr.size() - 1; gap++)
    {
        for (int si = 0, ei = gap; ei < arr.size(); si++, ei++)
        {
            int l = ((si - 1) == -1) ? 1 : arr[si - 1];
            int r = ((ei + 1) == arr.size()) ? 1 : arr[ei + 1];

            int myAns = 0;
            for (int cut = si; cut <= ei; cut++)
            {
                int left = (cut == si) ? 0 : dp[si][cut - 1];
                int right = (cut == ei) ? 0 : dp[cut + 1][ei];

                int myCost = left + l * arr[cut] * r + right;

                if (myAns < myCost)
                    myAns = myCost;
            }

            dp[si][ei] = myAns;
        }
    }
    return dp[0][arr.size() - 1];
}

void solve()
{
    auto start = std::chrono::steady_clock::now();

    vi arr = {3, 1, 5, 8};
    int n = arr.size();
    vii dp(n, vi(n, 0));
    cout << burstBalloon(arr, 0, arr.size() - 1, dp) << endl;
    cout << burstBalloonDP(arr, 0, arr.size() - 1, dp) << endl;
    display(dp);

    auto end = std::chrono::steady_clock::now();
    double time = double(std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count());
    std::cout << "time = " << time / 1e6 << std::endl;
}

int main(int rags, char **argv)
{
    solve();
    return 0;
}