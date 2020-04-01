#include <iostream>
#include <vector>
#include <string>
using namespace std;
int pairOfShows(vector<int> &arr)
{
    if (!(arr.size() % 2))
    {
        cout << "all are paired" << endl;
        return -1;
    }
    int si = 0, ei = arr.size() - 1;
    
    while (si <= ei)
    {
        int mid = (si + ei) / 2;
        if (si == ei)
            return arr[mid];

        else if (mid % 2 == 0)
        {
            if (arr[mid] == arr[mid + 1])
            {
                si = mid + 1;
            }
            else
            {
                ei = mid - 1;
            }
        }
        else if(mid % 2 != 0)
        {
            if (arr[mid] == arr[mid - 1])
            {
                si = mid + 1;
            }
            else
            {
                ei = mid - 1;
            }
        }
    }
   return -1;
}
void solve()
{
    vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 4, 5, 6, 6, 7, 7};
    cout <<"the missing num is "<< pairOfShows(arr) << endl;
}
int main(int args, char **argv)
{
    solve();
    return 0;
}