#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>
#include <stdio.h>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        std::vector<int> votes;
        int m;
        std::cin >> m;
        for (int j = 0; j < m; ++j)
        {
            int tmp;
            std::cin >> tmp;
            votes.push_back(tmp);
        }

        int tot = std::reduce(votes.begin(), votes.end());
        int mx = 0;
        int idx;
        bool w = false;
        for (int j = 0; j < m; ++j)
        {
            if (votes[j] > mx)
            {
                mx = votes[j];
                idx = j;
                w = true;
            }
            else if (votes[j] == mx)
            {
                w = false;
            }
        }
        int majority = tot / 2 + 1;
        int winner = tot / m + 1;
        if (mx >= majority && w)
        {
            std::cout << "majority winner " << idx + 1 << std::endl;
        }
        else if (mx >= winner && w)
        {
            std::cout << "minority winner " << idx + 1 << std::endl;
        }
        else
        {
            std::cout << "no winner " << std::endl;
        }
    }
}
