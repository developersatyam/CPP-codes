#include <iostream>
#include <string>
#include <stack>
using namespace std;
bool balanceChecker(string expr)
{
    stack<char> s;
    char x;
    for (int i = 0; i < expr.length(); i++)
    {
        if (expr[i] == '(' || expr[i] == '[' || expr[i] == '{')
        {
            s.push(expr[i]);
            continue;
        }
        if (s.empty())
            return false;

        switch (expr[i])
        {
        case ')':
            x = s.top();
            s.pop();
            if (x == '{' || x == '[')
                return false;
            break;

        case '}':
            x = s.top();
            s.pop();
            if (x == '(' || x == '[')
                return false;
            break;

        case ']':
            x = s.top();
            s.pop();
            if (x == '(' || x == '{')
                return false;
            break;
        }
    }
    return (s.empty());
}
int main()
{
    //code
    int n, i;
    string str;
    cin >> n;
    string arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        arr[i] = str;
    }
    int k = 0;
    while (k < n)
    {
        bool check = balanceChecker(arr[k]);
        if (check)
            cout << "balanced" << endl;
        else
            cout << "not balanced" << endl;
        k++;
    }
    return 0;
}