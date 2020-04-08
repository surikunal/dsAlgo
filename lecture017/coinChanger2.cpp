#include <iostream>
#include <string>
#include <vector>
using namespace std;
/* _________________combination___________________________*/
/* _______________without retpetation____________________ */
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
    for (int i = idx; i < arr.size(); i++)
    {
        if (target - arr[i] >= 0)
            count += coinchange(arr, i + 1, target - arr[i], ans + to_string(arr[i]) + " ");
    }
    return count;
}
/* __________________permutation___________________________*/
/* _______________without repetation______________________*/

int coinchange01(vector<int> &arr, vector<bool> &isdone, int target, string ans)
{
    if (target == 0)
    {
        cout << ans << endl;
        return 1;
    }

    int count = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (target - arr[i] >= 0 && !isdone[i])
        {
            isdone[i] = true;
            count += coinchange01(arr, isdone, target - arr[i], ans + to_string(arr[i]) + " ");
            isdone[i] = false;
        }
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
    cout << coinchange01(arr, isdone, 10, "") << endl;
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