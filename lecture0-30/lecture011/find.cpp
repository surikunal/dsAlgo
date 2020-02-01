#include<iostream>
#include<vector>
using namespace std ;
bool find(vector<int> &arr, int idx , int data){
    if(idx==arr.size()) 
    return false;

    if(arr[idx]==data)
    return true;

    bool res=find(arr , idx+1 , data);
    return res;

}
int main(int args , char** argv){
    vector<int> arr={1,2,3,4,5,6,77,89};
    int  data=77;
    //cin>>data;
    cout<<find(arr, 0 , data);
}