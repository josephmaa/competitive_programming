#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int m;
        cin >> m;
        int rz = 0;
        vector<int> tmp(m, 0);
        for (int j = 0; j < m; ++j)
        {
            cin >> tmp[j];
            if (j != 0 and tmp[j] % 2 == tmp[j - 1] % 2)
            {
                rz++;
            }
        }
        cout << rz << endl;
    }
}