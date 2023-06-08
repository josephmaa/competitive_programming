#include <string>
#include <iostream>

int main()
{
    std::string a, b;
    std::cin >> a >> b;

    if (a.size() != b.size())
    {
        std::cout << std::max(a.size(), b.size());
    }
    else
    {
        if (a == b)
        {
            std::cout << -1 << std::endl;
        }
        else
        {
            std::cout << a.size() << std::endl;
        }
    }
}