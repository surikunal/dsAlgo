#include <iostream>
#include <vector>
#include <string>
using namespace std;

string words[] = {"!@$", "abc", "def", "ghi", "jkl", "mno", "pqrs", "uvw", "xyz", "*", "#", "%^&"};
int keypad_01(string str, string ans)
{
    if (str.size() == 0)
    {
        cout << ans << endl;
        return 1;
    }
    int count = 0;
    int idx = str[0] - '0';
    string roq = str.substr(1);
    string word = words[idx];

    for (int i = 0; i < word.size(); i++)
    {
        count += keypad_01(roq, ans + word[i]);
    }

    if (str.size() > 1)
    {
        idx = idx * 10 + (str[1] - '0');
        if (idx == 10 || idx == 11)
        {
            word = words[idx];
            for (int i = 0; i < word.size(); i++)
            {
                count += keypad_01(str.substr(2), ans + word[i]);
            }
        }
    }
    return count;
}

vector<string> keypad_02(string str)
{
    if (str.size() == 0)
    {
        vector<string>* base = new vector<>();
        vector->push_back("");
        return base;
    }

    int idx = str[0] - '0';
    string roq = str.substr(1);
    string word = words[idx];

    vector<string> recAns = keypad_02(roq);

    vector<string> myAns = new vector<>();
    for (int i = 0; i < word.size(); i++)
    {
        for (string s : recAns)
        {
            myAns.push_back(word[i] + s);
        }
    }
    
    if (str.size() > 1)
    {
        idx = idx * 10 + (str[1] -  '0');
        if (idx == 10 || idx == 11)
        {
            word = words[idx];
            recAns = keypad_02(str.substr(2));
            for (int i = 0; i < word.size(); i++)
            {
                for (string s : recAns)
                {
                    myAns.push_back(str[i] + s);
                }
            }
        }
    }
    return myAns;
}

int main(int args, char **argv)
{
    // keypad_01("234", "");
    // cout << keypad_01("11024", "");
    keypad_02("234");
    // keypad_02("11024");
    return 0;
}