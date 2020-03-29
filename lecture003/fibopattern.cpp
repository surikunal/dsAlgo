#include<iostream>

using namespace std;

int main(int args,char**argv)
{   int n;
    int a=0;
    int b=1;
    int sum=0;
    
    cout<<"enter no of layers : ";
    cin>>n;
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            cout<<a<<" ";
            sum=a+b;
            a=b;
            b=sum;
        }
        cout<<endl;
    }


}

