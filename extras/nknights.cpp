#include<iostream>
#include<vector>
using namespace std;

bool nknights(vector<vector<int>> &board, int sr, int sc, int moves, vector<vector<int>> &dir)
{
    if (moves == board.size() * board[0].size())
    {
        for (vector<int> &ar : board)
        {
            for (int ele : ar)
            {
                cout << ele << " ";
            }
            cout << endl;
        }
        return true;
    }

    bool res = false;
    
    for (int d = 0; d < board.size(); d++)
    {
        int x = sr + 1 * dir[d][0];
        int y = sc + 1 * dir[d][1];

        if (x >= 0 && y >= 0 && x < board.size() && y < board[0].size() && board[x][y] == -1)
        {
            board[x][y] = moves;
            res = res || nknights(board, x, y, moves + 1, dir);
            board[x][y] = -1;
        }
    }
    return res;
}

void knight(){
    vector<vector<int>> board(8, vector<int>(8, -1));
    vector<vector<int>> dir = {{2,1}, {1,2}, {-1,2},{-2,1}, {-2,-1}, {-1,-2},{1,-2},{2,-1}};
    board[0][0]=0;
    cout << (boolalpha) << nknights(board, 0, 0, 1, dir);
}

int main(int args, char **argv)
{
    knight();
    return 0;
}