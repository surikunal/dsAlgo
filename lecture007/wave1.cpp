#include<iostream>
#include<vector>
using namespace std;
void wave(vector<vector<int>> &arr){
    int m,n;
    n=arr.size();
    m=arr[0].size();
    for(int row=0; row<n ; row++){
        if(row%2==0){
            for(int col=0 ; col<m ; col++){
                cout<<arr[row][col]<<" ";
            }
        }
        else{
            for(int col=m-1 ; col>=0 ; col--){
                cout<<arr[row][col]<<" ";
            }
        }
    }
}
void input(vector<vector<int>> &arr){
    for(int row=0 ; row<arr.size() ; row++){
        for(int col=0 ; col< arr[0].size() ; col++){
            cin>>arr[row][col];
        }
    }
}
void display(vector<vector<int>> &arr){
    for(int row=0 ; row<arr.size() ; row++){
        for(int col=0 ; col< arr[0].size() ; col++){
            cout<<arr[row][col]<<" ";
        }
    }
}

int main(int args , char**argv){
    int row=0 , col=0;
    cin>>row>>col;
    vector<vector<int>> arr(row , vector<int>(col,0));
    input(arr);
    cout<<endl;
    wave(arr);
    //display(arr);
}