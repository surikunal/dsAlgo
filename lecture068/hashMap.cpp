#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int longestSeries(vector<int> &arr)
{
    unordered_map<int, bool> map; // pair like

    for (int ele : arr)
        map[ele] = true;

    int size = -1;
    int number = -1;
    for (auto keys : map)
    {
        if ((map.find(keys.first - 1)) != map.end())
        {
            map[keys.first] = false;
        }

        for (auto keys: map)
        {
            if (keys.second) 
            {
                int num = keys.first + 1;
                int smallSize = 1;
                while(map.find(num) != map.end())
                {
                    num++;
                    smallSize++;
                }

                if (smallSize > size)
                {
                    size = smallSize;
                    number = keys.first;
                }
            }
        }
    }

    for (int i = 0; i < size; i++) 
    {
        cout << number + i << " ";
    }
    cout << endl;
}

int main(int argc, char **argv)
{
    vector<int> arr{0, 1, 2, 3, 5, 7, 8, 9, 10, 87, 88, 89, 99, 100, 101, 102, 103};
    longestSeries(arr);
    return 0;
}
