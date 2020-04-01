#include<iostream>
#include<vector>

using namespace std;
int lastIndex(vector<int> &arr , int idx , int data){
    if(arr.size()==idx){
        return -1;
    }

    int recAns = lastIndex(arr , idx+1 , data);

    if(recAns!=-1)
    return recAns;
    else{
        return arr[idx]==data ? idx : -1 ;
    }
}

int main(int args , char** argv){
    vector<int> arr = {1,2,2,4,5,5,5,66,6,6,7,77,4,34,5,5,4,44,5,5,6};
    cout<<"last index is "<<lastIndex(arr ,0, 7);
}