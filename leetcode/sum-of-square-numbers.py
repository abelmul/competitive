from math import sqrt


class Solution:
    def judgeSquareSum(self, c: int) -> bool:

        l = 0
        r = int(sqrt(c))

        while l <= r:
            s = l**2 + r**2

            if s == c:
                print(l, r)
                return True
            elif s < c:
                l += 1
            else:
                r -= 1

        return False
