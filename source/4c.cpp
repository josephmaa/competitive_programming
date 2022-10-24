#include <vector>
#include <map>
#include <string>
#include <iostream>

int main()
{
    std::map<std::string, int> seen;
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        std::string q;
        std::cin >> q;
        if (not seen.count(q))
        {
            std::cout << "OK" << std::endl;
            seen[q] = 0;
        }
        else
        {
            std::cout << q + std::to_string(seen[q] + 1) << std::endl;
            seen[q]++;
        }
    }
}