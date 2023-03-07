class Solution:
    def isPalindrome(self, x: int) -> bool:
        reversed = 0
        y = abs(x)

        while y > 0:
            reversed = reversed * 10 + y % 10
            y //= 10

        return x == reversed
