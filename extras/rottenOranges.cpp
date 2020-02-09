#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isSafeForOranges(int r, int c, vector<vector<int>> &oranges)
{
    if (r < 0 || c < 0 || r >= oranges.size() || c >= oranges[0].size() || oranges[r][c] == 2 || oranges[r][c] == 0)
        return false;
    return true;
}

// =============================Recursion================================
void rottenOranges(vector<vector<int>> &oranges, int sr, int sc, vector<vector<int>> &dir, string ans)
{
    // bool flag = false;
    cout << ans << endl;
    oranges[sr][sc] = 1;

    // while (size != 0)
    // {
    for (int d = 0; d < oranges.size(); d++)
    {
        int nsr = sr + rad * dir[d][0];
        int nsc = sc + rad * dir[d][1];
        if (isSafeForOranges(nsr, nsc, oranges))
        {
            oranges[nsr][nsc] = 2;
            rottenOranges(oranges, nsr, nsc, dir, ans + "(" + to_string(nsr) + ", " + to_string(nsc) + ") ");
        }
    }
    // }
    oranges[sr][sc] = 0;
}
// ============================queue approch=============================

// void rottenOranges01(vector<vector<int>> &arr)
// {

// }

void floodFillSet()
{
    vector<vector<int>> oranges = {
        {2, 1, 0, 2, 1},
        {1, 0, 1, 2, 1},
        {1, 0, 0, 2, 1}};

    vector<vector<int>> dir = {{1, 0},{0, 1},{-1, 0},{0, -1}};
    int count = 0;
    for (int i = 0; i < oranges.size(); i++)
    {
        for (int j = 0; j < oranges[0].size(); j++)
        {
            if (oranges[i][j] == 2)
            {
                count++;
                rottenOranges(oranges, i, j, dir, "(" + to_string(i) + ", " + to_string(j) + ") ");
            }
        }
    }

    cout << count << endl;

    //=========================================================================
    //===============queue approch=============================================

    // cout << rottenOranges01(arr);
}
int main(int args, char **argv)
{
    floodFillSet();
    return 0;
}