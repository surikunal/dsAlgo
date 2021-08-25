#include <iostream>

using namespace std;
int powerBtr(int a, int b)
{
    if (b == 0)
        return 1;
    //  cout<<"*b"<<endl;
    int recans = powerBtr(a, b / 2);
    recans *= recans;
    //cout<<"#b"<<endl;
    if (b % 2 != 0)
        recans *= a;

    return recans;
}
int main(int args, char **argv)
{
    cout << powerBtr(2, 5) << endl;
}