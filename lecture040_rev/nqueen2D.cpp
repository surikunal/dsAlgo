#include <iostream>
#include <vector>
#include <string>
using namespace std;
int nqueen2D_permu(vector<vector<bool>> &board, int tnq, int qpsf, string ans)
{
    if (qpsf == tnq)
    {
        cout << ans << endl;
        return 1;
    }

    int count = 0;
    for (int i = 0; i < board.size() * board[0].size(); i++)
    {
        int r = i / board[0].size();
        int c = i % board[0].size();
        if (!board[r][c])
        {
            board[r][c] = true;
            count += nqueen2D_permu(board, tnq, qpsf + 1, ans + "B" + to_string(i) + "Q" + to_string(qpsf) + " ");
            board[r][c] = false;
        }
    }
    return count;
}
int nqueen2D_permu_subseq(vector<vector<bool>> &board, int vidx, int tnq, int qpsf, string ans)
{
    if (vidx == board.size() * board[0].size() || qpsf >= tnq)
    {
        if (tnq == qpsf)
        {
            cout << ans << endl;
            return 1;
        }
        return 0;
    }

    int count = 0;
    int r = vidx / board[0].size();
    int c = vidx % board[0].size();
    if (!board[r][c])
    {
        board[r][c] = true;
        count += nqueen2D_permu_subseq(board, 0, tnq, qpsf + 1, ans + "B" + to_string(vidx) + "Q" + to_string(qpsf) + " ");
        board[r][c] = false;
    }
    count += nqueen2D_permu_subseq(board, vidx + 1, tnq, qpsf, ans);
    return count;
}

int nqueen2D_combi(int row, int col, int vidx, int tnq, int qpsf, string ans)
{
    if (tnq == qpsf)
    {
        cout << ans << endl;
        return 1;
    }

    int count = 0;
    for (int i = vidx; i < row * col; i++)
    {
        count += nqueen2D_combi(row, col, i + 1, tnq, qpsf + 1, ans + "B" + to_string(i) + "Q" + to_string(qpsf) + " ");
    }
    return count;
}

int nqueen2D_combi_subseq(int row, int col, int vidx, int tnq, int qpsf, string ans)
{
    if (vidx == row * col || qpsf >= tnq)
    {
        if (tnq == qpsf)
        {
            cout << ans << endl;
            return 1;
        }
        return 0;
    }

    int count = 0;
    count += nqueen2D_combi_subseq(row, col, vidx + 1, tnq, qpsf + 1, ans + "B" + to_string(vidx) + "Q" + to_string(qpsf) + " ");
    count += nqueen2D_combi_subseq(row, col, vidx + 1, tnq, qpsf, ans);
    return count;
}

void solve()
{
    vector<vector<bool>> board(4, vector<bool>(4, 0));
    cout << nqueen2D_permu(board, 3, 0, "");
    cout << nqueen2D_permu_subseq(board, 0, 3, 0, "");
    cout << nqueen2D_combi(4, 4, 0, 3, 0, "");
    cout << nqueen2D_combi_subseq(4, 4, 0, 3, 0, "");
}
int main(int args, char **argv)
{
    solve();
    return 0;
}