#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    bool isValidInteger(const string& s, int i)
    {
        if (s.size() > 1 && s[0] == '0') {
            // leading 0
            return false;
        }

        return i >= 0 && i <= 255;
    }

    vector<string> restoreIpAddresses(string s)
    {
        auto length = s.size();
        vector<string> res;
        vector<int> cur;

        function<void(int, vector<int>)> backtrack = [&](int l, vector<int> cur) {
            if (cur.size() > 4) {
                return;
            }

            if (l == length) {
                if (cur.size() == 4) {
                    char buf[16];
                    snprintf(buf, sizeof buf, "%d.%d.%d.%d", cur[0], cur[1], cur[2], cur[3]);
                    res.push_back(buf);
                }
                return;
            }

            if (length - l >= 1) {
                cur.push_back(stoi(s.substr(l, 1)));
                backtrack(l + 1, cur);
                cur.pop_back();
            }

            if (length - l >= 2) {
                auto tmp = s.substr(l, 2);
                auto i = stoi(tmp);
                if (isValidInteger(tmp, i)) {
                    cur.push_back(i);
                    backtrack(l + 2, cur);
                    cur.pop_back();
                }
            }

            if (length - l >= 3) {
                auto tmp = s.substr(l, 3);
                auto i = stoi(tmp);
                if (isValidInteger(tmp, i)) {
                    cur.push_back(i);
                    backtrack(l + 3, cur);
                    cur.pop_back();
                }
            }
        };

        if (s.size() <= 12)
            backtrack(0, cur);

        return res;
    }
};
