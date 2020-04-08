#include <iostream>
#include <vector>
#include <string>
using namespace std;

int targetSum(vector<int> &arr, int vidx, int target, string ans)
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
    count += targetSum(arr, vidx + 1, target - arr[vidx], ans + to_string(arr[vidx]) + " ");
    count += targetSum(arr, vidx + 1, target, ans);
    return count;
}
void setQuestion()
{
    vector<int> arr = {0, 10, 20, 30, 40, 50, 60, 70, 80};
    cout << targetSum(arr, 0, 60, "") << endl;
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