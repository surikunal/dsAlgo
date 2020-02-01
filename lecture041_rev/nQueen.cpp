#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool isQueenSafeToPlace(vector<vector<bool>> &board, int x, int y)
{
    vector<vector<int>> dir = {{0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};
    for (int i = 0; i < dir.size(); i++)
    {
        for (int rad = 1; rad < max(board.size(), board[0].size()); rad++)
        {
            int nx = x + rad * dir[i][0];
            int ny = y + rad * dir[i][1];
            if (nx < 0 || ny < 0 || nx >= board.size() || ny >= board[0].size())
                break;
            if (board[nx][ny])
                return false;
        }
    }
    return true;
}

int calls = 0;
int nQueen_Combi(vector<vector<bool>> &board, int lqpl, int tnq, string ans)
{
    if (tnq == 0)
    {
        cout << ans << endl;
        return 1;
    }

    int count = 0;
    calls++;
    for (int i = lqpl; i < board.size() * board[0].size(); i++)
    {
        int r = i / board[0].size();
        int c = i % board[0].size();
        if (isQueenSafeToPlace(board, r, c))
        {
            board[r][c] = true;
            count += nQueen_Combi(board, i + 1, tnq - 1, ans + "(" + to_string(r) + ", " + to_string(c) + ")");
            board[r][c] = false;
        }
    }
    return count;
}
//================================================================================
bool isQueenSafeToPlace1(vector<vector<bool>> &board, int x, int y)
{
    vector<vector<int>> dir = {{-1,0},{1,0},{0,1},{0,-1},{1,1},{-1,-1},{-1,1},{1,-1}};
    for (int i = 0; i < dir.size(); i++)
    {
        for(int rad = 1; rad < max(board.size(), board[0].size()); rad++)
        {
            int nx = x + rad * dir[i][0];
            int ny = y + rad * dir[i][1];
            if (nx < 0 || ny < 0 || nx >= board.size() || ny >= board[0].size())
            {
                break;
            }
            if (board[nx][ny])
            {
                return false;
            }
        }
    } 
    return true;
}
int nQueen_Permu(vector<vector<bool>> &board, int qpsf, int tnq, string ans)
{
    if (tnq == qpsf)
    {
        cout << ans << endl;
        return 1;
    }
    int count = 0;
    for (int i = 0; i < board.size() * board[0].size(); i++)
    {
        int r = i / board[0].size();
        int c = i % board[0].size();

        if (!board[r][c] && isQueenSafeToPlace1(board, r, c))
        {
            board[r][c] = true;
            count += nQueen_Permu(board, qpsf + 1, tnq, ans + "(" + to_string(r) + ", " + to_string(c) + ")");
            board[r][c] = false;
        }
    }
    return count;
}

void solve()
{
    vector<vector<bool>> board(4, vector<bool>(4, false));
    cout << nQueen_Combi(board, 0, 4, "");
    cout << endl;
    cout << calls << endl;
    // cout << nQueen_Permu(board, 0, 4, "");
}
int main(int args, char **argv)
{
    solve();
    return 0;
}