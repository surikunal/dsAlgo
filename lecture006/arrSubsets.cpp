#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> &arr , int si , int ei){
    for(int i=si ; i<=ei ; i++){
            cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void Substs(vector<int> &arr){
    for(int i=0 ; i<arr.size() ; i++){
        for(int j=i ; j<arr.size() ; j++){
             print(arr , i , j);
            //cout<<arr[j];
        }
       // cout<<endl;
    }  
}
int main(int args , char**argv){
    int n;
    cout<<"Enter size of array : ";
    cin>>n;
    vector<int> arr(n,0);
    cout<<"enter array : ";
    for(int i=0 ; i<n ; i++){
        cin>>arr[i];
    }
    Substs(arr);
    return 0;
}