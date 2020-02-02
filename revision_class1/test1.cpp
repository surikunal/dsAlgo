#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

// int fact_(int n){
//     int fact =1 ;
//     for(int i=1; i<=n ; i++){
//         fact*=i;
//     }
//     return fact;
//     }

// int main() {
//     /* Enter your code here. Read input from STDIN. Print output to STDOUT */
//     int n ;
//     int r; 
//     int p,c;
//     int fact=1;
//     cin>>n;
//     cin>>r;
//     cout<<fact_(n)<<endl;
    
//     for(int i=1; i<=n ; i++){
//         for(int j=1; j<=r ; j++){
//             p=fact_(n)/fact_(n-r);
//         }
//     }
//     cout<<p<<endl;

//     for(int i=1 ; i<=n ; i++){
//         for(int j=1 ; j<=r ; j++){
//             c=fact_(n)/(fact_(n-r)*fact_(r));
//         }
//     }
//     cout<<c;
//     return 0;
// }
bool isSafeToPlacQueen(vector<vector<bool>> & board,int x,int y)
{
    vector<vector<int>> dir={{-1,0},{0,-1} ,{-1,-1},{-1,1},
                             {1,0},{0,1} ,{1,1},{1,-1}};
    for(int i=0;i<dir.size();i++){
        for(int rad=1;rad<max(board.size(),board[0].size());rad++){
            int nx=x+ rad*dir[i][0];
            int ny=y+ rad*dir[i][1];
            if(nx<0 || ny<0 || nx>=board.size() || ny>=board[0].size()) break;
            if(board[nx][ny]) return false;
        }
    }
    return true;
}
int queen2DPermu(vector<vector<bool>> &board, int qpsf, int tnq, string ans)
{
    if (qpsf == tnq)
    {
        cout << ans << endl;
        return 1;
    }
    int count = 0;
    for (int i = 0; i < board.size() * board[0].size(); i++)
    {
        int x = i / board[0].size();
        int y = i % board[0].size();
        if (!board[x][y] && isSafeToPlacQueen(board, x, y))
        {
            board[x][y] = true;
            count += queen2DPermu(board, qpsf + 1, tnq,
                                  ans + "(" + to_string(x) + ", " + to_string(y) + ") ");
            board[x][y] = false;
        }
    }
    return count;
}
void queens()
{
    //  vector<bool> box(16,false);
    // cout << queenCombi(16, 0, 0, 4, "") << endl;
    // cout<<queenPermu(box,0,3,"")<<endl;

    vector<vector<bool>> board(4, vector<bool>(4, false));
    // cout << queen2DCombi(board, 0, 4, "") << endl;
    cout << queen2DPermu(board, 0, 4, "") << endl;
    // cout << queen(board, 0, 10, "") << endl;
    // cout<<calls<<endl;
}
void maxSumSubset(vector<int> &arr)
{
    int s = 0;
    int start_idx = 0;
    int end_idx = 0;
    int iterative_max = 0;
    int original_max = -10000000;

    for (int i = 0; i < arr.size(); i++)
    {
        iterative_max += arr[i];
        
        if (original_max < iterative_max)
        {
            end_idx = i;
            start_idx = s;
            original_max = iterative_max;
        }
        if (iterative_max < 0)
        {
            s = i + 1;
            iterative_max = 0;
        }
    }
}
void solve()
{
    // basicQues();
    // combiPermu();
    // queens();
    vector<int> arr = {8, -8, 9, -9, 10, -11, 12};
    maxSumSubset(arr);
}

// int main()
// {
//     solve();
//     return 0;
// }
#include<iostream>
#include<vector>
using namespace std;
void Subsets(vector<bool> &isDone, vector<int> &arr, int idx, string ans)
{
    cout << "[" << ans << "]" << endl;
    if (idx == arr.size())
    {
        return;
    }
    
    for(int i = 0; i < arr.size(); i++)
    {
        if(!isDone[i])
        {
            isDone[i] = true;
            Subsets(isDone, arr, i + 1, ans + to_string(arr[i]) + " ");
            isDone[i] = false;
        }
    }
}

int main(int args , char**argv){
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for(int i = 0; i< n; i++)
    {
        cin >> arr[i];
    }
    vector<bool> isDone(n, false);
    Subsets(isDone, arr, 0, "");
    return 0;
}