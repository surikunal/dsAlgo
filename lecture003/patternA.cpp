#include<iostream>
using namespace std;
int main(int args,char**aggv){
    int n;
    cout<<"Enter the no of rows : ";
    cin>>n;
    int nst=1;
    int nsp=n-1;
    for(int r=0;r<n;r++){
        for(int csp=1;csp<=nsp;csp++){
            cout<<" ";
        }
        for(int cst=1;cst<=nst;cst++){
            cout<<"*";
        }
        nst+=2;
        nsp--;
        cout<<endl;
    }
}
