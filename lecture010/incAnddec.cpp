#include <iostream>
using namespace std;
void increasing(int a, int b)
{
    if (b == a - 1)
        return;

    increasing(a, b - 1);
    cout << b << endl;
}

void decreasing(int a, int b)
{
    if (b == a - 1)
        return;

    cout << b << endl;
    decreasing(a, b - 1);
}

void solve()
{
    cout << "increasing using recursion " << endl;
    increasing(1, 10);
    cout << "decreasing using recursion " << endl;
    decreasing(1, 10);
}

int main(int args, char **argv)
{
    solve();
}