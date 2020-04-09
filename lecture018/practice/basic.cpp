#include<iostream>
#include<vector>
using namespace std;
int nQueenFund(vector<int> &arr, int idx, int q, int tnq, string ans)
{
    if(tnq == q + 1)
    {
        cout<< ans <<" ";
        return 1;
    }
    int count = 0;
    count += nQueenFund(arr, idx+1, q+1, tnq, ans + to_string())
}
int solve()
{
    nQueenFund();
    return 0;
}
void main(int args, char** argv)
{
    solve();
}
