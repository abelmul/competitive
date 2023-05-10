class Solution
{
 public:
    int singleNumber(vector<int>& nums)
    {
        int res = 0;
        int count = 0;

        for (auto i = 0; i < 32; ++i) {
            count = 0;
            for (auto n : nums) {
                if (n & (1 << i))
                    ++count;
            }
            if (count % 3 == 1) {
                res = res | (1 << i);
            }
        }

        return res;
    }
};
