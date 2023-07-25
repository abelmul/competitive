#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    vector<int> asteroidCollision(vector<int>& asteroids)
    {
        vector<int> st;

        for (auto a : asteroids) {
            auto insert = true;
            while (!st.empty() && st.back() > 0 && a < 0) {
                if (st.back() < abs(a)) {
                    st.pop_back();
                } else if (st.back() == abs(a)) {
                    st.pop_back();
                    insert = false;
                    break;
                } else {
                    insert = false;
                    break;
                }
            }

            if (insert) {
                st.push_back(a);
            }
        }

        return st;
    }
};
