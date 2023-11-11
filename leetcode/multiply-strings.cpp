#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    string add(string num1, string num2)
    {
        string res;

        const auto num1_size = num1.size(), num2_size = num2.size();

        int sum;
        int carry = 0;
        int min_size = min(num1_size, num2_size);
        int i;

        res.reserve(max(num1.size(), num2.size()));

        for (i = 0; i < min_size; ++i) {
            sum = (num1[num1_size - i - 1] - '0') + (num2[num2_size - i - 1] - '0') + carry;
            carry = (sum >= 10);
            if (sum >= 10) {
                sum -= 10;
            }
            res.push_back('0' + sum);
        }

        for (int j = i; j < num1_size; ++j) {
            sum = (num1[num1_size - j - 1] - '0') + carry;
            carry = (sum >= 10);
            if (sum >= 10) {
                sum -= 10;
            }
            res.push_back('0' + sum);
        }

        for (int j = i; j < num2_size; ++j) {
            sum = (num2[num2_size - j - 1] - '0') + carry;
            carry = (sum >= 10);
            if (sum >= 10) {
                sum -= 10;
            }
            res.push_back('0' + sum);
        }

        if (carry) {
            res.push_back('0' + carry);
        }

        while (!(res.size() <= 1) && res.back() == '0') {
            res.pop_back();
        }

        reverse(res.begin(), res.end());

        return res;
    }

    string multiply(string num1, string num2)
    {
        string res = "";
        string multiple;

        int m, carry;

        for (int i = num1.size() - 1; i >= 0; --i) {
            multiple.clear();
            carry = 0;

            for (int k = num1.size() - 1; k > i; --k) {
                multiple.push_back('0');
            }

            for (int j = num2.size() - 1; j >= 0; --j) {
                m = (num1[i] - '0') * (num2[j] - '0') + carry;

                carry = m / 10;
                m = m % 10;

                multiple.push_back('0' + m);
            }

            if (carry) {
                multiple.push_back('0' + carry);
            }

            reverse(multiple.begin(), multiple.end());

            res = add(res, multiple);
        }

        return res;
    }
};
