#include<iostream>

using namespace std ;
int fibo(int n){
    if(n<=1)
    return n ;

    int recans = fibo(n-1) + fibo(n-2) ;
    return recans;
}
int main(int args , char** argv){
    int a;
    cout<<"enter the position in fibo series "<<endl;
    cin>>a;
    cout<<"number at position " <<a<<" is "<<fibo(a)<<endl;
}