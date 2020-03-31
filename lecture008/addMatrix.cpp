#include <iostream>
#include <vector>
using namespace std;
void input(vector<vector<int>> &a)
{
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a[0].size(); j++)
        {
            cin >> a[i][j];
        }
    }
}
void print(vector<vector<int>> &a)
{
    for (int i = 0; i < a.size(); i++)
    {
        cout << endl;
        for (int j = 0; j < a[0].size(); j++)
        {
            cout << a[i][j] << " ";
        }
    }
}
void addition(vector<vector<int>> &mat1, vector<vector<int>> &mat2)
{
    for (int i = 0; i < mat1.size(); i++)
    {
        for (int j = 0; j < mat2[0].size(); j++)
        {
            mat1[i][j] += mat2[i][j];
        }
    }
}
int main(int args, char **argv)
{
    int m, n;
    cout << "enter row and col of matrix " << endl;
    cin >> m >> n;
    cout << "enter 1st array " << endl;
    vector<vector<int>> arr(m, vector<int>(n, 0));
    input(arr);
    // int p,q;
    // cout<<"enter row and col of 2nd matrix "<<endl;
    // cin>>p>>q;
    cout << "enter 2nd array " << endl;
    vector<vector<int>> ar(m, vector<int>(n, 0));
    input(ar);
    addition(arr, ar);
    cout << "array after addition is " << endl;
    print(arr);
}
