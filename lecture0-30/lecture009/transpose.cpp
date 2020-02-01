#include<iostream>
#include<vector>
using namespace std;
void input(vector<vector<int>> &a){
    for(int i=0 ; i<a.size() ; i++){
        for(int j=0 ; j<a[0].size() ; j++){
            cin>>a[i][j];
        }
    }
}
void transpose(vector<vector<int>> &arr){
    for(int i=0 ; i<arr.size() ; i++){
        cout<<endl;
        for(int j=0 ; j<arr[0].size() ; j++){
            // arr[i][j]=arr[j][i];           
            cout<<arr[j][i]<<" ";
    }
}
}
// void print(vector<vector<int>> &a){
//     for(int i=0 ; i<a.size(); i++){
//         cout<<endl;
//         for(int j=0 ; j<a[0].size() ; j++){
//             cout<<a[i][j]<<" ";
//         }
//     }
// }
int main(){
    int row , col ;
    cout<<"enter row and col value "<<endl;
    cin>>row>>col;
    vector<vector<int>> arr(row , vector<int> (col , 0));
    cout<<"enter array "<<endl;
    input(arr);
    transpose(arr);
   // print(arr);
}