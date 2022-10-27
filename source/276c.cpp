#include <vector>
#include <iostream>
#include <utility>

int main()
{
    int n, q;
    std::cin >> n >> q;
    std::vector<int> arr;
    for (int i = 0; i < n; ++i)
    {
        int tmp;
        std::cin >> tmp;
        arr.push_back(tmp);
    }

    std::vector<std::pair<int, int>> qs;
    for (int i = 0; i < q; ++q)
    {
        int tmp1, tmp2;
        std::cin >> tmp1, tmp2;
        qs.push_back(std::make_pair(tmp1, tmp2));
    }

    str
}