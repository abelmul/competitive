#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    vector<int> getPrimesInRange(int left, int right)
    {
        vector<int> primes;

        // Sieve of Eratosthenes

        // check only odds
        vector<bool> is_prime(right / 2 + 1 + (right % 2), true);

        is_prime[0] = false;  // 1 is not a prime

        for (auto i = 3; i * i <= right + (right % 2); i += 2) {
            if (is_prime[i / 2]) {
                auto j = i * i;
                while (j <= right + (right % 2)) {
                    is_prime[j / 2] = false;
                    j += (i << 1);
                }
            }
        }

        int start = left + (left % 2 == 0);

        // add 2 if it is in range
        if (left <= 2 && 2 <= right) {
            primes.push_back(2);
        }

        for (auto i = start; i <= right; i += 2) {
            if (is_prime[i / 2]) {
                primes.push_back(i);
            }
        }

        return primes;
    }

    vector<int> closestPrimes(int left, int right)
    {
        int start, min_diff, size;
        int l, r;
        vector<int> res = {-1, -1};

        vector<int> primes = getPrimesInRange(left, right);

        l = 0;
        r = 1;
        size = primes.size();
        min_diff = INT_MAX;

        while (r < size) {
            if (min_diff > primes[r] - primes[l]) {
                min_diff = primes[r] - primes[l];
                res[0] = primes[l];
                res[1] = primes[r];
            }

            ++l;
            ++r;
        }

        return res;
    }
};
