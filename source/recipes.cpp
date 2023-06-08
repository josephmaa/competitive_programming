#include <iostream>
#include <vector>
#include <tuple>
#include <string>
#include <iomanip>

int main()
{
    int n;
    std::cin >> n;

    int r;
    double p;
    double d;
    double unit;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> r >> p >> d;
        std::vector<std::tuple<std::string, double, double>> v;
        for (int j = 0; j < r; ++j)
        {
            std::string a;
            double b, c;
            std::cin >> a >> b >> c;
            if (c == 100.0)
            {
                unit = d / p * b;
            }
            std::tuple<std::string, double, double> t = std::make_tuple(a, b, c);
            v.push_back(t);
        }

        std::cout << "Recipe # " << i + 1 << std::endl;
        for (int k = 0; k < r; ++k)
        {
            std::cout << std::fixed << std::setprecision(1) << std::get<0>(v[k]) << " " << unit * std::get<2>(v[k]) * 0.01 << std::endl;
        }
        std::cout << "----------------------------------------" << std::endl;
    }
}