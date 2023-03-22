#include <bits/stdc++.h>

int main()
{
    long long n;

    std::ios_base::sync_with_stdio(false);

    std::cin >> n;

    while (n != 1) {
        std::cout << n << " ";
        if (n % 2 == 0) {
            n /= 2;
        } else {
            n = (n * 3) + 1;
        }
    }

    std::cout << n << " ";

    return 0;
}
