#include<iostream>
#include<vector>
#include<string>

#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
#define vvb vector<vb>

using namespace std;

void display(vvi &board)
{
    for (vi ar : board)
    {
        for (int i : ar)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    cout << endl;
}

vi row(9, 0);
vi col(9, 0);
vvi mat(3, vi(3, 0));
int sudoku(vvi &board, vi &calls, int idx)
{
    if (idx == calls.size())
    {
        display(board);
        return 1;
    }
    int x = calls[idx] / 9;
    int y = calls[idx] % 9;
    int count = 0;
    for (int num = 1; num < 9; num++)
    {
        int mask = 1 << num;
        if (!(row[x] & mask) && !(col[y] & mask) && !(mat[x / 3][y / 3] & mask))
        {
            board[x][y] = num;
            row[x] ^= mask;
            col[y] ^= mask;
            mat[x / 3][y / 3] ^= mask;

            count += sudoku(board, calls, idx + 1);

            board[x][y] = 0;
            row[x] ^= mask;
            col[y] ^= mask;
            mat[x / 3][y / 3] ^= mask;
        }
    }
    return count;
}

void solve()
{
    vvi board = {{0, 0, 6, 0, 0, 8, 0, 0, 0},
                 {5, 2, 0, 0, 0, 0, 0, 0, 0},
                 {0, 8, 7, 0, 0, 0, 0, 3, 1},
                 {0, 0, 3, 0, 1, 0, 0, 8, 0},
                 {9, 0, 0, 8, 6, 3, 0, 0, 5},
                 {0, 5, 0, 0, 9, 0, 6, 0, 0},
                 {1, 3, 0, 0, 0, 0, 2, 5, 0},
                 {0, 0, 0, 0, 0, 0, 0, 7, 4},
                 {0, 0, 5, 2, 0, 6, 3, 0, 0}};

    vi calls;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] == 0)
            {
                calls.push_back(i * 9 + j);
            }
            else
            {
                int mask = 1 << board[i][j];
                row[i] |= mask;
                col[j] |= mask;
                mat[i / 3][j / 3] |= mask;
            }
        }
    }
    cout << sudoku(board, calls, 0) << endl;
}

int main(int args, char **argv)
{
    solve();
    return 0;
}