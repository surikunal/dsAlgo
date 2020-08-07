#include <iostream>
using namespace std;
int main()
{
    int a, b, c;
    cout << "Enter 3 numbers : ";
    cin >> a >> b >> c;
    if (a > b && a > c)
    {
        cout << a << " is largest ";
    }
    else if (b > a && b > c)
    {
        cout << b << " is largest ";
    }
    else
    {
        cout << c << " is largest ";
    }
}