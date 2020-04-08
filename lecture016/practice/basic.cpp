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
int floodfill4(vector<vector<bool>> &isdone, int sr, int sc, int er, int ec, string ans)
{
    if (sr == er && sc == ec)
    {
        cout << ans << endl;
        return 1;
    }
    int count = 0;
    isdone[sr][sc] = true;

    if (isValidLocation(isdone, sr + 1, sc))
    {
        count += floodfill4(isdone, sr + 1, sc, er, ec, ans + "D");
    }
    if (isValidLocation(isdone, sr, sc + 1))
    {
        count += floodfill4(isdone, sr, sc + 1, er, ec, ans + "R");
    }
    if (isValidLocation(isdone, sr - 1, sc))
    {
        count += floodfill4(isdone, sr - 1, sc, er, ec, ans + "U");
    }
    if (isValidLocation(isdone, sr, sc - 1))
    {
        count += floodfill4(isdone, sr, sc - 1, er, ec, ans + "L");
    }
    isdone[sr][sc] = false;
    return count;
}
int floodfill4_better(vector<vector<bool>> &isdone, int sr, int sc, int er, int ec, string ans)
{
    if (sr == er && sc == ec)
    {
        cout << ans << endl;
        return 1;
    }
    int count = 0;
    isdone[sr][sc] = true;
    string dir[4] = {"D", "R", "U", "L"};
    int dir_[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    for (int d = 0; d < 4; d++)
    {
        int x = sr + dir_[d][0];
        int y = sc + dir_[d][1];

        if (isValidLocation(isdone, x, y))
        {
            count += floodfill4_better(isdone, x, y, er, ec, ans + dir[d]);
        }
    }
    isdone[sr][sc] = false;
    return count;
}

int floodfill8_better(vector<vector<bool>> &isdone, int sr, int sc, int er, int ec, string ans)
{
    if (sr == er && sc == ec)
    {
        cout << ans << endl;
        return 1;
    }
    int count = 0;
    isdone[sr][sc] = true;
    int dir[8][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
    string dir_[8] = {"R", "D", "U", "L", "d4", "d3", "d2", "d1"};
    for (int d = 0; d < 8; d++)
    {
        int x = sr + dir[d][0];
        int y = sc + dir[d][1];

        if (isValidLocation(isdone, x, y))
        {
            count += floodfill8_better(isdone, x, y, er, ec, ans + dir_[d]);
        }
    }
    isdone[sr][sc] = false;
    return count;
}

int targetSum(vector<int> &isdone, int vidx, int target, string ans)
{
    if (target <= 0 || vidx == isdone.size())
    {
        if (target == 0)
        {
            cout << ans << endl;
            return 1;
        }
        return 0;
    }
    int count = 0;
    count += targetSum(isdone, vidx + 1, target, ans);
    count += targetSum(isdone, vidx + 1, target - isdone[vidx], ans + to_string(isdone[vidx]) + " ");
    return count;
}
int equiSet(vector<int> &arr, int vidx, int set1, int set2, string ans1, string ans2)
{
    if (vidx == arr.size() || ((set1 == set2) && (set1 != 0)))
    {
        if (set1 == set2)
        {
            cout << ans1 << "= " << ans2 << endl;
            return 1;
        }
        return 0;
    }

    int count = 0;
    count += equiSet(arr, vidx + 1, set1, set2, ans1, ans2);
    count += equiSet(arr, vidx + 1, set1 + arr[vidx], set2, ans1 + to_string(arr[vidx]) + " ", ans2);
    count += equiSet(arr, vidx + 1, set1, set2 + arr[vidx], ans1, ans2 + to_string(arr[vidx]) + " ");
    return count;
}

void solve()
{
    // vector<vector<bool>> isdone(3, vector<bool>(4, false));
    // cout << floodfill4(isdone ,0, 0, 2, 3, "") << endl;
    // cout << floodfill4_better(isdone, 0, 0, 2, 3, "") << endl;
    // cout << floodfill8_better(isdone, 0, 0, 2, 3, "") << endl;

    // vector<vector<bool>> isdone={
    //     {0,0,1,0,0},
    //     {0,0,0,1,0},
    //     {0,0,0,0,1},
    //     {1,0,1,0,0},
    // };
    // cout << floodfill8_better(isdone, 0, 0, 2, 2, "") <<endl;

    vector<int> arr = {10, 20, 30, 40, 50, 60};
    // cout<<targetSum(isdone, 0, 60, "");
    // cout << "with duplicacy " << equiSet(arr, 0, 0, 0, "", "");
    cout << "without duplicacy " << equiSet(arr, 1, 10, 0, "10 ", "");
}
int main(int args, char **argv)
{
    solve();
    return 0;
}