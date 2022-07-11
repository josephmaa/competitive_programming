#include <iostream>
#include <vector>
using namespace std;

bool helper(vector<int> &num, int a)
{
    int n = num.size();
    int i = 0;
    while (a)
    {
        if (i < n and a % 10 == num[i])
        {
            i++;
        }
        else if (a % 10 == 4 or a % 10 == 7)
        {
            return false;
        }
        a /= 10;
    }
    return (i == n);
}

int main()
{
    int a;
    int b;
    cin >> a >> b;

    vector<int> num;
    while (b)
    {
        num.push_back(b % 10);
        b /= 10;
    }

    // The returned value must be strictly greater than a.
    a++;
    while (true)
    {
        if (helper(num, a))
        {
            cout << a;
            break;
        }
        a += 1;
    }
}