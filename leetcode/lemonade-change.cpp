#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    bool lemonadeChange(vector<int>& bills)
    {
        int five = 0, ten = 0;

        for (auto b : bills) {
            if (b == 10) {
                if (five == 0)
                    return false;
                --five;
            }

            else if (b == 20) {
                if (five > 0 && ten > 0) {
                    --five;
                    --ten;
                } else if (five >= 3) {
                    five -= 3;
                } else {
                    return false;
                }
            }

            five += (b == 5);
            ten += (b == 10);
        }

        return true;
    }
};
