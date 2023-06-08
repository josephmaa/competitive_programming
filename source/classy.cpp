#include <map>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

int main()
{
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int m;
        std::cin >> m;
        std::map<std::string, std::vector<std::string>> l;
        std::string s;
        std::vector<std::string> line;
        for (int j = 0; j < m; ++j)
        {
            std::cin >> s;
            line.push_back(s);
        }

        std::vector<int> res;
        int k = 0;
        std::map<std::string, std::vector<std::string>> ll;
        for (auto &pr : l)
        {
            std::stringstream t(pr.second[1]);
            std::string segment;
            std::vector<std::string> seg_list;
            while (std::getline(t, segment, '-'))
                seg_list.push_back(segment);
            ll[pr.first] = seg_list;
            k = std::max(k, (int)seg_list.size());
        }

        std::map<std::string, std::vector<std::string>> lm;
        std::vector<std::string> res;
        int z = 0;
        for (auto &pr : ll)
        {
            std::vector<std::string> fn;
            fn.insert(fn.begin(), k - pr.second.size(), "middle");
            lm[pr.first] = fn;
            res.push_back(pr.first);
            z++;
        }

        std::sort(res.begin(), res.end(), [&](const std::string &a, const std::string &b)
                  { return lm[a] < lm[b]; });

        for (auto &s : res)
        {
            std::cout << s << std::endl;
        }
    }
}