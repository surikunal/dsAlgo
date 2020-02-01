#include<iostream>

using namespace std;
int power(int a , int b){
    if(b==0)
    return 1;

    int recans=power(a,b-1);
    return (recans)*a;
} 
int main(int args , char** argv){
    cout<<power(2,5);
    
}