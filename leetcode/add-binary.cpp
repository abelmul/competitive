#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    string addBinary(string a, string b)
    {
        int carry = 0;
        string res;

        auto a_size = a.size(), b_size = b.size(), m_size = min(a_size, b_size);

        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        auto sum_and_push = [](char a, char b, int& carry, string& res) {
            auto s = (a == '1') + (b == '1') + carry;

            switch (s) {
                case 0:
                case 2:
                    res.push_back('0');
                    break;
                case 1:
                case 3:
                    res.push_back('1');
                    break;
            }

            carry = (s > 1);
        };

        for (auto i = 0; i < m_size; ++i) {
            sum_and_push(a[i], b[i], carry, res);
        }

        for (auto i = m_size; i < a_size; ++i) {
            sum_and_push(a[i], '0', carry, res);
        }

        for (auto i = m_size; i < b_size; ++i) {
            sum_and_push(b[i], '0', carry, res);
        }

        if (carry) {
            res.push_back('1');
        }

        reverse(res.begin(), res.end());

        return res;
    }
};
