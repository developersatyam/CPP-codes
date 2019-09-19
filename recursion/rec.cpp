#include <iostream>
using namespace std;
int mem[100];
int sunFact(int num)
{
    if (num == 0)
        return 1;
    int res = num * sunFact(num - 1);
    return res;
}
int fibSum(int n)
{
    if (n <= 1)
        return n;
    if (mem[n] != -1)
        return mem[n];
    mem[n] = fibSum(n - 1) + fibSum(n - 2);
    return mem[n];
}
int main()
{
    for (int i = 0; i < 100; i++)
        mem[i] = -1;
    cout << sunFact(6) << endl;
    cout << fibSum(99) << endl;
    return 0;
}