#include <iostream>
using namespace std;
void odd_even(int a, int b)
{
    if (a == b)
    {
        cout << a << endl;
        return;
    }

    if (a % 2 != 0)
    {
        cout << a << endl;
    }
    odd_even(a + 1, b);
    if (a % 2 == 0)
    {
        cout << a << endl;
    }
}

int main(int args, char **argv)
{
    int a;
    cout << "enter a num ";
    cin >> a;
    odd_even(1, a);
}