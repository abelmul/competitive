#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    bool splitString(string s)
    {
        auto length = s.size();

        function<bool(int, long long, int)> backtrack = [&](int l, long long prev = -1,
                                                            int splits = 0) {
            long long tmp;

            if (l == length) {
                if (splits < 2) {
                    return false;
                }
                return true;
            }

            for (int i = l; i < length; ++i) {
                try {
                    tmp = stoll(s.substr(l, i - l + 1));

                    if (prev != -1 && prev - tmp != 1) {
                        continue;
                    }

                    if (backtrack(i + 1, tmp, splits + 1))
                        return true;

                } catch (...) {
                    // catch overflow
                    break;
                }
            }

            return false;
        };

        return backtrack(0, -1, 0);
    };
};
