
/* NQUEEN question in 1D */

#include <iostream>
#include <string>
#include <vector>
using namespace std;
/* ____________________combination_____________________ */

int queenCombi(int boxes, int box, int tnq, int q, string ans)
{
    if (q == tnq + 1)
    {
        cout << ans << endl;
        return 1;
    }
    int count = 0;
    for (int i = box; i <= boxes; i++)
    {
        count += queenCombi(boxes, i + 1, tnq, q + 1, ans + "q" + to_string(q) + "b" + to_string(i) + " ");
    }
    return count;
}
/* ____________________permutation_____________________ */
/* ____________________with bit mass___________________ */
int queenPermu(int boxes, int bit, int tnq, int q, string ans)
{
    if (q == tnq + 1)
    {
        cout << ans << endl;
        return 1;
    }
    int count = 0;
    for (int i = 0; i <= boxes; i++)
    {
        int mask = (1 << i);
        if ((bit & mask) == 0)
        {
            bit = (bit | mask);
            count += queenPermu(boxes, bit, tnq, q + 1, ans + "q" + to_string(q) + "b" + to_string(i) + " ");
            bit = (bit & (~mask));
        }
    }
    return count;
}

void setQuestion()
{
    cout << "COMBINATION" << endl;
    cout << queenCombi(5, 0, 3, 1, "") << endl;
    cout << "PERMUTATION" << endl;
    cout << queenPermu(5, 0, 3, 1, "") << endl;
}
void solve()
{
    setQuestion();
}
int main(int args, char **argv)
{
    solve();
    return 0;
}