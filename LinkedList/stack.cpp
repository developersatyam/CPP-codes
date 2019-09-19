#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;
stack<char> stac;
void print()
{
    while (!stac.empty())
    {
        cout << stac.top();
        stac.pop();
    }
}

int main()
{
    string str;
    cin >> str;
    int l=str.length();
    for(int i=0;i<l;i++){
        char ch=str.at(i);
        stac.push(ch);
    }
    print();
    return 0;
}