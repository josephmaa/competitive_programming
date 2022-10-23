#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    int t;
    cin >> t;

    int n;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        unordered_map<int, int> m;
        int a;
        for (int j = 0; j < n; j++)
        {
            cin >> a;
            if (m.count(a))
            {
                m[a] += 1;
            }
            else
            {
                m[a] = 1;
            }
        }

        int repeats = 0;
        for (auto const &[key, val] : m)
        {
            if (val != 1)
            {
                repeats += val - 1;
            }
        }
        cout << n - (((repeats + 1) / 2) * 2) << endl;
    }
}