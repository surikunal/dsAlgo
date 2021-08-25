#include <iostream>
#include <string>
using namespace std;

/*void subsequence(string str , string ans){
    if(str.size()==0){
        cout<<ans<<" ";
        return ;
    }
    char ch = str[0];
    string roq = str.substr(1);
    //int count=0;

    subsequence(roq , ans + ch);
    subsequence(roq , ans);

}*/

//==================================================
//=============== TO COUNT =========================

int subsequence(string str, string ans)
{
    if (str.size() == 0)
    {
        cout << ans << " ";
        return 1;
    }
    char ch = str[0];
    string roq = str.substr(1);
    int count = 0;

    count += subsequence(roq, ans + ch);
    count += subsequence(roq, ans);

    return count;
}
void basic()
{
    cout << subsequence("abc", "");
}
void solve()
{
    basic();
}
int main(int args, char **argv)
{
    solve();
    return 0;
}