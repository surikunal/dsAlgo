#include <iostream>
using namespace std;

int main()
{
    int a = 0, b = 1, n;
    cout << "which position in fibonacci series : ";
    cin >> n;
    cout << "series is ";
    if (n >= 1)
    {
        cout << a << " ";
        if (n == 1)
            return 0;
    }
    if (n >= 2)
    {
        cout << b << " ";
        if (n == 2)
        {
            return 0;
        }
        int sum = 0;

        for (int i = 3; i <= n; i++)
        {
            sum = a + b;
            a = b;
            b = sum;
            cout << sum << " ";
        }
    }
}