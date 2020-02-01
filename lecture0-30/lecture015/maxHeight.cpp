#include <iostream>
#include <string>

using namespace std;
int mazePath(int sr, int sc, int er, int ec, string ans)
{
    if (sr == er && sc == ec)
    {
        cout << ans << " ";
        return 1;
    }
    int leftHeight = 0, rightHeight = 0;
    int count = 0;
    if (sr + 1 <= er)
    {
        leftHeight = mazePath(sr + 1, sc, er, ec, ans + "V") + 1;
    }
    if (sc + 1 <= ec)
    {
        rightHeight = mazePath(sr, sc + 1, er, ec, ans + "H") + 1;
    }
    return max(rightHeight, leftHeight);
}
int main(int args, char **argv)
{

    cout << mazePath(0, 0, 2, 2, "") << endl;
}