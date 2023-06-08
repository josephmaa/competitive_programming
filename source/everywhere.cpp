#include <set>
#include <iostream>
#include <string>

int main()
{
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int c;
        std::cin >> c;
        std::set<std::string> m;
        for (int j = 0; j < c; ++j)
        {
            std::string s;
            std::cin >> s;
            m.insert(s);
        }
        std::cout << m.size() << std::endl;
    }
}