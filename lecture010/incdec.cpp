#include <iostream>

using namespace std;
void inc_dec(int a, int b)
{
    if (a == b)
    {                      //OR
        cout << b << endl; //cout<<a;
        return;
    }

    cout << b;         //cout<<a;
    inc_dec(a, b - 1); //inc_dec(a+1,b)
    cout << b;         //cout<<a;
}

void main(int args, char **argv)
{
    inc_dec(1, 5);
}