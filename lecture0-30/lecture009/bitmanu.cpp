#include <iostream>
#include <vector>
using namespace std;
/* _________________ON a bit________________ */
void ONbits(int &n, int k)
{
    int mask = (1 << k);
    n |= mask;
}
/* _________________OFF a bit________________ */

void OFFbits(int &n, int k)
{
    int mask = (~(1 << k));
    n &= mask;
}

int main()
{
    int num = 89;
    ONbits(num, 7);
    cout << num << endl;
    OFFbits(num, 7);
    cout << num << endl;
    return 0;
}