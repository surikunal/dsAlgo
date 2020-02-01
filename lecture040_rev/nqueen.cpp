#include <iostream>
#include <vector>
#include <string>
using namespace std;
int subset(vector<int> &arr, int idx, string ans)
{
    cout << ans << endl;
    if (idx == arr.size())
    {
        return 1;
    }

    int count = 0;
    for (int i = idx; i < arr.size(); i++)
    {
        count += subset(arr, i + 1, ans + to_string(arr[i]) + " ");
    }
    return count;
}

int nqueen_combi(int box, int idx, int qpsf, int tnq, string ans)
{
    if (qpsf == tnq)
    {
        cout << ans << endl;
        return 1;
    }

    int count = 0;
    for (int i = idx; i < box; i++)
    {
        count += nqueen_combi(box, i + 1, qpsf + 1, tnq, ans + "B" + to_string(i) + "Q" + to_string(qpsf) + " ");
    }
    return count;
}

int nqueen_permu(vector<bool> &box, int qpsf, int tnq, string ans)
{
    if (qpsf == tnq)
    {
        cout << ans << endl;
        return 1;
    }

    int count = 0;
    for (int i = 0; i < box.size(); i++)
    {
        if (!box[i])
        {
            box[i] = true;
            count += nqueen_permu(box, qpsf + 1, tnq, ans + "B" + to_string(i) + "Q" + to_string(qpsf) + " ");
            box[i] = false;
        }
    }
    return count;
}

int nqueen_combi_subseq(int box, int lqpl, int qpsf, int tnq, string ans)
{
    if (lqpl == box || qpsf >= tnq)
    {
        if (qpsf == tnq)
        {
            cout << ans << endl;
            return 1;
        }
        return 0;
    }

    int count = 0;
    count += nqueen_combi_subseq(box, lqpl + 1, qpsf + 1, tnq, ans + "B" + to_string(lqpl) + "Q" + to_string(qpsf) + " ");
    count += nqueen_combi_subseq(box, lqpl + 1, qpsf, tnq, ans);
    return count;
}

int nqueen_permu_subseq(vector<bool> &box, int lqpl, int qpsf, int tnq, string ans)
{
    if (lqpl == box.size() || qpsf >= tnq)
    {
        if (qpsf == tnq)
        {
            cout << ans << endl;
            return 1;
        }
        return 0;
    }

    int count = 0;
    if (!box[lqpl])
    {
        box[lqpl] = true;
        count += nqueen_permu_subseq(box, 0, qpsf + 1, tnq, ans + "B" + to_string(lqpl) + "Q" + to_string(qpsf) + " ");
        box[lqpl] = false;
    }
    count += nqueen_permu_subseq(box, lqpl + 1, qpsf, tnq, ans);
    return count;
}
void solve()
{
    vector<int> arr = {1, 2, 3}; //OR  vector<int> arr{1, 2, 3};
    // these are 3 queen 
    vector<bool> box(5, false);
    // and 5 are the num of boxes
    subset(arr, 0, "");
    cout << nqueen_combi(5, 0, 0, 3, "");
    cout << nqueen_permu(box, 0, 3, "");
    cout << nqueen_combi_subseq(5, 0, 0, 3, "");
    cout << endl;
    cout << nqueen_permu_subseq(box, 0, 0, 3, "");
}
int main(int args, char **argv)
{
    solve();
    return 0;
}