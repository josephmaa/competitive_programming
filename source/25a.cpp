#include <iostream>
#include <map>

int main()
{
    int n;
    std::cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i)
    {
        std::cin >> arr[i];
    }
    int odd = 0;
    int even = 0;
    for (int j = 0; j < 3; ++j)
    {
        if (arr[j] % 2 == 0)
        {
            even++;
        }
        else
        {
            odd++;
        }
    }
    for (int k = 0; k < n; ++k)
    {
        if (odd > even and arr[k] % 2 == 0)
        {
            std::cout << k + 1;
            break;
        }
        else if (odd < even and arr[k] % 2 == 1)
        {
            std::cout << k + 1;
            break;
        }
    }
}