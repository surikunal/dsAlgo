#include <iostream>
#include <string>
using namespace std;

int mazePath_multi(int sr, int sc, int er, int ec, string ans)
{
    if (sr == er && sc == ec)
    {
        cout << ans << endl;
        return 1;
    }
    int count = 0;
    for (int jump = 1; jump + sc <= ec; jump++)
    {
        count += mazePath_multi(sr, sc + jump, er, ec, ans + "H" + to_string(jump));
    }
    for (int jump = 1; jump + sr <= er; jump++)
    {
        count += mazePath_multi(sr + jump, sc, er, ec, ans + "V" + to_string(jump));
    }
    for (int jump = 1; jump + sr <= er && jump + sc <= ec; jump++)
    {
        count += mazePath_multi(sr + jump, sc + jump, er, ec, ans + "D" + to_string(jump));
    }
    return count;
}

int main(int args, char **argv)
{
    cout << mazePath_multi(0, 0, 2, 2, "") << endl;
}