#include <iostream>
#include <string>
#include <vector>
#include <numeric>

int main()
{
    std::string a, b;
    std::cin >> a >> b;

    std::vector<int> primes{2, 3, 5, 7};
    std::vector<int> nums(9);

    for (auto &s : b)
    {
        int num = s - '0';
        while (num != 1)
        {
            for (auto p : primes)
            {
                if (num % p == 0)
                {
                    nums[p - 1]++;
                }
            }
        }
    }

    std::string res = "";
    for (int i = 8; i >= 0; --i)
    {
        res += std::string(nums[i], '0' + i + 1);
    }
    std::cout << res;
}