#include<iostream>
#include<vector>
using namespace std;

void input(vector<vector<int>> &arr){
    for(int row=0 ; row<arr.size() ; row++){
        for(int col=0 ; col<arr[0].size() ; col++){
            cin>>arr[row][col];
        }
    }
}

int spiral(vector<vector<int>> &arr ){
    int minr=0 ,minc=0 ;
    int maxr=arr.size()-1;
    int maxc=arr[0].size()-1;
    int count=0;
    int total=arr.size() * arr[0].size();
    while(count<total){
        for(int row=minr ; row<=maxr && count<total ; row++){
            cout<<arr[row][minc]<<" ";
            count++;
        }
        minc++;
        for(int col=minc ; col<=maxc && count<total  ; col++){
            cout<<arr[maxr][col]<<" ";
            count++;
        }
        maxr--;
        for(int row=maxr ; row>=minr && count<total  ; row--){
            cout<<arr[row][maxc]<<" ";
            count++;
        }           
        maxc--;
        for(int col=maxc ; col>=minc && count<total  ; col--){
            cout<<arr[minr][col]<<" ";
            count++;
        } 
        minr++;
    }
}

int main(int args , char**argv){
    int row , col;
    cout<<"Enter row and col value : ";
    cin>>row>>col;
    cout<<"enter array "<<endl;
    vector<vector<int>> arr(row , vector<int> (col , 0));
    input(arr);
    cout<<"new array is "<<endl;
    spiral(arr);

}