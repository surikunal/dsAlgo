#include <iostream>
#include <string>
using namespace std;

int boardPath(int si, int ei, string ans)
{
    if (si == ei)
    {
        cout << ans << endl;
        return 1;
    }
    int count = 0;
    for (int dice = 1; dice + si <= ei && dice <= 6; dice++)
    {
        count += boardPath(si + dice, ei, ans + to_string(dice));
    }
    return count;
}

int main(int args, char **argv)
{
    cout << boardPath(0, 10, "") << endl;
}