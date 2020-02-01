#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<string> subSeq(string str)
{
    if (str.size() == 0)
    {
        vector<string> base;
        base.push_back(" ");
        return base;
    }

    char ch = str[0];
    string restStr = str.substr(1);

    vector<string> recAns = subSeq(restStr);
    vector<string> myAns;
    for (string s : recAns)
    {
        myAns.push_back(s);
        myAns.push_back(ch + s);
    }
    return myAns;
}
void solve()
{
    vector<string> ans = subSeq("1234");
    for (string s : ans)
        cout << s << " ";
}
int main(int args, char **argv)
{
    solve();
}