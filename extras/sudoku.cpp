#include <iostream>
#include <vector>

#define vi vector<int>
#define vvi vector<vector<int>>

using namespace std;

bool isSafeToPlaceNum(vector<vector<int>> &box, int x, int y, int val)
{
    for (int i = 0; i < 9; i++)
    {
        if (box[i][y] == val)
        {
            return false;
        }
    }
    for (int j = 0; j < 9; j++)
    {
        if (box[x][j] == val)
        {
            return false;
        }
    }

    int nr = (x / 3) * 3;
    int nc = (y / 3) * 3;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (box[nr + i][nc + j] == val)
            {
                return false;
            }
        }
    }
    return true;
}
//--------------------BOOLEAN METHOD----------------------
int sudoku(vector<vector<int>> &box, int vidx)
{
    if (vidx == 81)
    {
        for (vector<int> ar : box)
        {
            for (int ele : ar)
            {
                cout << ele << " ";
            }
            cout << endl;
        }
        cout << endl;
        return 1;
    }

    int count = 0;
    int r = vidx / 9;
    int c = vidx % 9;

    if (box[r][c] == 0)
    {
        for (int val = 1; val <= 9; val++)
        {
            if (isSafeToPlaceNum(box, r, c, val))
            {
                box[r][c] = val;
                count += sudoku(box, vidx + 1);
                box[r][c] = 0;
            }
        }
    }
    else
    {
        count += sudoku(box, vidx + 1);
    }
    return count;
}

//---------------------BIT MASSKING-------------------------

void sudoku_populate(vector<vector<int>> &arr, vector<int> &row, vector<int> &col, vector<vector<int>> &mat)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (arr[i][j] != 0)
            {
                int mask = 1 << (arr[i][j]);
                row[i] |= mask;
                col[j] |= mask;
                mat[i / 3][j / 3] |= mask;
            }
        }
    }
}

int sudoku_bitMass(vector<vector<int>> &arr, int vidx, vector<int> &row, vector<int> &col, vector<vector<int>> &mat)
{
    if (vidx == 81)
    {
        for (vector<int> ar : arr)
        {
            for (int ele : ar)
            {
                cout << ele << " ";
            }
            cout << endl;
        }
        cout << endl;
        return 1;
    }

    int count = 0;
    int r = vidx / 9;
    int c = vidx % 9;

    if (arr[r][c] != 0)
    {
        count += sudoku_bitMass(arr, vidx + 1, row, col, mat);
    }
    else
    {
        for (int val = 1; val <= 9; val++)
        {
            int mask = 1 << (val);

            if (((row[r] & mask) == 0) && ((col[c] & mask) == 0) && ((mat[r / 3][c / 3] & mask) == 0))
            {
                arr[r][c] = val;
                row[r] |= mask;
                col[c] |= mask;
                mat[r / 3][c / 3] |= mask;

                count += sudoku_bitMass(arr, vidx + 1, row, col, mat);

                arr[r][c] = 0;
                row[r] ^= mask;
                col[c] ^= mask;
                mat[r / 3][c / 3] ^= mask;
            }
        }
    }
    return count;
}

//--------------------sudoku better----------------------------

vi rows(9, 0);
vi cols(9, 0);
vvi mats(3, vi(3, 0));

int sudoku_better(vvi &arr, int vidx, vi &calls)
{
    if (vidx == calls.size())
    {
        for (vi ar : arr)
        {
            for (int ele : ar)
            {
                cout << ele << " ";
            }
            cout << endl;
        }
        cout << endl;
        return 1;
    }

    int count = 0;
    int r = calls[vidx] / 9;
    int c = calls[vidx] % 9;

    for (int val = 1; val <= 9; val++)
    {
        int mask = (1 << (val));
        if (!(rows[r] & mask) && !(cols[c] & mask) && !(mats[r / 3][c / 3] & mask))
        {
            arr[r][c] = val;
            rows[r] ^= mask;
            cols[c] ^= mask;
            mats[r / 3][c / 3] ^= mask;

            count += sudoku_better(arr, vidx + 1, calls);

            arr[r][c] = 0;
            rows[r] ^= mask;
            cols[c] ^= mask;
            mats[r / 3][c / 3] ^= mask;
        }
    }
    return count;
}

int main(int args, char **argv)
{
    vector<vector<int>> arr = {
        {3, 0, 6, 5, 0, 8, 4, 0, 0},
        {5, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 8, 7, 0, 0, 0, 0, 3, 1},
        {0, 0, 3, 0, 1, 0, 0, 8, 0},
        {9, 0, 0, 8, 6, 3, 0, 0, 5},
        {0, 5, 0, 0, 9, 0, 6, 0, 0},
        {1, 3, 0, 0, 0, 0, 2, 5, 0},
        {0, 0, 0, 0, 0, 0, 0, 7, 4},
        {0, 0, 5, 2, 0, 6, 3, 0, 0},
    };
    //================================================
    // cout << sudoku(arr, 0);
    //================================================
    // vector<int> row(9, 0);
    // vector<int> col(9, 0);
    // vector<vector<int>> mat(3, vector<int>(3, 0));
    // sudoku_populate(arr, row, col, mat);
    // cout << sudoku_bitMass(arr, 0, row, col, mat);
    //================================================
    // vi calls;
    // for (int i = 0; i < 9; i++)
    // {
    //     for (int j = 0; j < 9; j++)
    //     {
    //         if (arr[i][j] != 0)
    //         {
    //             int mask = (1 << arr[i][j]);
    //             rows[i] |= mask;
    //             cols[j] |= mask;
    //             mats[i / 3][j / 3] |= mask;
    //         }
    //         else
    //         {
    //             calls.push_back(i * 9 + j);
    //         }
    //     }
    // }
    // cout << sudoku_better(arr, 0, calls);
    //================================================
    return 0;
}