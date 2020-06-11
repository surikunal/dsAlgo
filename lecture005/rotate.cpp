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

void display(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
}

void swap(vector<int> &arr, int x, int y)
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

void rotate_(vector<int> &arr, int k)
{
    k %= arr.size();
    k = k < 0 ? k + arr.size() : k;

    reverse_(arr, 0, k - 1);
    reverse_(arr, k, arr.size() - 1);
    reverse_(arr, 0, arr.size() - 1);
}

int main(int args, char **argv)
{
    int n, k;
    cout << "Enter no of elements in array : ";
    cin >> n;
    vector<int> arr(n, 0);
    cout << "Enter array : ";
    input(arr);
    cout << "Enter index of array to rotate from : ";
    cin >> k;
    rotate_(arr, k);
    cout << "rotated array is : ";
    display(arr);
}
