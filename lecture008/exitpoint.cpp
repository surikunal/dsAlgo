#include<iostream>
#include<vector>
using namespace std;
void input(vector<vector<int>> &arr){
    for(int i=0 ; i<arr.size() ; i++){
        for(int j=0 ; j<arr[0].size() ; j++){
            cin>>arr[i][j];
        }
    }
}
void print(vector<vector<int>> &arr){
    for(int i=0 ; i<arr.size() ; i++){
        for(int j=0 ; j<arr[0].size() ; j++){
            cout<<arr[i][j]<<" ";
        }
    }
}
void exit_point(vector<vector<int>> &mat){
    int dir=0;
    int r=0 , c=0;
    while(true){
        dir=((dir + mat[r][c])%4);
        if(dir==0){
            c++;
            if(c==mat[0].size()){
                cout<<r<<" "<<c-1<<endl;
                break;
            }
        }
        else if(dir==1){
            r++;
            if(r==mat.size()){
                cout<<r-1<<" "<<c<<endl;
                break;
            }
        }
        else if(dir==2){
            c--;
            if(c==-1){
                cout<<r<<" "<<c+1<<endl;
                break;       
        }
        }
        else{
            r--;
            if(r==-1){
                cout<<r+1<<" "<<c<<endl;
                break;
        }
    }

}
}
int main(int args , char** argv){
    int row,col;    
    cout<<"enter row and col value "<<endl;
    cin>>row>>col;
    vector<vector<int>> arr(row , vector<int> (col,0));
    cout<<"enter array "<<endl;
    input(arr);
    cout<<"positon of end is ";
    exit_point(arr);
    // print(arr);
   // return 0;
}