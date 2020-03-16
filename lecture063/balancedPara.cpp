#include <iostream>
#include <stack>
using namespace std;

bool balancedBrackets(string &str)
{
    stack<char> st;
    for (int i = 0; i < str.size(); i++)
    {
        char ch = str[i];
        if (ch == '(' || ch == '{' || ch == '[' || ch == '<')
            st.push(ch);

        else if (ch == '}' && st.top() != '{')
            return false;
        else if (ch == '>' && st.top() != '<')
            return false;
        else if (ch == ')' && st.top() != '(')
            return false;
        else if (ch == ']' && st.top() != '[')
            return false;

        else
            st.pop();
    }
    return st.size() == 0;
}

int main(int args, char **argv)
{
    string str = "{{{{}}}()[]}{";
    cout << (boolalpha) << balancedBrackets(str) << endl;
}