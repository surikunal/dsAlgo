#include<iostream>

using namespace std;
int val_(int n){
    //int n;
    for(int i=0;i<n;i++){
        int val=1;
        for(int j=0;j<=i;j++){
            cout<<val;
            val=(i-j)*val/(j+1);
        }
    cout<<endl;
    
    }
}
int main(int args,char**argv){
    int n;
    //int val;
    cout<<"Enter no of rows : ";
    cin>>n;
    val_(n);
    
}