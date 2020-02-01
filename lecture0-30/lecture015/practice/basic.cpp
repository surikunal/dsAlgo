#include <iostream>

#include <string>

using namespace std;

int mazePath1(int sr, int sc, int er, int ec, string ans)
{
    if (sr == er && sc == ec)
    {
        cout << ans << " ";
        return 1;
    }
    int count = 0;
    if (sr + 1 <= er)
    {
        count += mazePath1(sr + 1, sc, er, ec, ans + "V");
    }
    if (sc + 1 <= ec)
    {
        count += mazePath1(sr, sc + 1, er, ec, ans + "H");
    }
    if (sr + 1 <= er && sc + 1 <= ec)
    {
        count += mazePath1(sr + 1, sc + 1, er, ec, ans + "D");
    }
    return count;
}

int mazePath_multi(int sr, int sc, int er, int ec, string ans)
{
    if (sr == er && sc == ec)
    {
        cout << ans << " ";
        return 1;
    }
    int count = 0;
    for (int jump = 1; jump + sr <= er; jump++)
    {
        count += mazePath_multi(sr + jump, sc, er, ec, ans + "V" + to_string(jump));
    }
    for (int jump = 1; jump + sc <= ec; jump++)
    {
        count += mazePath_multi(sr, sc + jump, er, ec, ans + "H" + to_string(jump));
    }
    for (int jump = 1; jump + sr <= er && jump + sc <= ec; jump++)
    {
        count += mazePath_multi(sr + jump, sc + jump, er, ec, ans + "D" + to_string(jump));
    }
    return count;
}

int boardPath(int si, int ei, string ans)
{
    if (si == ei)
    {
        cout << ans << endl;
        return 1;
    }
    int count = 0;
    for (int jump = 1; jump + si <= ei && jump <= 6; jump++)
    {
        count += boardPath(si + jump, ei, ans + to_string(jump));
    }
    return count;
}

int function_call = 0;
int countFun(int sr, int sc, int er, int ec, string ans)
{
    function_call++;
    if (sr == er && sc == ec)
    {
        cout << ans << " ";
        return 1;
    }
    int count = 0;
    if (sr + 1 <= er)
    {
        count += countFun(sr + 1, sc, er, ec, ans + "V");
    }
    if (sc + 1 <= ec)
    {
        count += countFun(sr, sc + 1, er, ec, ans + "H");
    }
    if (sr + 1 <= er && sc + 1 <= ec)
    {
        count += countFun(sr + 1, sc + 1, er, ec, ans + "D");
    }
    return count;
}


int countHeight(int sr, int sc, int er, int ec, string ans)
{
    if (sr == er && sc == ec)
    {
        cout << ans << " ";
        return 1;
    }
    int count = 0;
    if (sr + 1 <= er)
    {
        count += countHeight(sr + 1, sc, er, ec, ans + "V") + 1;
    }
    if (sc + 1 <= ec)
    {
        count += countHeight(sr, sc + 1, er, ec, ans + "H") + 1;
    }
    if (sr + 1 <= er && sc + 1 <= ec)
    {
        count += countHeight(sr + 1, sc + 1, er, ec, ans + "D") + 1;
    }
    return count;
}

int maxHeight(int sr, int sc, int er, int ec, string ans)

{
    if (sr == er && sc == ec)
    {
        cout << ans << " ";
        return 1;
    }
    int count = 0;
    int Hheight = 0;
    int Vheight = 0;
    int Dheight = 0;

    if (sr + 1 <= er)
    {
        Vheight += maxHeight(sr + 1, sc, er, ec, ans + "V") + 1;
    }
    if (sc + 1 <= ec)
    {
        Hheight += maxHeight(sr, sc + 1, er, ec, ans + "H") + 1;
    }
    if (sr + 1 <= er && sc + 1 <= ec)
    {
        Dheight += maxHeight(sr + 1, sc + 1, er, ec, ans + "D") + 1;
    }

    if (Hheight > Vheight && Hheight > Dheight)
    {
        return Hheight;
    }

    else if (Vheight > Hheight && Vheight > Dheight)
    {
        return Vheight;
    }

    else if (Dheight > Vheight && Dheight > Hheight)
    {
        return Dheight;
    }
}

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
    // cout<<mazePath1(0, 0, 2, 2, "")<<" ";

    // cout << mazePath_multi(0, 0, 2, 2, "") << " ";

    // cout<<boardPath(0,10,"");

    // cout << countFun(0, 0, 2, 2, "") << " ";
    // cout << function_call;

    // cout << countHeight(0, 0, 2, 2, "") << endl;

    // cout << maxHeight(0, 0, 2, 2, "") << endl;

    cout << dialPad("235", "");
}
int main(int args, char **argv)
{
    solve();
    return 0;
}