class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int mask = 1, first = 0;
        int allxor = 0;

        for(auto n : nums) {
            allxor ^= n;
        }

        while(! (allxor & mask)) mask <<=1;

        // mask = allxor & (-allxor); // find rightmost bit

        for(auto n : nums) {
            if (mask & n) {
                first ^= n;
            }
        }
        return {first, allxor ^ first};
    }
};