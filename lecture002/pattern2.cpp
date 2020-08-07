#include <iostream>

using namespace std;

int main(int args, char **argv)
{
    int n;

    cout << "enter no of layers : ";
    cin >> n;
    int nst = 1;
    int nsp = n - 1;

    for (int r = 1; r <= n; r++)
    {
        for (int csp = 1; csp <= nsp; csp++)
        {
            cout << " ";
        }
        for (int cst = 1; cst <= nst; cst++)
        {
            cout << "*";
        }
        cout << endl;
        nst++;
        nsp--;
    }
}