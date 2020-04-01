#include<iostream>
#include<vector>
#include<climits>
using namespace std ;

int minimum(vector<int> &arr , int idx)
{
    if(idx==arr.size())
    return INT_MAX;

    if(idx==arr.size()-1)
    return arr[idx];

    int ans=minimum(arr , idx+1);

    if(arr[idx]<ans){
        ans=arr[idx];
    }
        return ans;
}
int main(int args , char** argv){
    vector<int> arr = {1,2,3,4,5,5,6,6,77,88,7,7,6,77,8};
    cout<<minimum(arr, 0);
}