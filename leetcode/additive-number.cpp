#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    bool isAdditiveNumber(string num)
    {
        auto size = num.size();

        function<bool(int, long long, long long, int)> backtrack = [&](int l, long long prev,
                                                                       long long penu, int added) {
            if (l >= size) {
                return added >= 3;
            }

            long long current;
            for (auto i = l; i < size; ++i) {
                if (num[l] == '0' && i - l + 1 > 1) {
                    // leading zero
                    break;
                }

                ++added;
                try {
                    current = stoll(num.substr(l, i - l + 1));
                    if ((prev == -1 || penu == -1) && backtrack(i + 1, current, prev, added)) {
                        return true;
                    } else if (prev != -1 && penu != -1) {
                        if (prev + penu == current && backtrack(i + 1, current, prev, added)) {
                            return true;
                        } else if (prev + penu < current) {
                            break;
                        }
                    }
                } catch (...) {
                }
                --added;
            }

            return false;
        };

        return backtrack(0, -1, -1, 0);
    }
};
