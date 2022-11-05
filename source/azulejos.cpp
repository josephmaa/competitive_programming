#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <sstream>
#include <string>
#include <numeric>
#include <functional>

int main()
{
    std::map<int, std::vector<int>> m;
    std::map<int, std::vector<int>> o;
    std::vector<int> back_price, back_height, front_price, front_height;
    std::vector<std::vector<int>> v{back_price, back_height, front_price, front_height};
    int n;
    std::cin >> n;
    std::string line;
    for (int i = 0; i < 4; ++i)
    {
        std::getline(std::cin, line);
        std::istringstream is(line);
        for (auto &vec : v)
        {
            vec.assign(std::istream_iterator<int>(is), std::istream_iterator<int>());
        }
    }

    for (int i = 0; i < n; ++i)
    {
        m[back_price[i]].push_back(i);
        o[front_price[i]].push_back(i);
    }

    std::vector<int> res1;
    std::vector<int> res2;
    auto i1 = m.begin();
    auto i2 = o.begin();
    for (int i = 0; i < m.size(); ++i)
    {
        std::sort(i1->second.begin(), i1->second.end(), [&](const int &a, const int &b) -> bool
                  { return back_height[a] < back_height[b]; });
        res1.insert(res1.end(), i1->second.begin(), i1->second.end());
    }
    for (int i = 0; i < o.size(); ++i)
    {
        std::sort(i2->second.begin(), i2->second.end(), [&](const int &a, const int &b) -> bool
                  { return front_height[a] < front_height[b]; });
        res2.insert(res2.end(), i2->second.begin(), i2->second.end());
    }
    std::cout << std::inner_product(res1, res2, true, std::logical_and<bool>(), std::less<int>());
}