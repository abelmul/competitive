#include <bits/stdc++.h>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::cin >> n;

    std::unordered_set<int> s;

    for (int i = 0; i < n; ++i) s.insert(i + 1);

    int x;
    for (int i = 0; i < n - 1; ++i) {
        std::cin >> x;
        s.erase(x);
    }

    std::cout << *s.cbegin();

    return 0;
}
