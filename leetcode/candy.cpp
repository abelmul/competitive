#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    int candy(vector<int>& ratings)
    {
        auto size = ratings.size();
        vector<int> candies(size, 1);

        for (auto i = 1; i < size; ++i) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }

        for (int j = size - 2; j >= 0; --j) {
            if (ratings[j] > ratings[j + 1] && candies[j + 1] >= candies[j]) {
                candies[j] = candies[j + 1] + 1;
            }
        }

        return accumulate(candies.begin(), candies.end(), 0);
    }
};
