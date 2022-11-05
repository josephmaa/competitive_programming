#include <vector>
#include <iostream>
#include <cmath>
#include <iomanip>

int main()
{
    std::cout << std::fixed << std::showpoint;
    std::cout << std::setprecision(20);
    double res = 0;
    int p, a, b, c, d, n;
    std::cin >> p >> a >> b >> c >> d >> n;
    double cur_max = 0;
    double cur = 0;
    for (int i = 1; i <= n; i++)
    {
        double cur = p * (std::sin(a * i + b) + std::cos(c * i + d) + 2);
        if (cur > cur_max)
        {
            cur_max = cur;
            continue;
        }
        else
        {
            res = std::max(res, cur_max - cur);
        }
    }
    std::cout << res;
}
