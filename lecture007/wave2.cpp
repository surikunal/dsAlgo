#include<iostream>
#include<vector>
using namespace std;
void wave1(vector<vector<int>> &arr){
    int m,n;
    n=arr.size();
    m=arr[0].size();
    for(int col=0; col<n ; col++){
        if(col%2==0){
            for(int row=0 ; row<m ; row++){
                cout<<arr[row][col]<<" ";
            }
        }
        else{
            for(int row=m-1 ; row>=0 ; row--){
                cout<<arr[row][col]<<" ";
            }
        }
    }
}
void input(vector<vector<int>> &arr){
    for(int col=0 ; col<arr.size() ; col++){
        for(int row=0 ; row< arr[0].size() ; row++){
            cin>>arr[col][row];
        }
    }
}
void display(vector<vector<int>> &arr){
    for(int col=0 ; col<arr.size() ; col++){
        for(int row=0 ; row< arr[0].size() ; row++){
            cout<<arr[col][row]<<" ";
        }
    }
}

int main(int args , char**argv){
    int row=0 , col=0;
    cin>>row>>col;
    vector<vector<int>> arr(row , vector<int>(col,0));
    input(arr);
    cout<<endl;
    wave1(arr);
    //display(arr);
}