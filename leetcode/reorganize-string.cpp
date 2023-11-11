#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    string reorganizeString(string s)
    {
        auto size = s.size();

        unordered_map<char, int> counter;
        priority_queue<pair<int, char>> pq;

        pair<int, char> first, second;

        for (auto c : s) {
            ++counter[c];
        }

        for (auto &[k, v] : counter) {
            pq.push({v, k});
        }

        s.clear();

        while (!pq.empty()) {
            first = pq.top();
            pq.pop();

            if (s.empty() || first.second != s.back()) {
                s.push_back(first.second);
                --first.first;
            } else if (!pq.empty()) {
                second = pq.top();
                pq.pop();
                s.push_back(second.second);
                --second.first;

                if (second.first > 0) {
                    pq.push(second);
                }
            } else {
                return "";
            }

            if (first.first > 0) {
                pq.push(first);
            }
        }

        return s;
    }
};
