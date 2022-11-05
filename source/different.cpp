#include <iostream>
#include <cmath>
#include <string>
#include <sstream>

int main()
{
    unsigned long long m, n;
    std::string line;
    while (std::getline(std::cin, line))
    {
        std::istringstream ss(line);
        ss >> m >> n;
        if (m > n)
        {
            std::cout << m - n << std::endl;
        }
        else
        {
            std::cout << n - m << std::endl;
        }
    }
}