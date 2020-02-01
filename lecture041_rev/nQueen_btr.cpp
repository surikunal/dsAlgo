#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool isSafeToPlaceQueen(vector<vector<bool>> &board, int x, int y)
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
int calls = 0;
int nQueen_in_less_calls(vector<vector<bool>> &board, int row, int tnq, string ans)
{
    if (row == board.size() || tnq == 0)
    {
        if (tnq == 0)
        {
            cout << ans << endl;
            return 1;
        }
        return 0;
    }
    int count = 0;
    calls++;
    for (int col = 0; col < board[0].size(); col++)
    {
        if (isSafeToPlaceQueen(board, row, col))
        {
            board[row][col] = true;
            count += nQueen_in_less_calls(board, row + 1, tnq - 1, ans + "(" + to_string(row) + ", " + to_string(col) + ") ");
            board[row][col] = false;
        }
    }
    return count;
}
void solve()
{
    vector<vector<bool>> board(4, vector<bool>(4, false));
    nQueen_in_less_calls(board, 0, 4, "");
    cout << calls << endl;
}
int main(int args, char **argv)
{
    solve();
    return 0;
}