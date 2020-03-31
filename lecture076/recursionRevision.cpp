
/* recursion revision codes for the further dp class */
/* target sum */
/* 8 ways codes of coin change */

#include <iostream>
#include <vector>
#include <chrono>

#define vi vector<int>
#define vb vector<bool>
#define vii vector<vi>
#define vbb vector<vb>

using namespace std;

int targetSum(int vidx, vi &arr, int target, string ans)
{
    if (vidx == arr.size() || target <= 0)
    {
        if (target == 0)
        {
            cout << ans << endl;
            return 1;
        }
        return 0;
    }

    int count = 0;
    count += targetSum(vidx + 1, arr, target - arr[vidx], ans + to_string(arr[vidx]) + " ");
    count += targetSum(vidx + 1, arr, target, ans);
    return count;
}

//?================================================================

int coinChange_01(int vidx, vi &arr, int target, string ans)
{
    if (vidx == arr.size() || target <= 0)
    {
        if (target == 0)
        {
            cout << ans << endl;
            return 1;
        }
        return 0;
    }

    int count = 0;
    for (int i = vidx; i < arr.size(); i++)
    {
        if (target - arr[i] >= 0)
        {
            count += coinChange_01(i, arr, target - arr[i], ans + to_string(arr[i]) + " ");
        }
    }
    return count;
}

// ================================================================

int coinChange_02(int vidx, vi &arr, int target, string ans)
{
    if (vidx == arr.size() || target <= 0)
    {
        if (target == 0)
        {
            cout << ans << endl;
            return 1;
        }
        return 0;
    }

    int count = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (target >= arr[i])
        {
            count += coinChange_02(i, arr, target - arr[i], ans + to_string(arr[i]) + " ");
        }
    }
    return count;
}

// ================================================================

int coinChange_03(int vidx, vi &arr, int target, string ans)
{
    if (vidx == arr.size() || target <= 0)
    {
        if (target == 0)
        {
            cout << ans << endl;
            return 1;
        }
        return 0;
    }

    int count = 0;
    for (int i = vidx; i < arr.size(); i++)
    {
        if (target >= arr[i])
        {
            count += coinChange_03(i + 1, arr, target - arr[i], ans + to_string(arr[i]) + " ");
        }
    }
    return count;
}

// ================================================================

int coinChange_04(vi &arr, vb &isDone, int target, string ans)
{
    if (target == 0)
    {
        cout << ans << endl;
        return 1;
    }

    int count = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (target >= arr[i] && !isDone[i])
        {
            isDone[i] = true;
            count += coinChange_04(arr, isDone, target - arr[i], ans + to_string(arr[i]) + " ");
            isDone[i] = false;
        }
    }
    return count;
}

//==================== SUBSEQUENCE ================================

int coinChange_05(int vidx, vi &arr, int target, string ans)
{
    if (vidx == arr.size() || target <= 0)
    {
        if (target == 0)
        {
            cout << ans << endl;
            return 1;
        }
        return 0;
    }

    int count = 0;
    if (target >= arr[vidx])
    {
        count += coinChange_05(vidx, arr, target - arr[vidx], ans + to_string(arr[vidx]) + " ");
        count += coinChange_05(vidx + 1, arr, target, ans);
    }
    return count;
}

// ================================================================

int coinChange_06(int vidx, vi &arr, int target, string ans)
{
    if (vidx == arr.size() || target <= 0)
    {
        if (target == 0)
        {
            cout << ans << endl;
            return 1;
        }
        return 0;
    }

    int count = 0;
    if (target >= arr[vidx])
    {
        count += coinChange_06(0, arr, target - arr[vidx], ans + to_string(arr[vidx]) + " ");
        count += coinChange_06(vidx + 1, arr, target, ans);
    }
    return count;
}

// ================================================================

int coinChange_07(int vidx, vi &arr, int target, string ans)
{
    if (vidx == arr.size() || target <= 0)
    {
        if (target == 0)
        {
            cout << ans << endl;
            return 1;
        }
        return 0;
    }

    int count = 0;
    if (target >= arr[vidx])
    {
        count += coinChange_07(vidx + 1, arr, target - arr[vidx], ans + to_string(arr[vidx]) + " ");
        count += coinChange_07(vidx + 1, arr, target, ans);
    }
    return count;
}

// ================================================================

int coinChange_08(int vidx, vb &isDone, vi &arr, int target, string ans)
{
    if (vidx == arr.size() || target <= 0)
    {
        if (target == 0)
        {
            cout << ans << endl;
            return 1;
        }
        return 0;
    }

    int count = 0;
    if (target >= arr[vidx] && !isDone[vidx])
    {
        isDone[vidx] = true;
        count += coinChange_08(0, isDone, arr, target - arr[vidx], ans + to_string(arr[vidx]) + " ");
        isDone[vidx] = false;
    }
    count += coinChange_08(vidx + 1, isDone, arr, target, ans);
    return count;
}

//?================================================================
// main. ==========================================================
void solve()
{
    // vi arr1 = {10, 20, 30, 40, 50};
    // int target01 = 60;
    // cout << targetSum(0, arr1, target01, "") << endl;

    vi arr2 = {2, 3, 5, 7};
    vb isDone(arr2.size(), false);
    int target = 10;
    // cout << coinChange_01(0, arr2, target, "") << endl;
    // cout << coinChange_02(0, arr2, target, "") << endl;
    // cout << coinChange_03(0, arr2, target, "") << endl;
    // cout << coinChange_04(arr2, isDone, target, "") << endl;
    // cout << coinChange_05(0, arr2, target, "") << endl;
    // cout << coinChange_06(0, arr2, target, "") << endl;
    // cout << coinChange_07(0, arr2, target, "") << endl;
    // cout << coinChange_08(0, isDone, arr2, target, "") << endl;
}

int main(int args, char **argv)
{
    solve();
    return 0;
}