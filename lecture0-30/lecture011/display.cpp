#include<iostream>
#include<vector>
using namespace std ;
void display(vector<int> arr , int idx){
    if(idx==arr.size())
    return ;

    cout<<arr[idx]<<" ";
    display(arr , idx+1);
}
int main(int args , char** argv){
    vector<int> arr={10,20,30,40,50,60,70,80};
    display(arr , 0);   
}