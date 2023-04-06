class Solution:
    def findNthDigit(self, n: int) -> int:
        """
        there is
        1 char in range 1-9
        2 char in range 10-99
        3 char in range 100-999
        4 char in range 1000-9999
        n char in range 10^(n-1) - 10^n-1
        """

        def getCharsInSequence(n: int) -> int:
            p = 10  # upper bound for 2^31-1

            res = 0

            while n > 0:
                lower_bound = 10 ** (p - 1)
                if n >= lower_bound:
                    res += (n - lower_bound + 1) * p
                    n = lower_bound - 1

                p -= 1

            return res

        l = 0
        r = 252326712  # upper bound for 2^31-1

        while l < r:
            m = (l + r) // 2

            if getCharsInSequence(m) < n:
                l = m + 1
            else:
                r = m

        chars = getCharsInSequence(l)

        return (l // (10 ** (chars - n))) % 10
