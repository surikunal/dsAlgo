#include <iostream>
#include <vector>
#include <string>
using namespace std;

int coinChange1(vector<int> &arr, int vidx, int target, string ans)
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
            count += coinChange1(arr, i, target - arr[i], ans + to_string(arr[i]));
        }
    }
    return count;
}

int coinChange2(vector<int> &arr, int vidx, int target, string ans)
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
        if (target - arr[vidx] >= 0)
        {
            count += coinChange2(arr, i, target - arr[i], ans + to_string(arr[i]));
        }
    }
    return count;
}

int coinChange3(vector<int> &arr, int vidx, int target, string ans)
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
        if (target - arr[vidx] >= 0)
        {
            count += coinChange3(arr, i + 1, target - arr[i], ans + to_string(arr[i]));
        }
    }
    return count;
}

int coinChange4(vector<int> &arr, vector<int> &isdone, int target, string ans)
{
    if (target == 0)
    {
        cout << ans << endl;
        return 1;
    }

    int count = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (target - arr[i] >= 0 && !(isdone[i]))
        {
            isdone[i] = true;
            count += coinChange4(arr, isdone, target - arr[i], ans + to_string(arr[i]));
            isdone[i] = false;
        }
    }
    return count;
}

int coinchange5(vector<int> &arr, int vidx, int target, string ans)
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
    if (target - arr[vidx] >= 0)
    {
        count += coinchange5(arr, vidx, target - arr[vidx], ans + to_string(arr[vidx]));
        count += coinchange5(arr, vidx + 1, target, ans);
    }
    return count;
}

int coinchange6(vector<int> &arr, int vidx, int target, string ans)
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
    if (target - arr[vidx] >= 0)
    {
        count += coinchange6(arr, 0, target - arr[vidx], ans + to_string(arr[vidx]));
        count += coinchange6(arr, vidx + 1, target, ans);
    }
    return count;
}

int coinchange7(vector<int> &arr, int vidx, int target, string ans)
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
    if (target - arr[vidx] >= 0)
    {
        count += coinchange7(arr, vidx + 1, target - arr[vidx], ans + to_string(arr[vidx]));
        count += coinchange7(arr, vidx + 1, target, ans);
    }
    return count;
}

int coinchange8(vector<int> &arr, vector<int> &isdone, int vidx, int target, string ans)
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
    if (target - arr[vidx] >= 0)
    {
        isdone[vidx] = true;
        count += coinchange8(arr, isdone, 0, target - arr[vidx], ans + to_string(arr[vidx]));
        count += coinchange8(arr, isdone, vidx + 1, target, ans);
        isdone[vidx] = false;
    }
    return count;
}

int encoding(string ques, string ans)
{
    if (ques.size() == 0)
    {
        cout << ans << endl;
        return 1;
    }
    int count = 0;
    char ch = ques[0];

    if(ch == '0')
    {
        count += encoding(ques.substr(1), ans);
    }
    else
    {
        count += encoding(ques.substr(1), ans + (char)(ch - '1' + 'a'));
    
        if (ques.size() > 1)
        {
            char ch1 = ques[1];
            int num = ((ch - '0')*10 + (ch1 - '0'));
            if(num <= 26)
            {
                count += encoding(ques.substr(2), ans + (char)('a' + num - 1));
            }
        }
    }
    return count ;
}

void solve()
{
    vector<int> arr = {2, 3, 5, 7};
    // cout << coinChange1(arr, 0, 10, "");
    // cout << coinChange2(arr, 0, 10, "");
    // cout << coinChange3(arr, 0, 10, "");
    // vector<int> isdone(4,0);
    // cout << coinChange4(arr, isdone, 10, "");

    // cout << coinchange5(arr, 0, 10, "");
    // cout << coinchange6(arr, 0, 10, "");
    // cout << coinchange7(arr, 0, 10, "");
    // vector<int> isdone(4,0);
    // cout << coinchange8(arr, isdone, 0, 10, "");
    // cout << encoding("1124", "") << endl;
    // cout << encoding("1100024", "") << endl;
}
int main(int args, char **argv)
{
    solve();
    return 0;
}