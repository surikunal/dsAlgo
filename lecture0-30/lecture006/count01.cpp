#include<iostream>
#include<vector>
using namespace std;

void zeroAndOnes(vector<int>& arr){
    int pt=0;
    int itr=0;

    while(itr<arr.size()){
        if(arr[itr]==0){
            swap(arr[itr],arr[pt]);     //in cpp , swap function is inbuilt
            pt++;                       //but we have to make it in java
        }
        itr++;
    }
}
int main(){
    vector<int> arr={0,1,0,1,1,1,0,0,0,0,1,0,1,0,1,0,0,1};
    zeroAndOnes(arr);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}