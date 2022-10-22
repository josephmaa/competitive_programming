#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (auto i = 0; i < n; i++)
    {

        int sz;
        cin >> sz;

        // Initialize set.
        set<int> s;
        for (int m = 0; m < sz; ++m)
        {
            s.insert(s.end(), m);
        }

        vector<int> arr(sz, 0);
        // Initialize range.
        iota(arr.begin(), arr.end(), 0);
        sort(arr.begin(), arr.end(), greater<int>());

        // Initialize res array.
        int res[sz];

        for (auto j = 0; j < arr.size(); j++)
        {
            int k = ceil(sqrt(arr[j]));
            int l = pow(k, 2) - pow(arr[j], 2);
            if (s.find(l) == s.end())
            {
                cout << -1 << endl;
                return 0;
            }
            else
            {
                s.erase(l);
                res[l] = arr[j];
            }
        }

        for (int m = 0; m < sz; ++m)
        {
            cout << res[m] << " ";
        }

        cout << endl;
    }
}