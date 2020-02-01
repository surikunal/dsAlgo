#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool isValidLocation(vector<vector<bool>> &isdone, int x, int y)
{
    if (x < 0 || y < 0 || x >= isdone.size() || y >= isdone[0].size() || isdone[x][y])
    {
        return false;
    }
    return true;
}
int floodfill(vector<vector<bool>> &isdone, int sr, int sc, int er, int ec, string ans)
{
    if (sr == er && sc == ec)
    {
        cout << ans << endl;
        return 0;
    }
    int count = 0;
    int max_ = 0;
    isdone[sr][sc] = true;

    if (isValidLocation(isdone, sr + 1, sc))
    {
        max_ = max(max_, floodfill(isdone, sr + 1, sc, er, ec, ans + "D"));
    }
    if (isValidLocation(isdone, sr, sc + 1))
    {
        max_ = max(max_, floodfill(isdone, sr, sc + 1, er, ec, ans + "R"));
    }
    if (isValidLocation(isdone, sr - 1, sc))
    {
        max_ = max(max_, floodfill(isdone, sr - 1, sc, er, ec, ans + "U"));
    }
    if (isValidLocation(isdone, sr, sc - 1))
    {
        max_ = max(max_, floodfill(isdone, sr, sc - 1, er, ec, ans + "L"));
    }
    isdone[sr][sc] = false;
    return max_ + 1;
}
void floodfillque()
{
    vector<vector<bool>> isdone(3, vector<bool>(4, false));
    cout << floodfill(isdone, 0, 0, 2, 3, "");
}
void solve()
{
    floodfillque();
}

int main(int args, char **argv)
{
    solve();
}