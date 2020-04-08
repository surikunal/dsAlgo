#include <iostream>
#include <vector>
#include <string>
using namespace std;
bool isValidLocation(vector<vector<bool>> &isdone, int x, int y)
{
    if (x < 0 || y < 0 || x >= isdone.size() || y >= isdone[0].size() || isdone[x][y])
    {
        return false;
    }
    return true;
}
int floodfill_dir(vector<vector<bool>> &isdone, int sr, int sc, int er, int ec, string ans)
{
    if (sr == er && sc == ec)
    {
        cout << ans << endl;
        return 1;
    }

    int count = 0;
    isdone[sr][sc] = true;

    string dir_[4] = {"R", "L", "U", "D"};
    int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    for (int d = 0; d < 4; d++)
    {
        int x = sr + dir[d][0];
        int y = sc + dir[d][1];

        if (isValidLocation(isdone, x, y))
        {
            count += floodfill_dir(isdone, x, y, er, ec, ans + dir_[d]);
        }
    }
    isdone[sr][sc] = false;
    return count;
}
void floodfillque()
{
    vector<vector<bool>> isdone(3, vector<bool>(4, false));
    cout << floodfill_dir(isdone, 0, 0, 2, 3, "") << endl;
}
void solve()
{
    floodfillque();
}
int main(int args, char **argv)
{
    solve();
    return 0;
}