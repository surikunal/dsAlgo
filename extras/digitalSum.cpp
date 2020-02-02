#include <iostream>
using namespace std;

int main(int args, char **argv)
{
    int n;
    cout << "Enter any digit no :";
    cin >> n;

    int sum = 0;
    while (n > 10)
    {
        while (n > 0)
        {
            int digit = n % 10;
            sum += digit;
            n = n / 10;
        }
        n = sum;
    }
    cout << "digital Sum : " << sum;
    return 0;
}