#include <iostream>
#include <vector>
using namespace std;
void print(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i];
    }
}

void addArray(vector<int> &arr1, vector<int> &arr2)
{
    int size = arr1.size() > arr2.size() ? arr1.size() : arr2.size();
    int carry = 0;
    vector<int> res(size + 1, 0);
    int i = arr1.size() - 1;
    int j = arr2.size() - 1;
    int k = res.size() - 1;
    while (i >= 0 || j >= 0 || carry != 0)
    {
        int ans = carry;
        if (i >= 0)
            ans += arr1[i];
        if (j >= 0)
            ans += arr2[j];

        int rem = ans % 10;
        carry = ans / 10;
        res[k] = rem;
        k--;
        i--;
        j--;
    }
    print(res);
}

int reverse(int num)
{
    int temp = 0;
    while (num != 0)
    {
        int rem = num % 10;
        temp = temp * 10 + rem;
        num /= 10;
    }
    return temp;
}

vector<int> numToArray(int num)
{
    // int count = 0;
    // int temp = num;
    // while(num!=0) {
    //     num/=10;
    //     count++;
    // }
    num = reverse(num);
    vector<int> arr;
    while (num != 0)
    {
        arr.push_back(num % 10);
        num /= 10;
    }
    return arr;
}

int main(int args, char **argv)
{

    int no1, no2;
    //cout<<"enter row and col value "<<endl;

    // vector<int> arr1={9,9,9,9,9};
    // vector<int> arr2={1};
    cin >> no1;
    vector<int> arr1 = numToArray(no1);
    // print(arr1);
    cin >> no2;
    vector<int> arr2 = numToArray(no2);
    // print(arr2);
    // arr1.push_back(no1);
    // arr2.push_back(no2);
    addArray(arr1, arr2);
    //print(arr);
}