class Solution:
    def countGoodNumbers(self, n: int) -> int:
        """
        we can find the number of good numbers
        by multiplying
        pow(4, n//2) * pow(5, n//2) = pow(20, n//2)
        and multiply by 5 if n is odd
        """

        def pow(k, n):
            if n == 0:
                return 1

            half = pow(k, n // 2)

            return ((k if n % 2 == 1 else 1) * half * half) % 1_000_000_007

        return (
            (5 if n % 2 == 1 else 1) * pow(4, n // 2) * pow(5, n // 2)
        ) % 1_000_000_007
