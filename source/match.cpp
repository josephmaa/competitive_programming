#include <bits/stdc++.h>
using namespace std;
#define ll long long
int MOD = 1000000007;

ll countSubseqRec(int i, int j, int start, const string &searchSpace, const string &target)
{
    if (i > start and j == 0)
    {
        return 0;
    }
    if (j == target.length())
    {
        return 1;
    }

    if (i > start + (searchSpace.length() / 2) - 1)
    {
        return 0;
    }

    ll match = 0;
    if (searchSpace[i] == target[j])
    {
        match += countSubseqRec(i + 1, j + 1, start, searchSpace, target);
    }

    return match + countSubseqRec(i + 1, j, start, searchSpace, target);
}

ll countSubseq(int start, const string &searchSpace, const string &target)
{
    return countSubseqRec(start, 0, start, searchSpace, target) % MOD;
}

void solve()
{
    string p;
    cin >> p;
    string s;
    cin >> s;
    set<char> charSet{s.begin(), s.end()};
    string searchSpace;
    for (auto &c : p)
    {
        if (s.find(c) != -1)
        {
            searchSpace += c;
        }
    }
    ll ans = 0;
    searchSpace += searchSpace;
    for (int i = 0; i < searchSpace.length() / 2; ++i)
    {
        if (searchSpace[i] == s[0])
        {
            ans += countSubseq(i, searchSpace, s);
            ans %= MOD;
        }
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}