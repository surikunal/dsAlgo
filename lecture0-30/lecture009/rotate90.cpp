#include<iostream>
#include<vector>
using namespace std;
void input(vector<vector<int>> &a){
    for(int i=0 ; i<a.size() ; i++){
        //cout<<endl;
        for(int j=0 ; j<a[0].size() ; j++){
            cin>>a[i][j];
        }
    }
}
void print(vector<vector<int>> &a){
    for(int i=0 ; i<a.size(); i++){
        cout<<endl;
        for(int j=0 ; j<a[0].size() ; j++){
            cout<<a[i][j]<<" ";
        }
    }
}
int transpose(vector<vector<int>> &arr){
    for(int i=0 ; i<arr.size() ; i++){
        for(int j=i ; j<arr[0].size() ; j++){
        swap(arr[i][j] , arr[j][i]);
    }
    
}

}
int swapCol(vector<vector<int>> &arr){
    
    int c1=0;
    int c2=arr.size()-1;
    while(c1<c2){
        for(int r=0 ; r<arr[0].size() ; r++){
            swap(arr[r][c1] , arr[r][c2]);
        }
        c1++;
        c2--;
    }
}
int main(){
    int row , col ;
    cout<<"enter row and col value "<<endl;
    cin>>row>>col;
    vector<vector<int>> arr(row , vector<int> (col , 0));
    cout<<"enter array "<<endl;
    input(arr);
    transpose(arr);
    swapCol(arr);
    cout<<"matrix after 90degree rotation ";
    print(arr);
}
