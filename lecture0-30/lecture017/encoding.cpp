#include <iostream>
#include <vector>
#include <string>
using namespace std;
int encoding(string ques, string ans)
{
    if (ques.size() == 0)
    {
        cout << ans << endl;
        return 1;
    }
    char ch = ques[0];
    int count = 0;

    if (ch == '0')
    {
        count += encoding(ques.substr(1), ans);
    }
    else
    {
        count += encoding(ques.substr(1), ans + (char)(ch - '1' + 'a'));

        if (ques.size() > 1)
        {
            char ch1 = ques[1];
            int num = ((ch - '0') * 10 + (ch1 - '0'));

            if (num <= 26)
            {
                count += encoding(ques.substr(2), ans + (char)('a' + num - 1));
            }
        }
    }
    return count;
}
void setQuestion()
{
    cout << encoding("1100024", "");
    // cout<<encoding("1124","");
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