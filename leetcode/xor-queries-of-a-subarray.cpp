#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries)
    {
        auto size = arr.size();
        auto queries_size = queries.size();
        vector<int> prefix_sum = vector<int>(size + 1);
        vector<int> answer = vector<int>(queries.size());

        for (int i = 1; i < size + 1; ++i) {
            prefix_sum[i] = prefix_sum[i - 1] ^ arr[i - 1];
        }

        for (int i = 0; i < queries_size; ++i) {
            answer[i] =
                prefix_sum[queries[i][0]] ^ prefix_sum[queries[i][1] + 1];
        }

        return answer;
    }
};
