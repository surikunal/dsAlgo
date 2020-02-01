#include <iostream>
#include <vector>
#include <string>
using namespace std;
bool isValidLocation(vector<vector<bool>> &vis, int x, int y)
{
    if (x < 0 || y < 0 || x >= vis.size() || y >= vis[0].size() || vis[x][y])
    {
        return false;
    }
    return true;
}

int floodfill_voidType(vector<vector<bool>> &vis, int sr, int sc, int er, int ec, string ans)
{
    if (sr == er && sc == ec)
    {
        cout << ans << endl;
        return 1;
    }
    int count = 0;
    vis[sr][sc] = true;

    string dir_[4] = {"R", "L", "U", "D"};
    int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    for (int i = 0; i < 4; i++)
    {
        int x = sr + dir[i][0];
        int y = sc + dir[i][1];

        if (isValidLocation(vis, x, y))
        {
            count += floodfill_voidType(vis, x, y, er, ec, ans + dir_[i]);
        }
    }

    vis[sr][sc] = false;
    return count;
}

//---------------------------void type--------------------------------------

bool isLoactionSafe(int x, int y, vector<vector<int>> &board)
{
    if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size() || board[x][y] == 1)
        return false;
    return true;
}

int floodFill_voidType(int sr, int sc, int er, int ec, int len, vector<vector<int>> &board, vector<vector<int>> &dir, vector<string> &path, string ans)
{
    if (sr == er && sc == ec)
    {
        cout << ans << endl;
        return true;
    }
    int count = 0;
    board[sr][sc] = 1;
    for (int d = 0; d < dir.size(); d++)
    {
        for (int rad = 1; rad <= len; rad++)
        {
            int x = sr + rad * dir[d][0];
            int y = sc + rad * dir[d][1];

            if (isLoactionSafe(x, y, board))
            {
                count += floodFill_voidType(x, y, er, ec, len, board,  dir, path, ans + path[d] + to_string(len) + " ");
            }
        }
    }
    board[sr][sc] = 0;
    return count;
}

//----------------------------return type-------------------------------------------

vector<string> floodFill_returnType(int sr, int sc, int er, int ec, int len, vector<vector<int>> &board, vector<vector<int>> &dir, vector<string> &path)
{
    if (sr == er && sc == ec)
    {
        vector<string> base;
        base.push_back("");
        return base;
    }

    vector<string> myAns;
    board[sr][sc] = 1;
    
    for (int d = 0; d < dir.size(); d++)
    {
        for (int rad = 1; rad <= len; rad++)
        {
            int x = sr + rad * dir[d][0];
            int y = sc + rad * dir[d][1];

            if (isLoactionSafe(x, y, board))
            {
                vector<string> recAns = floodFill_returnType(x, y, er, ec, len, board, dir, path);

                for (string s : recAns)
                {
                    myAns.push_back(path[d] + s);
                }
            }
        }
    }

    board[sr][sc] = 0;
    return myAns;
}

int main(int args, char **argv)
{
    // vector<vector<bool>> vis(3, vector<bool>(4, false));
    // cout << floodfill_voidType(vis, 0, 0, 2, 3, "") << endl;

    vector<vector<int>> board(3, vector<int>(3, 0));
    vector<vector<int>> dir = {{0, 1},{1, 0},{1, 1}};
    vector<string> path = {"V", "H", "D"};
    // cout << floodFill_voidType(0, 0, 2, 2, 1, board, dir, path, "") << endl;

    vector<string> ans = floodFill_returnType(0, 0, 2, 2, 1, board, dir, path);
    for (string s : ans)
    {
        cout << s << endl;
    }
    return 0;
}