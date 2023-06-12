#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    string frequencySort(string s)
    {
        unordered_map<char, int> counter;
        priority_queue<pair<int, char>> heap;

        string res;

        res.reserve(s.size());

        for (auto c : s) {
            ++counter[c];
        }

        for (auto &[k, v] : counter) {
            heap.push({v, k});
        }

        while (!heap.empty()) {
            for (auto _ = 0; _ < heap.top().first; ++_) res.push_back(heap.top().second);
            heap.pop();
        }

        return res;
    }
};
