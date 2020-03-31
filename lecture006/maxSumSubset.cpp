#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maximumSumSubset(vector<int> &arr)
{
    int imax = 0;
    int omax = INT_MIN;
    for (int i = 0; i < arr.size(); i++)
    {
        imax += arr[i];

        if (imax < 0)
        {
            imax = 0;
        }
        else if (imax > omax)
        {
            omax = imax;
        }
    }
    return omax;
}

int main(int args, char **argv)
{
    vector<int> arr{-2, -3, 4, -1, -2, 1, 5, -3};   // ans = 7
    cout << maximumSumSubset(arr) << endl;
}