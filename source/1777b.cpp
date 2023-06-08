#include <iostream>
using namespace std;

long long factorial(int n)
{
    long long res = 1;
    for (int i = 2; i <= n; ++i)
    {
        res *= i;
        res %= 1000000007;
    }
    return res % 1000000007;
}

int main()
{
    int i;
    cin >> i;
    for (int j = 0; j < i; ++j)
    {
        long long k;
        cin >> k;
        cout << ((k * (k - 1)) % static_cast<long long>(1e9 + 7) * factorial(k)) % static_cast<long long>(1e9 + 7) << endl;
    }
}