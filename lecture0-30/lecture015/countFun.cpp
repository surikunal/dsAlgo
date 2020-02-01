#include <iostream>
#include <string>

using namespace std;
int functionCall = 0;
int mazePath(int sr, int sc, int er, int ec, string ans)
{
    functionCall++;
    if (sr == er && sc == ec)
    {
        cout << ans << "\n";

        return 1;
    }
    int count = 0;
    if (sr + 1 <= er)
    {
        count += mazePath(sr + 1, sc, er, ec, ans + "V");
    }
    if (sc + 1 <= ec)
    {
        count += mazePath(sr, sc + 1, er, ec, ans + "H");
    }
    return count;
}
int main(int args, char **argv)
{

    cout << mazePath(0, 0, 2, 2, "") << endl;
    cout << "num of times the fnction is called is " << functionCall;
}