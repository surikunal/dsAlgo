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
void print(vector<vector<int>> &a){
    for(int i=0 ; i<a.size() ; i++){
        for(int j=0 ; j<a[0].size() ; j++){
            cout<<a[i][j]<<" ";
        }
    }

}
void multiplication(vector<vector<int>> &a , int m , int n , vector<vector<int>> &b , int p , int q){
    vector<vector<int>> res(m ,vector<int> (q,0));
    if(m==p){
        for(int i=0 ; i<a.size() ; i++){
        for(int j=0 ; j<b[0].size() ; j++){
            //res[i][j]=0;
            for(int k=0 ; k<m ; k++){
                res[i][j]+=a[i][j]*b[i][j];
            }

        }
    }
    cout<<"multiplied matrix is "<<endl;
    print(res);
    }
    else{
        cout<<"cannot be multiplied";
    }
}
int main(int args , char**argv){
    int n,m,p,q;
    cout<<"enter row and col of 1st array : "<<endl;
    cin>>m>>n;
    cout<<"enter row and col of 2nd array : "<<endl;
    cin>>p>>q;
    vector<vector<int>> arr(m , vector<int>(n,0)); 
    cout<<"enter 1st array "<<endl;
    input(arr);
    vector<vector<int>> ar(p , vector<int>(q,0));
    cout<<"enter 2nd array "<<endl;
    input(ar);
    multiplication(arr , m , n , ar , p , q);
    //print(arr);
}