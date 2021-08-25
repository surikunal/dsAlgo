#include <iostream>
#include <string>
using namespace std;

string codes[] = {"+", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wx", "yz", "*", "#"};

int dialPad(string ques, string ans)
{
    if (ques.length() == 0)
    {
        cout << ans << " ";
        return 1;
    }
    int count = 0;
    char ch = ques[0];
    string roq = ques.substr(1);
    string code = codes[ch - '0'];

    for (int i = 0; i < code.length(); i++)
    {
        count += dialPad(roq, ans + code[i]);
    }
    return count;
}
void solve()
{
    cout << endl << dialPad("235", "");
}
int main(int args, char **argv)
{
    solve();
    return 0;
}
