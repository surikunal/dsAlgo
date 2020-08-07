//the only pattern which is more preferable to do with i,j method

#include <iostream>
using namespace std;

int main(int args, char **argv)
{
    int n;
    cout << "Enter no of layers : ";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j || i + j == n + 1)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}