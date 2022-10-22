#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<char> res;
    int n;
    cin >> n;

    while (n)
    {
        char num = '0' + n % 2;
        res.push_back(num);
        n /= 2;
    }

    copy(res.rbegin(), res.rend(), ostream_iterator<char>(cout, ""));

    cout << endl;
}
