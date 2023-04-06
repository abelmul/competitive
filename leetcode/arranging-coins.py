class Solution:
    def arrangeCoins(self, n: int) -> int:
        l = 1
        r = n

        # gauss formula for sum of artimetic series that is increasing by 1
        gauss_sum = lambda n: ((n * (n + 1)) // 2)

        while l < r:
            m = (l + r) // 2

            if gauss_sum(m) <= n:
                l = m + 1
            else:
                r = m

        return l - (gauss_sum(l) != n)
