#include<iostream>
#include<vector>
using namespace std;
int inc(int a , int b){
    if(a==b){
        cout<<a<<" ";
        return a;
    }
    
    cout<<a<<" ";
    int rec = inc(a+1, b);
    cout<<a<<" ";
}
int oddeven(int a , int b){
    if(a==b){
        cout<<a<<" ";
        return a;
    }
    
    if(a%2==0){
        cout<<a<<" ";
    }
    int rec = oddeven(a+1, b);
    if(a%2!=0){
        cout<<a<<" ";
    }
}
int printIncr(int n){
        if(n==0){
        return 0;
    }
         
    int rec = printIncr(n-1);
    cout<<rec+1<<" ";
    return rec+1;
}

int printDecr(int n, int a){
        if(n==0){
        return 0;
    }
         
    int rec = printDecr(n+1 , a);
    cout<<rec+1<<" ";
    return rec+1;
}

int main(){
    //inc(1,5);
    // oddeven(1,6);
    printDecr(5,0);
}