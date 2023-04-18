#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        map<int, int> nu;
        multimap<int, int> m;

        auto iterpair = m.equal_range(0);
        auto it = iterpair.first;

        vector<int> res;

        for (auto n : nums) {
            iterpair = m.equal_range(-nu[n]);
            it = iterpair.first;

            for (; it != iterpair.second; ++it) {
                if (it->second == n) {
                    m.erase(it);
                    break;
                }
            }

            ++nu[n];
            m.insert({-nu[n], n});
        }

        it = m.begin();
        while (k > 0) {
            res.push_back(it->second);
            ++it;
            k -= 1;
        }

        return res;
    }
};
