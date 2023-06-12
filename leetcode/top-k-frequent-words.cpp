#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    vector<string> topKFrequent(vector<string>& words, int k)
    {
        vector<string> res;

        function<bool(const pair<int, string>&, const pair<int, string>&)> compare =
            [](const pair<int, string>& lhs, const pair<int, string>& rhs) {
                return lhs.first > rhs.first || (lhs.first == rhs.first && lhs.second < rhs.second);
            };

        unordered_map<string, int> counter;
        priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(compare)> pq(compare);

        res.reserve(k);

        for (auto w : words) {
            ++counter[w];
        }

        for (auto& [key, v] : counter) {
            pq.push({v, key});

            while (pq.size() > k) {
                pq.pop();
            }
        }

        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        reverse(res.begin(), res.end());

        return res;
    }
};
