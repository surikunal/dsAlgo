#include <iostream>
#include <string>
#include <vector>

#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
#define vvb vector<vb>

using namespace std;
int queen(int r, int tnq, vb &col, vb &diag, vb &adiag, string ans)
{
    int n = col.size();
    if (r == n || tnq == 0)
    {
        if (tnq == 0)
        {
            cout << ans << endl;
            return 1;
        }
        return 0;
    }
    int count = 0;
    for (int c = 0; c < n; c++)
    {
        if (!col[c] && !diag[r + c] && !adiag[r - c + n - 1])
        {
            col[c] = true;
            diag[r + c] = true;
            adiag[r - c + n - 1] = true;

            count += queen(r + 1, tnq - 1, col, diag, adiag, ans + "(" + to_string(r) + ", " + to_string(c) + ")");

            col[c] = false;
            diag[r + c] = false;
            adiag[r - c + n - 1] = false;
        }
    }
    return count;
}

//============================================================
int queenBITS(int n, int r, int tnq, int col, int diag, int adiag, string ans)
{
    if (r == n || tnq == 0)
    {
        if (tnq == 0)
        {
            cout << ans << endl;
            return 1;
        }
        return 0;
    }
    int count = 0;

    for (int c = 0; c < n; c++)
    {
        int w = 1 << c;
        int x = 1 << (r + c);
        int y = 1 << (r - c + n - 1);

        if (!(col & w) && !(diag & x) && !(adiag & y))
        {
            col ^= w;
            diag ^= x;
            adiag ^= y;

            count += queenBITS(n, r + 1, tnq - 1, col, diag, adiag, ans + "(" + to_string(r) + ", " + to_string(c) + ")");

            col ^= w;
            diag ^= x;
            adiag ^= y;
        }
    }
    return count;
}

void solve()
{
    int r = 4, c = 4;
    // vb col(4, false);
    // vb diag(r + c - 1, false);
    // vb adiag(r + c - 1, false);
    // cout << queen(0, 4, col, diag, adiag, "");

    // cout << queenBITS(c, 0, r, 0, 0, 0, "");

}
int main(int args, char **argv)
{
    solve();
    return 0;
}