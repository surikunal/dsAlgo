#include <iostream>
#include <string>
#include <vector>
using namespace std;
int infi_permu(vector<int> &arr, int idx, int target, string ans)
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
        {
            count += infi_permu(arr, i, target - arr[i], ans + to_string(arr[i]) + " ");
        }
    }
    return count;
}

int infi_combi(vector<int> &arr, int idx, int target, string ans)
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
            count += infi_combi(arr, i, target - arr[i], ans + to_string(arr[i]) + " ");
    }
    return count;
}

int combi_without_repe(vector<int> &arr, int idx, int target, string ans)
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
            count += combi_without_repe(arr, i + 1, target - arr[i], ans + to_string(arr[i]) + " ");
    }
    return count;
}

int permu_without_repe(vector<int> &arr, vector<bool> &isDone, int target, string ans)
{
    if (target == 0)
    {
        cout << ans << endl;
        return 1;
    }

    int count = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (target - arr[i] >= 0 && isDone[i] == false)
        {
            isDone[i] = true;
            count += permu_without_repe(arr, isDone, target - arr[i], ans + to_string(arr[i]) + " ");
            isDone[i] = false;
        }
    }
    return count;
}

int infi_combi_subseq(vector<int> &arr, int idx, int target, string ans)
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
        count += infi_combi_subseq(arr, idx, target - arr[idx], ans + to_string(arr[idx]) + " ");
        count += infi_combi_subseq(arr, idx + 1, target, ans);
    }
    return count;
}

int infi_permu_subseq(vector<int> &arr, int idx, int target, string ans)
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
        count += infi_permu_subseq(arr, 0, target - arr[idx], ans + to_string(arr[idx]) + " ");
        count += infi_permu_subseq(arr, idx + 1, target, ans);
    }
    return count;
}

int combi_without_repe_subseq(vector<int> &arr, int idx, int target, string ans)
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
        count += combi_without_repe_subseq(arr, idx + 1, target - arr[idx], ans + to_string(arr[idx]) + " ");
        count += combi_without_repe_subseq(arr, idx + 1, target, ans);
    }
    return count;
}

int permu_without_repe_subseq(vector<int> &arr, vector<bool> &isDone, int idx, int target, string ans)
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
    if (target - arr[idx] >= 0 && isDone[idx] == false)
    {
        isDone[idx] = true;
        count += permu_without_repe_subseq(arr, isDone, 0, target - arr[idx], ans + to_string(arr[idx]) + " ");
        isDone[idx] = false;
    }
    count += permu_without_repe_subseq(arr, isDone, idx + 1, target, ans);
    return count;
}
void solve()
{
    vector<int> arr = {2, 3, 5, 7};
    vector<bool> isDone(arr.size(), 0);
    cout << infi_permu(arr, 0, 10, "");
    cout << endl;
    cout << infi_combi(arr, 0, 10, "");
    cout << endl;
    cout << combi_without_repe(arr, 0, 10, "");
    cout << endl;
    cout << permu_without_repe(arr, isDone, 10, "");
    cout << endl;
    cout << infi_combi_subseq(arr, 0, 10, "");
    cout << endl;
    cout << infi_permu_subseq(arr, 0, 10, "");
    cout << endl;
    cout << combi_without_repe_subseq(arr, 0, 10, "");
    cout << endl;
    cout << permu_without_repe_subseq(arr, isDone, 0, 10, "");
    cout << endl;
}
int main(int args, char **argv)
{
    solve();
    return 0;
}