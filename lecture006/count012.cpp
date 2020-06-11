#include <iostream>
#include <vector>
using namespace std;

void zeroAndOnesTwo(vector<int> &arr)
{
    int pt1 = 0;
    int pt2 = arr.size() - 1;
    int itr = 0;

    while (itr <= pt2)
    {
        if (arr[itr] == 0)
        {
            swap(arr[itr], arr[pt1]); //in cpp , swap function is inbuilt
            pt1++;
            itr++; //but we have to make it in java
        }
        else if (arr[itr] == 2)
        {
            swap(arr[itr], arr[pt2]);
            pt2--;
        }
        else
        {
            itr++;
        }
    }
}
int main()
{
    vector<int> arr = {0, 1, 0, 1, 1, 1, 2, 2, 0, 0, 0, 0, 2, 1, 0, 1, 0, 1, 0, 0, 1};
    zeroAndOnesTwo(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}