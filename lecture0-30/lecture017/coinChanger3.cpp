
/* same question using SUBSEQUENCE method */

#include <iostream>
#include <string>
#include <vector>
using namespace std;
//================combination==============================
//=============with repetation=============================
int coinchange(vector<int> &arr, int idx, int target, string ans)
{
    if (idx == arr.size() || target <= 0)
    {
        if (target == 0)
        {
            cout << ans << endl;
            return 1;
        }
        return 0;
    }
    int count = 0;
    if (target - arr[idx] >= 0)
    {
        count += coinchange(arr, idx, target - arr[idx], ans + to_string(arr[idx]) + " ");
        count += coinchange(arr, idx + 1, target, ans);
    }
    return count;
}
//=====================permutaion===========================
//=============with repetation=============================

int coinchange01(vector<int> &arr, int idx, int target, string ans)
{
    if (idx == arr.size() || target <= 0)
    {
        if (target == 0)
        {
            cout << ans << endl;
            return 1;
        }
        return 0;
    }

    int count = 0;
    if (target - arr[idx] >= 0)
    {
        count += coinchange01(arr, 0, target - arr[idx], ans + to_string(arr[idx]) + " ");
        count += coinchange01(arr, idx + 1, target, ans);
    }
    return count;
}
void setQuestion()
{
    vector<int> arr = {2, 3, 5, 7};
    cout << "combinaton" << endl;
    cout << coinchange(arr, 0, 10, "") << endl;
    cout << "permutation" << endl;
    vector<bool> isdone(arr.size(), false);
    cout << coinchange01(arr, 0, 10, "") << endl;
}
void solve()
{
    setQuestion();
}
int main(int args, char **argv)
{
    solve();
    return 0;
}