class Solution
{
 public:
    int hammingDistance(int x, int y)
    {
        int res = 0;

        auto r = x ^ y;

        // Brian Kernighan's algorithm
        while (r) {
            r = r & (r - 1);
            ++res;
        }

        return res;
    }
};
