#include<iostream>
#include<vector>
#include<climits>

using namespace std ;
int maximum(vector<int> &arr , int idx){
    if(idx==arr.size())
    return INT_MIN;

    if(idx==arr.size()-1)
    return arr[idx];

    int recMax=maximum(arr,idx+1);

    //return max(arr[idx],recMax);

    if(arr[idx]>recMax){
         recMax=arr[idx];
        }
        return recMax;
}
int main(int args , char** argv){
    vector<int> arr={1,2,3,4,5,6,77,89,9,0,-2};
    cout<<maximum(arr,0);
}