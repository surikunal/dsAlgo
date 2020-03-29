#include <iostream>
#include <vector>

using namespace std;

int min(vector<int> arr)
{ //public static int min (for java)
    int min = arr[0];

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    return min;
}
int max(vector<int> &arr)
{ //public static int max (for java)
    int max = arr[0];
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}
bool find(vector<int> &arr, int data)
{ //public static bool find (for java)
    //cout << "enter a no from the array to find : ";
    for (int i = 0; i < arr.size(); i++)
    { //arr.length(for java)
        if (arr[i] == data)
            //cout<<"element "<<i<<" is present";
            return true;
    }
    return false;
}
void display(vector<int> &arr)
{
    cout << "entered array is : ";
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
}

void input(vector<int> &arr)
{
    cout << "Enter array : ";
    for (int i = 0; i < arr.size(); i++)
        cin >> arr[i];
}

int main(int args, char **argv)
{
    int a, n;
    cout << "how many elements in the array : ";
    cin >> a;
    vector<int> arr(a, 0);

    input(arr);
    display(arr);
    cout << endl;
    cout << "the minimum no in array is : " << min(arr) << endl;
    cout << "the maximum no in array is : " << max(arr) << endl;
    cout << "Enter a element to search : ";
    cin >> n;
    bool x = find(arr, n);
    if (x == 1)
    {
        cout << "elemnt is present";
    }
    else
    {
        cout << "element not present";
    }
    return 0;
}