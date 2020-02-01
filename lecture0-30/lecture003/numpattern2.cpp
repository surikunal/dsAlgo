#include<iostream>

using namespace std;

int main(int args,char**argv)
{   int n;
    
    cout<<"enter no of layers : ";
    cin>>n;
    int nst=1;
    int nsp=n/2;

    for(int r=1;r<=n;r++)
    {
        for(int csp=1;csp<=nsp;csp++){
            cout<<" ";
        }
        int val;
        if(r<=n/2){
            val=r;
        }   
        else{
            val=n-r+1;
        }

        for(int cst=1;cst<=nst;cst++){
        cout<<val;
        if(cst<=nst/2){
            val--;

            }  
        else{
            val++;
            
            }
        }
        if(r<=n/2){
        nst+=2;
        nsp--;
        }
        else{
        nst-=2;
        nsp++;
        }
        cout<<endl;
        
    }
}