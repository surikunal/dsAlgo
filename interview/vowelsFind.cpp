/* CODE BY KUNAL SURI FOR THE INTERNSHIP PURPOSE */

#include <iostream>
#include <vector>
using namespace std;

int count = 0;

void vowelFind(string s)
{
    for (int i = 0; i < s.size(); i++)
    {
        for (int len = 1; len <= s.size() - i; len++)
        {
            cout << s.substr(i, len) << " ";

            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
            count++;
        }
    }
}

int main(int args, char **argv)
{
    string str;
    cin >> str;
    vowelFind(str);
    cout << endl;
    cout << count;
    return 0;
}