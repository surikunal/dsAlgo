#include<iostream>
using namespace std;

void rotateDigits(int n, int k)
{
    int temp = n;
    int digits = 0;
    while (temp != 0)
    {
        temp /= 10;
        digits++;
    }

    k %= digits;

    if (k < 0)
    {
        k += digits;
    }

    int div = 1;
    int mult = 1;
    for (int i = 1; i <= digits; i++)
    {
        if (i <= k)
        {
            mult *= 10;
        }
        else
        {
            div *= 10;
        }
    }
    int rem = n % div;
    int oldVal = n / div;

    n = rem * mult + oldVal;
    cout << n;
}

int main()
{
    int n = 2345456;
    int k = 3;
    rotateDigits(n, k);
    return 0;
}