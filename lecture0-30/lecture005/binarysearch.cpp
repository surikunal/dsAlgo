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

bool BS(vector<int> &arr, int data)
{
    int si = 0;
    int ei = arr.size() - 1;
    //int b=0;
    while (si < ei)
    {
        int mid = (si + ei) / 2;

        if (arr[mid] == data)
        {
            return true;
        }
        else if (arr[mid] > data)
        {
            ei = mid - 1;
        }
        else
        {
            si = mid + 1;
        }
    }

    si++;
    ei--;
    return false;
}

int main(int args, char **argv)
{
    int n, b;
    cout << "Enter length of array : ";
    cin >> n;
    vector<int> arr(n, 0);
    cout << "Enter array : ";
    input(arr);
    int data;
    cout << "enter an element to search : ";
    cin >> data;
    bool x = BS(arr, data);
    if (x == 1)
        cout << "found";
    else
        cout << "no found";

    // if(b==0){
    // cout<<"Not found";
}
