#include<iostream>
using namespace std;

int main()
{
    int a;
    cout<<"Enter a no to count no of digits : ";
    cin>>a;
    int digits=0;
    while(a!=0){
        a/=10;
        digits++;
    }
    cout<<"no of digits are "<<digits;
}