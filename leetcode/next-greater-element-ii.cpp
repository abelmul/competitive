class Solution
{
 public:
    vector<int> nextGreaterElements(vector<int>& nums)
    {
        auto size = nums.size();
        vector<int> res(size, -1);

        stack<int> st;
        int i;

        for (auto j = 0; j < (size * 2); ++j) {
            i = (j % size);

            while (!st.empty() && nums[st.top()] < nums[i]) {
                if (res[st.top()] == -1) {
                    res[st.top()] = nums[i];
                }
                st.pop();
            }
            st.push(i);
        }

        return res;
    }
};