#include <iostream>
#include <string>
#include <vector>
using namespace std;
/* ______________________permutation_________________________ */
/* _________________using subsequence method_________________ */

int nQueenPermu(vector<vector<bool>> &boxes, int OneD_idx, int tnq, int q, string ans)
{
    if (q == tnq + 1 || OneD_idx == boxes.size() * boxes[0].size())
    {
        if (q == tnq + 1)
        {
            cout << ans << endl;
            return 1;
        }
        return 0;
    }
    int count = 0;
    int r = OneD_idx / boxes[0].size();
    int c = OneD_idx % boxes[0].size();

    if (!boxes[r][c])
    {
        boxes[r][c] = true;
        count += nQueenPermu(boxes, 0, tnq, q + 1, ans + "q" + to_string(q) + "b" + to_string(OneD_idx) + " ");
        boxes[r][c] = false;                                                                         
    }
    count += nQueenPermu(boxes, OneD_idx + 1, tnq, q, ans);
    return count;
}
//THIS IS JUST TO PRINT ALL THE CASES

int nQueen2D(vector<vector<bool>> &boxes, int tnq, int q, string ans)  
{

    if (q == tnq + 1)
    {
        cout << ans << endl;
        return 1;
    }
    int count = 0;

    for (int i = 0; i < boxes.size() * boxes[0].size(); i++)
    {
        int r = i / boxes[0].size();
        int c = i % boxes[0].size();

        if (!boxes[r][c])
        {
            boxes[r][c] = true;
            count += nQueen2D(boxes, tnq, q + 1, ans + "q" + to_string(q) + "b" + to_string(i) + " ");
            boxes[r][c] = false;
        }
    }
    return count;
}
/* NOW WE WILL DO THE REAL NQUEEN PROBLEM */
int isValidSpot(int r, int c, int n, int m)
{
    if (r < 0 || c < 0 || r >= n || c >= m)
    {
        return false;
    }
    return true;
}

int isQueenSafe(vector<vector<bool>> &boxes, int x, int y)
{
    int n = boxes.size();
    int m = boxes[0].size();

    int arr[4][2] = {{0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};
    for (int i = 0; i < 4; i++)
    {
        for (int rad = 1; rad < max(n, m); rad++)
        {
            int r = x + rad * arr[i][0];
            int c = y + rad * arr[i][1];
            if (isValidSpot(r, c, n, m) && boxes[r][c])
            {
                return false;
            }
        }
    }
    return true;
}
int nQueen(vector<vector<bool>> &boxes, int idx, int tnq, int qpsf, string ans)
{

    if (qpsf == tnq)
    {
        cout << ans << endl;
        return 1;
    }
    int n = boxes.size();
    int m = boxes[0].size();

    int count = 0;
    for (int i = idx; i < m * n; i++)
    {
        int r = i / m;
        int c = i % m;
        if (isQueenSafe(boxes, r, c))
        {
            boxes[r][c] = true;
            // count+=nQueen(boxes , i+1 , tnq , qpsf+1 , ans + "q" + to_string(qpsf+1) + "b" + to_string(i+1) + " ");
            count += nQueen(boxes, i + 1, tnq, qpsf + 1, ans + "(" + to_string(r) + "," + to_string(c) + ")q" + to_string(qpsf + 1) + " ");
            boxes[r][c] = false;
        }
    }
    return count;
}
/* lets print only one answer and left the rest */
/* USING SUBSEQUENCE METHOD */
bool nQueenSub01(vector<vector<bool>> &boxes, int idx, int tnq, int qpsf, string ans)
{
    int n = boxes.size();
    int m = boxes[0].size();

    if (qpsf == tnq || idx >= n * m)
    {

        if (qpsf == tnq)
        {
            cout << ans << endl;
            return true;
        }
        return false;
    }

    bool flag = false;
    int r = idx / m;
    int c = idx % m;
    if (isQueenSafe(boxes, r, c))
    {
        boxes[r][c] = true;
        // count+=nQueen(boxes , idx+1 , tnq , qpsf+1 , ans + "q" + to_string(qpsf+1) + "b" + to_string(idx+1) + " ");
        flag = flag || nQueenSub01(boxes, idx + 1, tnq, qpsf + 1, ans + "(" + to_string(r) + "," + to_string(c) + ")q" + to_string(qpsf + 1) + " ");
        boxes[r][c] = false;
    }
    flag = flag || nQueenSub01(boxes, idx + 1, tnq, qpsf, ans);
    return flag;
}

void setQuestion()
{

    vector<vector<bool>> boxes(4, vector<bool>(4, 0));
    // cout<<nQueenPermu(boxes , 3 , 1 , 0, "")<<endl;     /* these are just 2 methods to print all the conditons */
    // cout<<nQueen2D(boxes , 3 , 1 , "")<<endl;
    cout << "num of arrangements are " << nQueen(boxes, 0, 4, 0, "") << endl; /* this is real n queen problem */
    //int stop = 0;
    // cout<<"num of arrangements are "<<nQueenSub01(boxes , 0 , 4 , 0 , "")<<endl;       /* when we want to print only first answer and ignore the rest */
    /* also do this nQueen problem using subsequence method */
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