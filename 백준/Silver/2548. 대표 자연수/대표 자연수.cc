#include <iostream>
#include <vector>
#include <algorithm> // For std::sort
#include <cmath>     // For std::abs (though not strictly needed after sorting to find median)

int main()
{
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int n;
    std::cin >> n;

    std::vector<int> v(n);

    for (int i = 0; i < n; i++) {
        std::cin >> v[i];
    }

    std::sort(v.begin(), v.end());

    std::cout << v[(n - 1) / 2] << std::endl;

    return 0;
}