class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        auto g_size = g.size(), s_size = s.size();

        sort(g.rbegin(), g.rend());
        sort(s.rbegin(), s.rend());

        int g_i = 0, s_i = 0;

        while(g_i < g_size && s_i < s_size) {
            if (s[s_i] >= g[g_i]) {
                ++s_i;
            }
            ++g_i;
        }

        return s_i;
    }
};