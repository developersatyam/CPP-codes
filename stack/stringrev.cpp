#include <iostream>
#include <string>
using namespace std;
void reversal(string str)
{
    int l = str.length();
    string word = "", temp = "";
    for (int i = 0; i < l; i++)
    {
        char ch = str.at(i);
        if (ch != '.')
            word = word + ch;
        else
        {
            temp = word + "." + temp;
            word = "";
        }
    }
   temp = word + "." + temp;
   l=temp.length();
   temp=temp.substr(0,l-1);
    cout << temp << endl;
}
int main()
{
    //code
    int n;
    string str;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        reversal(str);
    }
    return 0;
}