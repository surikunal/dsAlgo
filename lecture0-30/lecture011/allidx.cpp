#include<iostream>
#include<vector>
using namespace std ;
vector<int> allidx(vector<int> &arr , int idx , int data , int count)
{
    if(idx==arr.size())
    {
        vector<int> baseArray(count);
        return baseArray;
    }
    if(arr[idx]==data)
    {
        count++;
    }

    vector<int> recans = allidx(arr , idx+1 , data , count);

    if(arr[idx]==data)
    {
        recans[count-1]=idx;
    }
    return recans;
}
int main(int args , char** argv)
{
    vector<int> arr = {10,20,30,40,50,60,70,21,1,4,7,8,9,4,0,5,4,2,56};
    vector<int> ans = allidx(arr , 0 , 4 , 0);
    for(int i : ans)
    {
        cout<<i<<" ";
    }
}
