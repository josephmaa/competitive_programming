#include <iostream>
using namespace std;

int main()
{
    int cases;
    cin >> cases;

    int a, b, c, d;
    int bb, cc, dd;
    for (int i = 0; i < cases; i++)
    {
        cin >> a >> b >> c >> d;
        bb = b > a;
        cc = c > a;
        dd = d > a;
        cout << bb + cc + dd << endl;
    }
}