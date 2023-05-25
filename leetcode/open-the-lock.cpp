#include <bits/stdc++.h>

using namespace std;

class Solution
{
 private:
    unordered_map<char, vector<string>> next_iter = {
        {'0', {"1", "9"}}, {'1', {"2", "0"}}, {'2', {"3", "1"}}, {'3', {"4", "2"}},
        {'4', {"5", "3"}}, {'5', {"6", "4"}}, {'6', {"7", "5"}}, {'7', {"8", "6"}},
        {'8', {"9", "7"}}, {'9', {"0", "8"}},
    };

 public:
    vector<string>& nextIter(string current, vector<string>& next)
    {
        next.clear();

        for (int i = 0; i < 4; ++i) {
            for (auto s : next_iter[current[i]]) {
                next.push_back(current.substr(0, i) + s + current.substr(i + 1));
            }
        }

        return next;
    }

    int openLock(vector<string>& deadends, string target)
    {
        unordered_set<string> deadend_set(deadends.begin(), deadends.end());

        string current;
        vector<string> next(8);
        deque<string> queue;
        unordered_map<string, int> prev;

        int res = -1;

        queue.push_back("0000");
        prev["0000"] = 0;

        while (!queue.empty()) {
            current = queue.front();
            queue.pop_front();

            if (current == target)
                break;

            if (deadend_set.find(current) != deadend_set.end())
                continue;

            for (auto n : nextIter(current, next)) {
                if (prev.find(n) == prev.end()) {
                    prev[n] = prev[current] + 1;
                    queue.push_back(n);
                }
            }
        }

        if (prev.find(target) != prev.end()) {
            res = prev[target];
        }

        return res;
    }
};
