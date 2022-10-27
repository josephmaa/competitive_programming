#include <iostream>
#include <vector>
#include <algorithm>

void build(int a[], std::vector<int> &t, int v, int tl, int tr)
{
    if (tl == tr)
    {
        t[v] = a[tl];
    }
    else
    {
        int tm = (tl + tr) / 2;
        build(a, t, v * 2, tl, tm);
        build(a, t, v * 2 + 1, tm + 1, tr);
        t[v] = t[v * 2] + t[v * 2 + 1];
    }
}

int min_val(std::vector<int> &t, int v, int tl, int tr, int l, int r)
{
    if (l > r)
    {
        return 0;
    }
    if (l == tl && r == tr)
    {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return std::min(min_val(t, v * 2, tl, tm, l, std::min(r, tm)), min_val(t, v * 2 + 1, tm + 1, tr, std::max(l, tm + 1), r));
}

void update(std::vector<int> &t, int v, int tl, int tr, int pos, int new_val)
{
    if (tl == tr)
    {
        t[v] = new_val;
    }
    else
    {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
        {
            update(t, v * 2, tl, tm, pos, new_val);
        }
        else
        {
            update(t, v * 2 + 1, tm + 1, tr, pos, new_val);
        }
        t[v] = t[v * 2] + t[v * 2 + 1];
    }
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> t{4 * n};
}
