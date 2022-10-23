#include <iostream>
using namespace std;

int main()
{
    int a;
    cin >> a;
    int num = 1;

    while (1)
    {
        int s = 0;
        int tmp = num;
        while (tmp)
        {
            s = s + tmp % 10;
            tmp /= 10;
        }

        if (s == 10)
        {
            a -= 1;
        }

        if (a == 0)
        {
            cout << num;
            break;
        }

        num = num + 1;
    }
    return 0;
}