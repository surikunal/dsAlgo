#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void hashMapOperation_01(string str)
{
    unordered_map<char, int> map;

    for (int i = 0; i < str.size(); i++)
    {
        map[str[i]]++;
    }

    for (auto i : map)
    {
        cout << i.first << " -> [" << i.second << "]" << endl;
    }
}

void hashMapOperation_02()
{
    unordered_map<string, int> map;
    map["USA"] = 100;
    map["India"] = 100000;
    map["iran"] = 10034;
    map["asia"] = 1001;
    map["america"] = 12100;
    map["kunal"] = 99100;

    for (auto s: map)
    {
        cout << s.first << " -> " << s.second << endl;
    }
}

void hashMapOperation_03(string str)
{
    unordered_map<char, int> map;

    for (int i = 0; i < str.size(); i++) 
    {
        char ch = str[i];
        if (map.find(ch) != map.end())
            map[ch]++;
        else
        {
            map[ch] = 1;
        }
    }

    for (auto c: map)
    {
        cout << c.first << " -> " << c.second << endl;
    }
}

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

        for (auto keys : map)
        {
            if (keys.second)
            {
                int num = keys.first + 1;
                int smallSize = 1;
                while (map.find(num) != map.end())
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
    string str = "imkunalsuri";
    // hashMapOperation_01(str);
    // cout << endl;
    // hashMapOperation_02();
    // cout << endl;
    // hashMapOperation_03(str);
    // cout << endl;
    // vector<int> arr{0, 1, 2, 3, 5, 7, 8, 9, 10, 87, 88, 89, 99, 100, 101, 102, 103};
    // longestSeries(arr);
    return 0;
}