#include <iostream>
#include <vector>

int main()
{
    int arr[4];
    for (int i = 0; i < 4; ++i)
    {
        std::cin >> arr[i];
    }
    std::vector<int> v(4001);

    for (int i = 1; i < arr[0] + 1; ++i)
    {
        for (int j = 1; j < 4; ++j)
        {
            if ((i - arr[j] == 0) or ((i - arr[j] >= 0) and (v[i - arr[j]] > 0)))
            {
                v[i] = std::max(v[i], v[i - arr[j]] + 1);
            }
        }
    }
    std::cout << v[arr[0]];
}