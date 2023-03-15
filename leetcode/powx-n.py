class Solution:
    def myPow(self, x: float, n: int) -> float:
        if n == 0:
            return 1

        if n == 1 or x == 0 or x == 1:
            return x

        negative = False
        if n < 0:
            negative = True
            n = abs(n)

        ans = 1
        if n % 2 == 1:
            ans = x
            n -= 1

        half = self.myPow(x, n // 2)
        ans = ans * half * half

        return 1 / ans if negative else ans
