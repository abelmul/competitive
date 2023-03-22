#include <bits/stdc++.h>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    long long n, res = 0;
    std::cin >> n;

    int prev, current;
    std::cin >> prev;

    for (long long i = 1; i < n; ++i) {
        std::cin >> current;

        if (prev > current) {
            res += prev - current;
            current = prev;
        }
        prev = current;
    }

    std::cout << res;
    return 0;
}
