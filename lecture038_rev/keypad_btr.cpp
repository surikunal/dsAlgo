#include<iostream>
#include<vector>
#include<string>
using namespace std;
string words[] = {".':;", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "ux", "yz", "@$&", "-_;"};
int keypad(string ques, string ans)
{
    if(ques.size() == 0)
    {
        cout<<ans<<endl;
        return 1;
    } 

    char ch = ques[0];
    string roq = ques.substr(1);
    int idx = ch - '0';
    string word = words[idx];
    int count = 0;
    for(int i=0; i<word.size(); i++)
    {
        count += keypad(roq, ans + word[i]);
    }
        // till here it is same 
        // now for the exception 
    if(ques.length() >= 2)
    {
        idx = idx * 10 + (ques[1] - '0');
        if(idx == 10 || idx == 11)
        {
            for(char c : words[idx])
            {
                count += keypad(ques.substr(2), ans + c);
            }
        }
    }
    return count;
}
int permutation(string ques, string ans)
{
    if(ques.length() == 0)
    {
        cout<<ans<<" ";
        return 1;
    }
    int count = 0;
    bool arr[26] = {0};
    for(int i=0; i<ques.length(); i++)
    {
        char ch = ques[i];
        if(arr[ch-'a'] == false)
        {
            string one = ques.substr(0,i);
            string two = ques.substr(i+1);

            arr[ch-'a'] = true;
            count += permutation(one+two, ans+ch);
        }
    }
    return count;
}
int permutationBITS(string ques, string ans)
{
    if(ques.length() == 0)
    {
        cout<<ans<<" ";
        return 1;
    }
    int count = 0;
    // bool arr[26] = {0};
    int isSet = 0;
    for(int i=0; i<ques.length(); i++)
    {
        char ch = ques[i];
        int mark = 1<<(ch-'a');
        // if(arr[ch-'a'] == false)
        if((isSet & mark) == 0)
        {
            string one = ques.substr(0,i);
            string two = ques.substr(i+1);

            count += permutationBITS(one+two, ans+ch);
            // arr[ch-'a'] = true;
            isSet |= mark; 
        }
    }
    return count;
}
void solve()
{
    // cout<<keypad("1011","");
    // cout<<permutation("aba","");
    cout<<permutationBITS("abc","");
}
int main()
{
    solve();    
}
