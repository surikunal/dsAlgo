#include <iostream>
#include <vector>
using namespace std;

void input(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }
}

void swap(vector<int> &arr, int y, int x)
{
    int temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
}

void reverse_(vector<int> &arr, int si, int ei)
{
    while (si < ei)
    {
        swap(arr, si, ei);
        si++;
        ei--;
    }
}

void display(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
}

int main(int args, char **argv)
{
    int a, n;
    cout << "Enter no of elements in the array : ";
    cin >> n;
    vector<int> arr(n, 0);
    cout << "Enter an array : ";
    input(arr);
    int si;
    cout << "Enter starting index : ";
    cin >> si;
    int ei;
    cout << "Enter end index : ";
    cin >> ei;
    reverse_(arr, si, ei);
    cout << "reversed array is : ";
    display(arr);
    return 0;
}
