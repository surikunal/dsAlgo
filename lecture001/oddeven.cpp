#include <iostream>
using namespace std;
int main()
{
    int a;
    cout << "Enter a numbers : ";
    cin >> a;
    if (a % 2 == 0)
    {
        cout << a << " is even";
    }
    else
    {
        cout << a << " is odd";
    }
}