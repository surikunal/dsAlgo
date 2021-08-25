#include <iostream>
#include <vector>
#include <string>
using namespace std;

//======================================================
//================ USING BOOLEAN METHOD ===============

int uniquePermu1(string str, string ans)
{
    if (str.length() == 0)
    {
        cout << ans << " ";
        return 1;
    }

    int count = 0;
    bool arr[26] = {0};

    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        if (arr[ch - 'a'] == false)
        {
            string one = str.substr(0, i);
            string two = str.substr(i + 1);

            count += uniquePermu1(one + two, ans + ch);
            arr[ch - 'a'] = true;
        }
    }
    return count;
}

//======================================================
//================ USING BIT MASS METHOD ===============

int uniquePermu2(string str, string ans)
{
    if (str.length() == 0)
    {
        cout << ans << " ";
        return 1;
    }

    int count = 0;
    int isSet = 0;

    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        int mask = (1 << (ch - 'a'));

        if ((isSet & mask) == 0)
        {
            string one = str.substr(0, i);
            string two = str.substr(i + 1);

            count += uniquePermu2(one + two, ans + ch);
            isSet |= mask;
        }
    }
    return count;
}
void solve()
{
    cout << uniquePermu1("aab", "") << " ";
    // cout<<uniquePermu2("aab","")<<" ";
}
int main(int args, char **argv)
{
    solve();
}