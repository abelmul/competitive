#include <bits/stdc++.h>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::string dna;

    std::cin >> dna;

    int max_length = 0;
    int l = 0;
    char current = 'Z';
    int length = dna.size();

    for (auto i = 0; i < length; ++i) {
        if (dna[i] != current) {
            l = i;
            current = dna[i];
            max_length = std::max(max_length, 1);
        } else {
            max_length = std::max(max_length, i - l + 1);
        }
    }

    std::cout << max_length;

    return 0;
}
