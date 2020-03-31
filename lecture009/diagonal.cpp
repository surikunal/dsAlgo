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
void diagonal_(vector<vector<int>> &arr)
{
    int m = arr[0].size();
    int n = arr.size();
    for (int gap = 0; gap < m; gap++)
    {
        for (int i = 0, j = gap; i < n && j < m; i++, j++)
        {
            cout << arr[i][j] << " ";
        }
    }
}
int main(int args, char **argv)
{
    int row, col;
    cout << "enter row and col value " << endl;
    cin >> row >> col;
    vector<vector<int>> arr(row, vector<int>(col, 0));
    cout << "enter array " << endl;
    input(arr);
    cout << "dioganls are " << endl;
    diagonal_(arr);
}