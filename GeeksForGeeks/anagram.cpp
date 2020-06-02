#include<bits/stdc++.h>
using namespace std;

bool Anagram_01(string &str1, string &str2)
{
    int n1 = str1.length();
    int n2 = str2.length();

    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());

    for (int i = 0; i < max(n1, n2); i++)
    {
        if (str1[i] != str2[i])
        {
            return false;
        }
    }
    return true;
}

bool Anagram_02(string &str1, string &str2)
{
    int count[256] = {0};
    int i;
    for (i = 0; str1[i] && str2[i]; i++)
    {
        count[str1[i]]++;
        count[str2[i]]--;
    }

    if (str1[i] || str2[i])
    {
        return false;
    }

    for (i = 0; i < 256; i++)
    {
        if (count[i])
        {
            return false;
        }
    }

    return true;
}

bool Anagram_03(string &str1, string &str2)
{
    int count1[256] = {0};
    int count2[256] = {0};
    int i;
    for (i = 0; str1[i] && str2[i]; i++)
    {
        count1[str1[i]]++;
        count2[str2[i]]++;
    }

    if (str1[i] || str2[i])
    {
        return false;
    }

    for (i = 0; i < 256; i++)
    {
        if (count1[i] != count2[i])
        {
            return false;
        }
    }

    return true;
}
void solve()
{
    string str1 = "triangle", str2 = "integral";
    // string str1 = "aaaa", str2 = "a";
    // cin >> str1;
    // cin >> str2;
    cout << (boolalpha) << Anagram_01(str1, str2) << endl;
    cout << (boolalpha) << Anagram_02(str1, str2) << endl;
    cout << (boolalpha) << Anagram_03(str1, str2) << endl;
}

int main(int args, char **argv) 
{
    solve();
    return 0;
}