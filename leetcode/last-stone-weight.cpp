#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    int lastStoneWeight(vector<int>& stones)
    {
        int one, two;
        make_heap(stones.begin(), stones.end());

        while (!stones.empty()) {
            if (stones.size() == 1) {
                return stones.front();
            }
            one = stones.front();
            pop_heap(stones.begin(), stones.end());
            stones.pop_back();

            two = stones.front();
            pop_heap(stones.begin(), stones.end());
            stones.pop_back();

            if (one != two) {
                stones.push_back(one - two);
                push_heap(stones.begin(), stones.end());
            }
        }

        return 0;
    }
};
