#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    int countPrimes(int n)
    {
        // Sieve of Eratosthenes

        // only check odd numbers
        vector<bool> is_prime(n / 2 + 1, true);
        int res = (n > 2);

        is_prime[0] = false;  // 1 is not a prime

        for (auto i = 3; i * i <= n; i += 2) {
            if (is_prime[i / 2]) {
                auto j = i * i;
                while (j <= n) {
                    is_prime[j / 2] = false;
                    j += (i << 1);
                }
            }
        }

        for (auto i = 0; i < n / 2; ++i) {
            res += is_prime[i];
        }

        return res;
    }
};
