#include<iostream>
#include<vector>
using namespace std;

void input(vector<vector<int>> &arr ){
    for(int i=0 ; i<arr.size() ; i++){
        for(int j=0 ; j<arr.size() ; j++){
            cin>>arr[i][j];
        }
    }
}

int maxi(vector<vector<int>> &arr){
    int max_=arr[0][0];

    for(int i=0 ; i<arr.size() ; i++){
        for(int j=0 ; j<arr.size() ; j++){
            if(arr[i][j]>max_)
            max_=arr[i][j];
        }
    }    
    return max_;
}

bool find(vector<vector<int>> &arr , int data){
    for(int i=0 ; i<arr.size() ; i++){
        for(int j=0 ; j<arr.size() ; j++){
            if(data==arr[i][j])
            return true ;
        }
    }
    return false;
}


int main(){
    int row , col;
    cout<<"enter rows and coloumn of array : ";
    cin>>row>>col;
    vector<vector<int>> arr(row , vector<int> (col, 0));
    cout<<"enter array "<<endl;
    input(arr);
    cout<<"maximum of array is "<<maxi(arr)<<endl;
    cout<<"enter data to find : ";
    int a;
    cin>>a;
    cout<<find(arr , a);
    //display(arr);
}
