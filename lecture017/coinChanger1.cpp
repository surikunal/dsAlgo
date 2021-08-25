#include <iostream>
#include <string>
#include <vector>
using namespace std;
//================combination==============================
//=============with repetation=============================g
int coinchange(vector<int>& arr, int idx, int target, string ans)
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
    for (int i = idx; i < arr.size(); i++)
    {
        if (target - arr[i] >= 0)
            count += coinchange(arr, i, target - arr[i], ans + to_string(arr[i]) + " ");
    }
    return count;
}
//=====================permutaion==========================
//===============with repetation===========================

int coinchange01(vector<int>& arr, int idx, int target, string ans)
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
    for (int i = 0; i < arr.size(); i++)
    {
        if (target - arr[i] >= 0)
            count += coinchange01(arr, i, target - arr[i], ans + to_string(arr[i]) + " ");
    }
    return count;
}
void setQuestion()
{
    vector<int> arr = {2, 3, 5, 7};
    cout << "combinaton" << endl;
    cout << coinchange(arr, 0, 10, "") << endl;
    cout << "permutation" << endl;
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