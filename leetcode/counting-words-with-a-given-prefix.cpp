#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    int prefixCount(vector<string>& words, string pref)
    {
        int count = 0;

        for (auto w : words) {
            int i = 0;
            for (auto c : pref) {
                if (i >= w.size() || c != w[i])
                    break;
                ++i;
            }
            count += (i <= w.size() && i >= pref.size());
        }

        return count;
    }
};
