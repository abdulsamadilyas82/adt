#include <iostream>
#include "stack.h"
using namespace std;


bool isBalanced(string);
void infixToPostfix(string);
void reverseString(string&);
string removeConsecutiveDuplicates(string);

int main()
{
    string s = "aabddyygg";
    
    cout << removeConsecutiveDuplicates(s);

    return 0;
}

void infixToPostfix(string s)
{
    stack<char> s2(10);

    for (int i = 0; i < size(s); i++)
    {
        if (s[i] >= 'A' && s[i] <= 'z' || s[i] >= 0 && s[i] <= 9)
        {
            cout << s[i];
        }

        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
        {
            if (s[i] == '*' || s[i] == '/')
            {
                s2.push(s[i]);
            }

            if (s[i] == '+' || s[i] == '-')
            {
                if (s2.Top() == '/' || s2.Top() == '*')
                {
                    while (s2.Top() == '/' || s2.Top() == '*')
                    {
                        cout << s2.Top();
                        s2.pop();
                    }

                    s2.push(s[i]);
                }

                else
                {
                    s2.push(s[i]);
                }
            }
        }

        

    }

    while (!s2.isEmpty())
    {
        cout << s2.Top();
        s2.pop();
    }
}

bool isBalanced(string s)
{
    stack<char> s1(10);

    for (int i = 0; i < size(s); i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            s1.push(s[i]);
        }

        if (s[i] == ')' || s[i] == '}' || s[i] == ']')
        {
            if (s[i] == ')')
            {
                if (s1.Top() != '(')
                {
                    return false;
                }

                else
                {
                    s1.pop();
                }

            }

            if (s[i] == '}')
            {
                if (s1.Top() != '{')
                {
                    return false;
                }

                else
                {
                    s1.pop();
                }

            }

            if (s[i] == ']')
            {
                if (s1.Top() != '[')
                {
                    return false;
                }

                else
                {
                    s1.pop();
                }

            }
        }

        
    }

    if (s1.isEmpty())
    {
        return true;
    }

    else
    {
        return false;
    }
}

void reverseString(string &str)
{
    stack<char> s(10);

    for (int i = 0; i < size(str); i++)
    {
        s.push(str[i]);
    }

    
    for (int i = 0; !s.isEmpty(); i++)
    {
        str[i] = s.Top();
        s.pop();
    }

}

string removeConsecutiveDuplicates(string str)
{
    if (str.size() == 1)
    {
        return str;
    }

    stack<char>s1(10);

    s1.push(str[0]);

    for (int i = 1; i < str.size(); i++)
    {
        if (str[i] != s1.Top())
        {
            s1.push(str[i]);
        }
    }

    str = "";
    while (!s1.isEmpty())
    {
        str += s1.Top();
        s1.pop();
    }

    reverseString(str);

    return str;
}