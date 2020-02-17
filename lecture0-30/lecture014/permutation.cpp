#include <iostream>
#include <vector>
#include <string>
using namespace std;
int permutation(string str, string ans)
{
    if (str.length() == 0)
    {
        cout << ans << " " << endl;
        return 1;
    }
    int count = 0;
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        string one = str.substr(0, i);
        string two = str.substr(i + 1);

        count += permutation(one + two, ans + ch);
    }
    return count;
}
void solve()
{
    // cout << permutation("abc", "") << " ";
    cout << permutation("aab", "") << " ";
}
int main(int args, char **argv)
{
    solve();
}