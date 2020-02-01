#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isBalancedParenthesis(string str)
{
    vector<char> stack;
    char s;

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[')
        {
            stack.push_back(str[i]);
        }

        else
        {
            if (str.empty())
                return false;

            switch (stack[i])
            {
            case ')':
                s = stack.back();
                stack.pop_back();
                if (s == '{' || s == '[')
                    return false;
                break;
            
            case '}':
                s = stack.front();
                stack.pop_back();
                if (s == '(' || s == '[')
                    return false;
                break;

            case ']':
                s = stack.front();
                stack.pop_back();
                if (s == '{' || s == '(')
                    return false;
                break;
            
            default:
                break;
            }
        }
    } 

    if (stack.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main(int args, char **argv)
{
    string str = "{()}[]";
    // string str = "(((((())))))";
    // cin >> str;
    cout << (boolalpha) << isBalancedParenthesis(str);
    return 0;
}
