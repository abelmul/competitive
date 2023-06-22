class Solution
{
 public:
    int minFlips(int a, int b, int c)
    {
        int res = 0;

        for (auto i = 0; i < 32; ++i) {
            if (((c >> i) & 1) == 1) {
                if ((((a | b) >> i) & 1) == 0) {
                    ++res;
                }
            } else {
                if (((a >> i) & 1) == 1) {
                    ++res;
                }
                if (((b >> i) & 1) == 1) {
                    ++res;
                }
            }
        }

        return res;
    }
};
